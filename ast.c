#include "ast.h"

ASTNode* create_node() {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    return node;
}

ASTNode* create_number_node(int value) {
    ASTNode* node = create_node();
    node->type = NODE_NUMBER;
    node->data.number_value = value;
    return node;
}

ASTNode* create_string_node(char* value) {
    ASTNode* node = create_node();
    node->type = NODE_STRING;
    node->data.string_value = strdup(value);
    return node;
}

ASTNode* create_identifier_node(char* name) {
    ASTNode* node = create_node();
    node->type = NODE_IDENTIFIER;
    node->data.string_value = strdup(name);
    return node;
}

ASTNode* create_binary_op_node(char* op, ASTNode* left, ASTNode* right) {
    ASTNode* node = create_node();
    node->type = NODE_BINARY_OP;
    node->data.binary_op.op = strdup(op);
    node->data.binary_op.left = left;
    node->data.binary_op.right = right;
    return node;
}

ASTNode* create_declaration_node(ASTNode* type, char* name) {
    ASTNode* node = create_node();
    node->type = NODE_DECLARATION;
    node->data.declaration.var_type = type;
    node->data.declaration.var_name = strdup(name);
    return node;
}

ASTNode* create_assignment_node(char* name, ASTNode* value) {
    ASTNode* node = create_node();
    node->type = NODE_ASSIGNMENT;
    node->data.assignment.var_name = strdup(name);
    node->data.assignment.value = value;
    return node;
}

ASTNode* create_if_node(ASTNode* condition, ASTNode* true_block, ASTNode* false_block) {
    ASTNode* node = create_node();
    node->type = NODE_IF;
    node->data.if_stmt.condition = condition;
    node->data.if_stmt.true_block = true_block;
    node->data.if_stmt.false_block = false_block;
    return node;
}

ASTNode* create_while_node(ASTNode* condition, ASTNode* body) {
    ASTNode* node = create_node();
    node->type = NODE_WHILE;
    node->data.while_stmt.condition = condition;
    node->data.while_stmt.body = body;
    return node;
}

ASTNode* create_print_node(ASTNode* expression) {
    ASTNode* node = create_node();
    node->type = NODE_PRINT;
    node->data.print_stmt.expression = expression;
    return node;
}

ASTNode* create_read_node(char* var_name) {
    ASTNode* node = create_node();
    node->type = NODE_READ;
    node->data.read_stmt.var_name = strdup(var_name);
    return node;
}

ASTNode* create_return_node(ASTNode* value) {
    ASTNode* node = create_node();
    node->type = NODE_RETURN;
    node->data.return_stmt.value = value;
    return node;
}

ASTNode* create_statement_list(ASTNode* statement, ASTNode* next) {
    ASTNode* node = create_node();
    node->type = NODE_STATEMENT_LIST;
    node->data.stmt_list.statement = statement;
    node->data.stmt_list.next = next;
    return node;
}

ASTNode* create_for_node(ASTNode* init, ASTNode* condition, ASTNode* update, ASTNode* body) {
    ASTNode* node = create_node();
    node->type = NODE_FOR;
    node->data.for_stmt.init = init;
    node->data.for_stmt.condition = condition;
    node->data.for_stmt.update = update;
    node->data.for_stmt.body = body;
    return node;
}

ASTNode* create_do_while_node(ASTNode* body, ASTNode* condition) {
    ASTNode* node = create_node();
    node->type = NODE_DO_WHILE;
    node->data.while_stmt.body = body;
    node->data.while_stmt.condition = condition;
    return node;
}

ASTNode* create_break_node(void) {
    ASTNode* node = create_node();
    node->type = NODE_BREAK;
    return node;
}

ASTNode* create_continue_node(void) {
    ASTNode* node = create_node();
    node->type = NODE_CONTINUE;
    return node;
}

ASTNode* create_function_node(ASTNode* return_type, char* name, ASTNode* params, ASTNode* body) {
    ASTNode* node = create_node();
    node->type = NODE_FUNCTION;
    node->data.function.return_type = return_type;
    node->data.function.name = strdup(name);
    node->data.function.params = params;
    node->data.function.body = body;
    return node;
}

ASTNode* create_type_node(char* type_name) {
    ASTNode* node = create_node();
    node->type = NODE_TYPE;
    node->data.type.type_name = strdup(type_name);
    return node;
}

ASTNode* create_param_list(ASTNode* param, ASTNode* next) {
    ASTNode* node = create_node();
    node->type = NODE_PARAM_LIST;
    node->data.param_list.param = param;
    node->data.param_list.next = next;
    return node;
}

ASTNode* create_param_node(ASTNode* type, char* name) {
    ASTNode* node = create_node();
    node->type = NODE_PARAM;
    node->data.param.var_type = type;
    node->data.param.var_name = strdup(name);
    return node;
}

ASTNode* create_unary_op_node(char* op, ASTNode* operand) {
    ASTNode* node = create_node();
    node->type = NODE_UNARY_OP;
    node->data.unary_op.op = strdup(op);
    node->data.unary_op.operand = operand;
    return node;
}

ASTNode* create_array_declaration_node(ASTNode* type, char* name, ASTNode* size) {
    ASTNode* node = create_node();
    node->type = NODE_ARRAY_DECLARATION;
    node->data.array_declaration.var_type = type;
    node->data.array_declaration.var_name = strdup(name);
    node->data.array_declaration.size = size;
    return node;
}

ASTNode* create_array_assignment_node(ASTNode* array_access, ASTNode* value) {
    ASTNode* node = create_node();
    node->type = NODE_ARRAY_ASSIGNMENT;
    node->data.array_assignment.array_access = array_access;
    node->data.array_assignment.value = value;
    return node;
}

ASTNode* create_compound_assignment_node(char* name, char* op, ASTNode* value) {
    ASTNode* node = create_node();
    node->type = NODE_COMPOUND_ASSIGNMENT;
    node->data.compound_assignment.var_name = strdup(name);
    node->data.compound_assignment.op = strdup(op);
    node->data.compound_assignment.value = value;
    return node;
}

ASTNode* create_array_access_node(char* array_name, ASTNode* index) {
    ASTNode* node = create_node();
    node->type = NODE_ARRAY_ACCESS;
    node->data.array_access.array_name = strdup(array_name);
    node->data.array_access.index = index;
    return node;
}

ASTNode* create_bool_node(int value) {
    ASTNode* node = create_node();
    node->type = NODE_BOOL;
    node->data.bool_value = value;
    return node;
}

ASTNode* create_function_call_node(char* name, ASTNode* args) {
    ASTNode* node = create_node();
    node->type = NODE_FUNCTION_CALL;
    node->data.function_call.name = strdup(name);
    node->data.function_call.args = args;
    return node;
}

ASTNode* create_arg_list(ASTNode* arg, ASTNode* next) {
    ASTNode* node = create_node();
    node->type = NODE_ARG_LIST;
    node->data.arg_list.arg = arg;
    node->data.arg_list.next = next;
    return node;
}

ASTNode* create_switch_node(ASTNode* expression, ASTNode* cases) {
    ASTNode* node = create_node();
    node->type = NODE_SWITCH;
    node->data.switch_stmt.expression = expression;
    node->data.switch_stmt.cases = cases;
    return node;
}

ASTNode* create_case_node(ASTNode* value, ASTNode* body) {
    ASTNode* node = create_node();
    node->type = NODE_CASE;
    node->data.case_stmt.value = value;
    node->data.case_stmt.body = body;
    node->data.case_stmt.next = NULL;
    return node;
}

ASTNode* create_case_list(ASTNode* case_stmt, ASTNode* next) {
    case_stmt->data.case_stmt.next = next;
    return case_stmt;
}

ASTNode* create_default_node(ASTNode* body) {
    ASTNode* node = create_node();
    node->type = NODE_DEFAULT;
    node->data.default_stmt.body = body;
    return node;
}

ASTNode* create_statement_list_node(ASTNode* statement, ASTNode* next) {
    ASTNode* node = create_node();
    node->type = NODE_STATEMENT_LIST;
    node->data.stmt_list.statement = statement;
    node->data.stmt_list.next = next;
    return node;
}

void free_ast(ASTNode* node) {
    if (!node) return;

    switch (node->type) {
        case NODE_STRING:
        case NODE_IDENTIFIER:
            if (node->data.string_value) {
                free(node->data.string_value);
            }
            break;
        case NODE_BINARY_OP:
            if (node->data.binary_op.op) {
                free(node->data.binary_op.op);
            }
            free_ast(node->data.binary_op.left);
            free_ast(node->data.binary_op.right);
            break;
        case NODE_UNARY_OP:
            if (node->data.unary_op.op) {
                free(node->data.unary_op.op);
            }
            free_ast(node->data.unary_op.operand);
            break;
        case NODE_DECLARATION:
            free_ast(node->data.declaration.var_type);
            if (node->data.declaration.var_name) {
                free(node->data.declaration.var_name);
            }
            break;
        case NODE_ARRAY_DECLARATION:
            free_ast(node->data.array_declaration.var_type);
            if (node->data.array_declaration.var_name) {
                free(node->data.array_declaration.var_name);
            }
            free_ast(node->data.array_declaration.size);
            break;
        case NODE_ASSIGNMENT:
            if (node->data.assignment.var_name) {
                free(node->data.assignment.var_name);
            }
            free_ast(node->data.assignment.value);
            break;
        case NODE_ARRAY_ASSIGNMENT:
            free_ast(node->data.array_assignment.array_access);
            free_ast(node->data.array_assignment.value);
            break;
        case NODE_COMPOUND_ASSIGNMENT:
            if (node->data.compound_assignment.var_name) {
                free(node->data.compound_assignment.var_name);
            }
            if (node->data.compound_assignment.op) {
                free(node->data.compound_assignment.op);
            }
            free_ast(node->data.compound_assignment.value);
            break;
        case NODE_IF:
            free_ast(node->data.if_stmt.condition);
            free_ast(node->data.if_stmt.true_block);
            free_ast(node->data.if_stmt.false_block);
            break;
        case NODE_WHILE:
        case NODE_DO_WHILE:
            free_ast(node->data.while_stmt.condition);
            free_ast(node->data.while_stmt.body);
            break;
        case NODE_FOR:
            free_ast(node->data.for_stmt.init);
            free_ast(node->data.for_stmt.condition);
            free_ast(node->data.for_stmt.update);
            free_ast(node->data.for_stmt.body);
            break;
        case NODE_SWITCH:
            free_ast(node->data.switch_stmt.expression);
            free_ast(node->data.switch_stmt.cases);
            break;
        case NODE_CASE:
            free_ast(node->data.case_stmt.value);
            free_ast(node->data.case_stmt.body);
            free_ast(node->data.case_stmt.next);
            break;
        case NODE_DEFAULT:
            free_ast(node->data.default_stmt.body);
            break;
        case NODE_PRINT:
            free_ast(node->data.print_stmt.expression);
            break;
        case NODE_READ:
            if (node->data.read_stmt.var_name) {
                free(node->data.read_stmt.var_name);
            }
            break;
        case NODE_STATEMENT_LIST:
            free_ast(node->data.stmt_list.statement);
            free_ast(node->data.stmt_list.next);
            break;
        case NODE_ARRAY_ACCESS:
            if (node->data.array_access.array_name) {
                free(node->data.array_access.array_name);
            }
            free_ast(node->data.array_access.index);
            break;
        case NODE_FUNCTION:
            free_ast(node->data.function.return_type);
            if (node->data.function.name) {
                free(node->data.function.name);
            }
            free_ast(node->data.function.params);
            free_ast(node->data.function.body);
            break;
        case NODE_FUNCTION_CALL:
            if (node->data.function_call.name) {
                free(node->data.function_call.name);
            }
            free_ast(node->data.function_call.args);
            break;
        case NODE_PARAM_LIST:
            free_ast(node->data.param_list.param);
            free_ast(node->data.param_list.next);
            break;
        case NODE_PARAM:
            free_ast(node->data.param.var_type);
            if (node->data.param.var_name) {
                free(node->data.param.var_name);
            }
            break;
        case NODE_ARG_LIST:
            free_ast(node->data.arg_list.arg);
            free_ast(node->data.arg_list.next);
            break;
        case NODE_RETURN:
            free_ast(node->data.return_stmt.value);
            break;
        case NODE_TYPE:
            if (node->data.type.type_name) {
                free(node->data.type.type_name);
            }
            break;
        case NODE_BREAK:
        case NODE_CONTINUE:
        case NODE_NUMBER:
        case NODE_BOOL:
            // These nodes don't have any allocated memory to free
            break;
        default:
            break;
    }
    free(node);
}
