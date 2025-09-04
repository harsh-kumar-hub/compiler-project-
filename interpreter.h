#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "ast.h"
#include "symbol_table.h"

// Function table structure
typedef struct {
    char** names;
    ASTNode** nodes;
    int count;
    int capacity;
} FunctionTable;

// Function declarations
void interpret_program(ASTNode* root);
void execute_statement(ASTNode* node, SymbolTable** table);
Symbol* evaluate_expression(ASTNode* node, SymbolTable* table);

// Function table operations
FunctionTable* create_function_table(void);
void add_function(FunctionTable* table, const char* name, ASTNode* node);
ASTNode* get_function(FunctionTable* table, const char* name);
void free_function_table(FunctionTable* table);

#endif
