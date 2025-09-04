#include "interpreter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global function table
static FunctionTable* function_table = NULL;

FunctionTable* create_function_table(void) {
    FunctionTable* table = (FunctionTable*)malloc(sizeof(FunctionTable));
    table->capacity = 10;
    table->count = 0;
    table->names = (char**)malloc(sizeof(char*) * table->capacity);
    table->nodes = (ASTNode**)malloc(sizeof(ASTNode*) * table->capacity);
    return table;
}

void add_function(FunctionTable* table, const char* name, ASTNode* node) {
    if (table->count == table->capacity) {
        table->capacity *= 2;
        table->names = (char**)realloc(table->names, sizeof(char*) * table->capacity);
        table->nodes = (ASTNode**)realloc(table->nodes, sizeof(ASTNode*) * table->capacity);
    }
    table->names[table->count] = strdup(name);
    table->nodes[table->count] = node;  // Just store the pointer, don't copy
    table->count++;
}

ASTNode* get_function(FunctionTable* table, const char* name) {
    for (int i = 0; i < table->count; i++) {
        if (strcmp(table->names[i], name) == 0) {
            return table->nodes[i];
        }
    }
    return NULL;
}

void free_function_table(FunctionTable* table) {
    if (!table) return;
    for (int i = 0; i < table->count; i++) {
        free(table->names[i]);
        // Don't free the nodes, they're part of the AST
    }
    free(table->names);
    free(table->nodes);
    free(table);
}

void interpret_program(ASTNode* root) {
    if (!root) return;
    
    // Create global symbol table
    SymbolTable* global_table = create_symbol_table();
    
    // Create function table if not exists
    if (!function_table) {
        function_table = create_function_table();
    }
    
    // If root is a list of function declarations, add all to function table
    if (root->type == NODE_STATEMENT_LIST) {
        ASTNode* curr = root;
        while (curr) {
            if (curr->data.stmt_list.statement && curr->data.stmt_list.statement->type == NODE_FUNCTION) {
                add_function(function_table, curr->data.stmt_list.statement->data.function.name, curr->data.stmt_list.statement);
            }
            curr = curr->data.stmt_list.next;
        }
        // After all functions are added, execute main if present
        ASTNode* main_func = get_function(function_table, "main");
        if (main_func) {
            execute_statement(main_func->data.function.body, &global_table);
        } else {
            fprintf(stderr, "Error: No main function found.\n");
        }
    } else if (root->type == NODE_FUNCTION) {
        add_function(function_table, root->data.function.name, root);
        if (strcmp(root->data.function.name, "main") == 0) {
            execute_statement(root->data.function.body, &global_table);
        }
    } else {
        // Otherwise execute as normal statement list
        execute_statement(root, &global_table);
    }
    
    // Cleanup
    free_symbol_table(global_table);
    if (function_table) {
        free_function_table(function_table);
        function_table = NULL;
    }
    free_ast(root);
}

Symbol* evaluate_expression(ASTNode* node, SymbolTable* table) {
    if (!node) return NULL;

    Symbol* result = NULL;
    Symbol* left = NULL;
    Symbol* right = NULL;
    Symbol* array_index = NULL;

    switch (node->type) {
        case NODE_NUMBER:
            return create_int_symbol(node->data.number_value);
        
        case NODE_STRING:
            return create_string_symbol(node->data.string_value);
        
        case NODE_BOOL:
            return create_bool_symbol(node->data.bool_value);
        
        case NODE_IDENTIFIER: {
            Symbol* found = lookup_symbol(table, node->data.string_value);
            if (found) {
                // Create a new symbol with the same values
                switch (found->type) {
                    case TYPE_INT:
                        return create_int_symbol(found->value.int_val);
                    case TYPE_STRING:
                        return create_string_symbol(found->value.string_val);
                    case TYPE_BOOL:
                        return create_bool_symbol(found->value.bool_val);
                    default:
                        return NULL;
                }
            }
            return NULL;
        }
        
        case NODE_ARRAY_ACCESS: {
            Symbol* array = lookup_symbol(table, node->data.array_access.array_name);
            array_index = evaluate_expression(node->data.array_access.index, table);
            
            if (array && array_index && array_index->type == TYPE_INT) {
                int idx = array_index->value.int_val;
                if (idx >= 0 && idx < array->array_size) {
                    if (array->type == TYPE_INT_ARRAY) {
                        result = create_int_symbol(array->value.int_array[idx]);
                    } else if (array->type == TYPE_STRING_ARRAY && array->value.string_array[idx]) {
                        result = create_string_symbol(array->value.string_array[idx]);
                    }
                }
            }
            free_symbol(array_index);
            return result;
        }
        
        case NODE_UNARY_OP:
            result = evaluate_expression(node->data.unary_op.operand, table);
            if (result) {
                if (strcmp(node->data.unary_op.op, "!") == 0) {
                    if (result->type == TYPE_BOOL) {
                        int val = !result->value.bool_val;
                        free_symbol(result);
                        return create_bool_symbol(val);
                    } else if (result->type == TYPE_INT) {
                        int val = !result->value.int_val;
                        free_symbol(result);
                        return create_bool_symbol(val);
                    }
                }
                // Handle other unary operators here
                free_symbol(result);
            }
            return NULL;
        
        case NODE_BINARY_OP:
            left = evaluate_expression(node->data.binary_op.left, table);
            right = evaluate_expression(node->data.binary_op.right, table);
            
            if (!left || !right) {
                free_symbol(left);
                free_symbol(right);
                return NULL;
            }
            
            // Handle boolean operations
            if (strcmp(node->data.binary_op.op, "&&") == 0) {
                int left_val = (left->type == TYPE_BOOL) ? left->value.bool_val : 
                              (left->type == TYPE_INT) ? (left->value.int_val != 0) : 0;
                int right_val = (right->type == TYPE_BOOL) ? right->value.bool_val :
                               (right->type == TYPE_INT) ? (right->value.int_val != 0) : 0;
                free_symbol(left);
                free_symbol(right);
                return create_bool_symbol(left_val && right_val);
            }
            
            if (strcmp(node->data.binary_op.op, "||") == 0) {
                int left_val = (left->type == TYPE_BOOL) ? left->value.bool_val :
                              (left->type == TYPE_INT) ? (left->value.int_val != 0) : 0;
                int right_val = (right->type == TYPE_BOOL) ? right->value.bool_val :
                               (right->type == TYPE_INT) ? (right->value.int_val != 0) : 0;
                free_symbol(left);
                free_symbol(right);
                return create_bool_symbol(left_val || right_val);
            }
            
            if (left->type == TYPE_INT && right->type == TYPE_INT) {
                int left_val = left->value.int_val;
                int right_val = right->value.int_val;
                free_symbol(left);
                free_symbol(right);
                
                if (strcmp(node->data.binary_op.op, "+") == 0) {
                    return create_int_symbol(left_val + right_val);
                } else if (strcmp(node->data.binary_op.op, "-") == 0) {
                    return create_int_symbol(left_val - right_val);
                } else if (strcmp(node->data.binary_op.op, "*") == 0) {
                    return create_int_symbol(left_val * right_val);
                } else if (strcmp(node->data.binary_op.op, "/") == 0) {
                    if (right_val == 0) {
                        fprintf(stderr, "Error: Division by zero\n");
                        return NULL;
                    }
                    return create_int_symbol(left_val / right_val);
                } else if (strcmp(node->data.binary_op.op, "%") == 0) {
                    if (right_val == 0) {
                        fprintf(stderr, "Error: Modulo by zero\n");
                        return NULL;
                    }
                    return create_int_symbol(left_val % right_val);
                } else if (strcmp(node->data.binary_op.op, "<") == 0) {
                    return create_bool_symbol(left_val < right_val);
                } else if (strcmp(node->data.binary_op.op, ">") == 0) {
                    return create_bool_symbol(left_val > right_val);
                } else if (strcmp(node->data.binary_op.op, "<=") == 0) {
                    return create_bool_symbol(left_val <= right_val);
                } else if (strcmp(node->data.binary_op.op, ">=") == 0) {
                    return create_bool_symbol(left_val >= right_val);
                } else if (strcmp(node->data.binary_op.op, "==") == 0) {
                    return create_bool_symbol(left_val == right_val);
                } else if (strcmp(node->data.binary_op.op, "!=") == 0) {
                    return create_bool_symbol(left_val != right_val);
                }
            } else if (left->type == TYPE_STRING && right->type == TYPE_STRING) {
                char* left_str = strdup(left->value.string_val);
                char* right_str = strdup(right->value.string_val);
                free_symbol(left);
                free_symbol(right);
                
                if (strcmp(node->data.binary_op.op, "+") == 0) {
                    // String concatenation
                    size_t len = strlen(left_str) + strlen(right_str) + 1;
                    char* concat = malloc(len);
                    strcpy(concat, left_str);
                    strcat(concat, right_str);
                    Symbol* result = create_string_symbol(concat);
                    free(concat);
                    free(left_str);
                    free(right_str);
                    return result;
                } else if (strcmp(node->data.binary_op.op, "==") == 0) {
                    int val = strcmp(left_str, right_str) == 0;
                    free(left_str);
                    free(right_str);
                    return create_bool_symbol(val);
                } else if (strcmp(node->data.binary_op.op, "!=") == 0) {
                    int val = strcmp(left_str, right_str) != 0;
                    free(left_str);
                    free(right_str);
                    return create_bool_symbol(val);
                }
                free(left_str);
                free(right_str);
            }
            
            free_symbol(left);
            free_symbol(right);
            return NULL;
            
        default:
            return NULL;
    }
}

char* interpret_escapes(const char* src) {
    if (!src) return NULL;
    size_t len = strlen(src);
    char* dest = malloc(len + 1); // max size needed
    size_t j = 0;
    for (size_t i = 0; i < len; ++i) {
        if (src[i] == '\\' && i + 1 < len) {
            i++;
            switch (src[i]) {
                case 'n': dest[j++] = '\n'; break;
                case 't': dest[j++] = '\t'; break;
                case 'r': dest[j++] = '\r'; break;
                case '\\': dest[j++] = '\\'; break;
                case '"': dest[j++] = '"'; break;
                case '\'': dest[j++] = '\''; break;
                default: dest[j++] = src[i]; break;
            }
        } else {
            dest[j++] = src[i];
        }
    }
    dest[j] = '\0';
    return dest;
}

void execute_statement(ASTNode* node, SymbolTable** table) {
    if (!node) return;

    Symbol* result;
    Symbol* array_index;
    
    switch (node->type) {
        case NODE_DECLARATION:
            if (node->data.declaration.var_type->type == NODE_TYPE) {
                const char* type_name = node->data.declaration.var_type->data.type.type_name;
                Symbol* symbol = NULL;
                
                if (strcmp(type_name, "int") == 0) {
                    symbol = create_int_symbol(0);
                } else if (strcmp(type_name, "string") == 0) {
                    symbol = create_string_symbol("");
                } else if (strcmp(type_name, "bool") == 0) {
                    symbol = create_bool_symbol(0);
                }
                
                if (symbol) {
                    insert_symbol(table, node->data.declaration.var_name, symbol);
                }
            }
            break;
            
        case NODE_ARRAY_DECLARATION:
            if (node->data.array_declaration.var_type->type == NODE_TYPE) {
                const char* type_name = node->data.array_declaration.var_type->data.type.type_name;
                Symbol* size_expr = evaluate_expression(node->data.array_declaration.size, *table);
                
                if (size_expr && size_expr->type == TYPE_INT) {
                    Symbol* array = NULL;
                    if (strcmp(type_name, "int") == 0) {
                        array = create_int_array_symbol(size_expr->value.int_val);
                    } else if (strcmp(type_name, "string") == 0) {
                        array = create_string_array_symbol(size_expr->value.int_val);
                    }
                    
                    if (array) {
                        insert_symbol(table, node->data.array_declaration.var_name, array);
                    }
                }
                free_symbol(size_expr);
            }
            break;
            
        case NODE_ASSIGNMENT:
            result = evaluate_expression(node->data.assignment.value, *table);
            if (result) {
                insert_symbol(table, node->data.assignment.var_name, result);
            }
            break;
            
        case NODE_ARRAY_ASSIGNMENT:
            array_index = evaluate_expression(node->data.array_assignment.array_access->data.array_access.index, *table);
            if (array_index && array_index->type == TYPE_INT) {
                Symbol* array = lookup_symbol(*table, node->data.array_assignment.array_access->data.array_access.array_name);
                if (array) {
                    result = evaluate_expression(node->data.array_assignment.value, *table);
                    if (result) {
                        if (array->type == TYPE_INT_ARRAY && result->type == TYPE_INT) {
                            array->value.int_array[array_index->value.int_val] = result->value.int_val;
                        } else if (array->type == TYPE_STRING_ARRAY && result->type == TYPE_STRING) {
                            if (array->value.string_array[array_index->value.int_val]) {
                                free(array->value.string_array[array_index->value.int_val]);
                            }
                            array->value.string_array[array_index->value.int_val] = strdup(result->value.string_val);
                        }
                    }
                    free_symbol(result);
                }
            }
            free_symbol(array_index);
            break;
            
        case NODE_COMPOUND_ASSIGNMENT: {
            Symbol* var = lookup_symbol(*table, node->data.compound_assignment.var_name);
            Symbol* value = evaluate_expression(node->data.compound_assignment.value, *table);
            Symbol* new_value = NULL;
            
            if (var && value && var->type == TYPE_INT && value->type == TYPE_INT) {
                if (strcmp(node->data.compound_assignment.op, "+=") == 0) {
                    new_value = create_int_symbol(var->value.int_val + value->value.int_val);
                } else if (strcmp(node->data.compound_assignment.op, "-=") == 0) {
                    new_value = create_int_symbol(var->value.int_val - value->value.int_val);
                } else if (strcmp(node->data.compound_assignment.op, "*=") == 0) {
                    new_value = create_int_symbol(var->value.int_val * value->value.int_val);
                } else if (strcmp(node->data.compound_assignment.op, "/=") == 0) {
                    if (value->value.int_val != 0) {
                        new_value = create_int_symbol(var->value.int_val / value->value.int_val);
                    }
                } else if (strcmp(node->data.compound_assignment.op, "%=") == 0) {
                    if (value->value.int_val != 0) {
                        new_value = create_int_symbol(var->value.int_val % value->value.int_val);
                    }
                }
                
                if (new_value) {
                    insert_symbol(table, node->data.compound_assignment.var_name, new_value);
                }
            }
            free_symbol(value);
            break;
        }
            
        case NODE_IF:
            result = evaluate_expression(node->data.if_stmt.condition, *table);
            if (result && (result->type == TYPE_BOOL || result->type == TYPE_INT)) {
                int condition_true = (result->type == TYPE_BOOL) ? 
                                   result->value.bool_val : 
                                   (result->value.int_val != 0);
                if (condition_true) {
                    execute_statement(node->data.if_stmt.true_block, table);
                } else if (node->data.if_stmt.false_block) {
                    execute_statement(node->data.if_stmt.false_block, table);
                }
            }
            free_symbol(result);
            break;
            
        case NODE_WHILE:
            while (1) {
                result = evaluate_expression(node->data.while_stmt.condition, *table);
                if (!result || 
                    (result->type == TYPE_BOOL && !result->value.bool_val) ||
                    (result->type == TYPE_INT && result->value.int_val == 0)) {
                    free_symbol(result);
                    break;
                }
                free_symbol(result);
                execute_statement(node->data.while_stmt.body, table);
            }
            break;
            
        case NODE_FOR:
            execute_statement(node->data.for_stmt.init, table);
            while (1) {
                result = evaluate_expression(node->data.for_stmt.condition, *table);
                if (!result || 
                    (result->type == TYPE_BOOL && !result->value.bool_val) ||
                    (result->type == TYPE_INT && result->value.int_val == 0)) {
                    free_symbol(result);
                    break;
                }
                free_symbol(result);
                execute_statement(node->data.for_stmt.body, table);
                execute_statement(node->data.for_stmt.update, table);
            }
            break;
            
        case NODE_DO_WHILE:
            do {
                execute_statement(node->data.while_stmt.body, table);
                result = evaluate_expression(node->data.while_stmt.condition, *table);
                if (!result || 
                    (result->type == TYPE_BOOL && !result->value.bool_val) ||
                    (result->type == TYPE_INT && result->value.int_val == 0)) {
                    free_symbol(result);
                    break;
                }
                free_symbol(result);
            } while (1);
            break;
            
        case NODE_PRINT:
            result = evaluate_expression(node->data.print_stmt.expression, *table);
            if (result) {
                switch (result->type) {
                    case TYPE_INT:
                        printf("%d\n", result->value.int_val);
                        break;
                    case TYPE_STRING: {
                        char* interpreted = interpret_escapes(result->value.string_val);
                        printf("%s\n", interpreted);
                        free(interpreted);
                        break;
                    }
                    case TYPE_BOOL:
                        printf("%s\n", result->value.bool_val ? "true" : "false");
                        break;
                    case TYPE_INT_ARRAY:
                        printf("[");
                        for (int i = 0; i < result->array_size; i++) {
                            printf("%d", result->value.int_array[i]);
                            if (i < result->array_size - 1) printf(", ");
                        }
                        printf("]\n");
                        break;
                    case TYPE_STRING_ARRAY:
                        printf("[");
                        for (int i = 0; i < result->array_size; i++) {
                            printf("\"%s\"", result->value.string_array[i] ? result->value.string_array[i] : "");
                            if (i < result->array_size - 1) printf(", ");
                        }
                        printf("]\n");
                        break;
                    default:
                        fprintf(stderr, "Error: Cannot print this type\n");
                        break;
                }
                free_symbol(result);
            }
            break;
            
        case NODE_READ: {
            char buffer[1024];
            Symbol* var = lookup_symbol(*table, node->data.read_stmt.var_name);
            if (var) {
                printf("INPUT: ");
                fflush(stdout);
                if (fgets(buffer, sizeof(buffer), stdin)) {
                    buffer[strcspn(buffer, "\n")] = 0;  // Remove newline
                    if (var->type == TYPE_INT) {
                        var->value.int_val = atoi(buffer);
                    } else if (var->type == TYPE_STRING) {
                        if (var->value.string_val) free(var->value.string_val);
                        var->value.string_val = strdup(buffer);
                    }
                }
            }
            break;
        }
            
        case NODE_STATEMENT_LIST:
            execute_statement(node->data.stmt_list.statement, table);
            execute_statement(node->data.stmt_list.next, table);
            break;
            
        case NODE_SWITCH: {
            Symbol* switch_val = evaluate_expression(node->data.switch_stmt.expression, *table);
            ASTNode* case_node = node->data.switch_stmt.cases;
            int matched = 0;
            int break_encountered = 0;
            // Find the first matching case or default
            while (case_node) {
                if (case_node->type == NODE_CASE && switch_val && switch_val->type == TYPE_INT) {
                    Symbol* case_val = evaluate_expression(case_node->data.case_stmt.value, *table);
                    if (case_val && case_val->type == TYPE_INT && switch_val->value.int_val == case_val->value.int_val) {
                        matched = 1;
                        free_symbol(case_val);
                        break;
                    }
                    free_symbol(case_val);
                } else if (case_node->type == NODE_DEFAULT) {
                    matched = 2;
                    break;
                }
                case_node = case_node->data.case_stmt.next;
            }
            // If a match was found, execute all bodies from there (fall-through), but stop on break
            if (matched) {
                while (case_node && !break_encountered) {
                    if (case_node->type == NODE_CASE) {
                        break_encountered = execute_statement_with_break(case_node->data.case_stmt.body, table);
                    } else if (case_node->type == NODE_DEFAULT) {
                        break_encountered = execute_statement_with_break(case_node->data.default_stmt.body, table);
                    }
                    case_node = case_node->data.case_stmt.next;
                }
            }
            free_symbol(switch_val);
            break;
        }
        case NODE_BREAK:
            // Special handling: signal break to switch
            return; // just return, do not return 1
            
        default:
            break;
    }
}

int execute_statement_with_break(ASTNode* node, SymbolTable** table) {
    if (!node) return 0;
    if (node->type == NODE_BREAK) {
        return 1;
    } else if (node->type == NODE_STATEMENT_LIST) {
        if (execute_statement_with_break(node->data.stmt_list.statement, table)) return 1;
        if (execute_statement_with_break(node->data.stmt_list.next, table)) return 1;
        return 0;
    } else {
        execute_statement(node, table);
        return 0;
    }
}
