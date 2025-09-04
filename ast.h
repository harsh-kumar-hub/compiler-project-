#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node types for AST
typedef enum {
    NODE_NUMBER,
    NODE_STRING,
    NODE_BOOL,
    NODE_IDENTIFIER,
    NODE_BINARY_OP,
    NODE_UNARY_OP,
    NODE_DECLARATION,
    NODE_ARRAY_DECLARATION,
    NODE_ARRAY_ACCESS,
    NODE_ASSIGNMENT,
    NODE_ARRAY_ASSIGNMENT,
    NODE_COMPOUND_ASSIGNMENT,
    NODE_IF,
    NODE_WHILE,
    NODE_FOR,
    NODE_DO_WHILE,
    NODE_SWITCH,
    NODE_CASE,
    NODE_DEFAULT,
    NODE_BREAK,
    NODE_CONTINUE,
    NODE_PRINT,
    NODE_READ,
    NODE_RETURN,
    NODE_STATEMENT_LIST,
    NODE_FUNCTION,
    NODE_FUNCTION_CALL,
    NODE_PARAM_LIST,
    NODE_PARAM,
    NODE_ARG_LIST,
    NODE_TYPE
} NodeType;

// Forward declaration
typedef struct ASTNode ASTNode;

// Structure for AST node
struct ASTNode {
    NodeType type;
    union {
        int number_value;
        char* string_value;
        int bool_value;
        struct {
            char* op;
            ASTNode* left;
            ASTNode* right;
        } binary_op;
        struct {
            char* op;
            ASTNode* operand;
        } unary_op;
        struct {
            ASTNode* var_type;
            char* var_name;
        } declaration;
        struct {
            ASTNode* var_type;
            char* var_name;
            ASTNode* size;
        } array_declaration;
        struct {
            char* var_name;
            ASTNode* value;
        } assignment;
        struct {
            ASTNode* array_access;
            ASTNode* value;
        } array_assignment;
        struct {
            char* var_name;
            char* op;
            ASTNode* value;
        } compound_assignment;
        struct {
            ASTNode* condition;
            ASTNode* true_block;
            ASTNode* false_block;
        } if_stmt;
        struct {
            ASTNode* condition;
            ASTNode* body;
        } while_stmt;
        struct {
            ASTNode* init;
            ASTNode* condition;
            ASTNode* update;
            ASTNode* body;
        } for_stmt;
        struct {
            ASTNode* expression;
            ASTNode* cases;
        } switch_stmt;
        struct {
            ASTNode* value;
            ASTNode* body;
            ASTNode* next;
        } case_stmt;
        struct {
            ASTNode* body;
        } default_stmt;
        struct {
            ASTNode* expression;
        } print_stmt;
        struct {
            char* var_name;
        } read_stmt;
        struct {
            ASTNode* statement;
            ASTNode* next;
        } stmt_list;
        struct {
            char* array_name;
            ASTNode* index;
        } array_access;
        struct {
            ASTNode* return_type;
            char* name;
            ASTNode* params;
            ASTNode* body;
        } function;
        struct {
            char* name;
            ASTNode* args;
        } function_call;
        struct {
            ASTNode* param;
            ASTNode* next;
        } param_list;
        struct {
            ASTNode* var_type;
            char* var_name;
        } param;
        struct {
            ASTNode* arg;
            ASTNode* next;
        } arg_list;
        struct {
            ASTNode* value;
        } return_stmt;
        struct {
            char* type_name;
        } type;
    } data;
};

// Function declarations for creating AST nodes
ASTNode* create_node(void);
ASTNode* create_number_node(int value);
ASTNode* create_string_node(char* value);
ASTNode* create_bool_node(int value);
ASTNode* create_identifier_node(char* name);
ASTNode* create_binary_op_node(char* op, ASTNode* left, ASTNode* right);
ASTNode* create_unary_op_node(char* op, ASTNode* operand);
ASTNode* create_declaration_node(ASTNode* type, char* name);
ASTNode* create_array_declaration_node(ASTNode* type, char* name, ASTNode* size);
ASTNode* create_array_access_node(char* array_name, ASTNode* index);
ASTNode* create_assignment_node(char* name, ASTNode* value);
ASTNode* create_array_assignment_node(ASTNode* array_access, ASTNode* value);
ASTNode* create_compound_assignment_node(char* name, char* op, ASTNode* value);
ASTNode* create_if_node(ASTNode* condition, ASTNode* true_block, ASTNode* false_block);
ASTNode* create_while_node(ASTNode* condition, ASTNode* body);
ASTNode* create_for_node(ASTNode* init, ASTNode* condition, ASTNode* update, ASTNode* body);
ASTNode* create_do_while_node(ASTNode* body, ASTNode* condition);
ASTNode* create_switch_node(ASTNode* expression, ASTNode* cases);
ASTNode* create_case_node(ASTNode* value, ASTNode* body);
ASTNode* create_case_list(ASTNode* case_stmt, ASTNode* next);
ASTNode* create_default_node(ASTNode* body);
ASTNode* create_break_node(void);
ASTNode* create_continue_node(void);
ASTNode* create_function_node(ASTNode* return_type, char* name, ASTNode* params, ASTNode* body);
ASTNode* create_function_call_node(char* name, ASTNode* args);
ASTNode* create_param_list(ASTNode* param, ASTNode* next);
ASTNode* create_param_node(ASTNode* type, char* name);
ASTNode* create_arg_list(ASTNode* arg, ASTNode* next);
ASTNode* create_type_node(char* type_name);
ASTNode* create_print_node(ASTNode* expression);
ASTNode* create_read_node(char* var_name);
ASTNode* create_return_node(ASTNode* value);
ASTNode* create_statement_list_node(ASTNode* statement, ASTNode* next);

// Function to free AST
void free_ast(ASTNode* node);

#endif
