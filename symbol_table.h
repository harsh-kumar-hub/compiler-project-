#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    TYPE_INT,
    TYPE_STRING,
    TYPE_BOOL,
    TYPE_VOID,
    TYPE_INT_ARRAY,
    TYPE_STRING_ARRAY
} SymbolType;

typedef struct Symbol {
    SymbolType type;
    union {
        int int_val;
        char* string_val;
        int bool_val;
        int* int_array;
        char** string_array;
    } value;
    int array_size;
} Symbol;

typedef struct SymbolTable {
    char* name;
    Symbol* symbol;
    struct SymbolTable* next;
} SymbolTable;

// Symbol table operations
SymbolTable* create_symbol_table(void);
void free_symbol_table(SymbolTable* table);
Symbol* lookup_symbol(SymbolTable* table, const char* name);
void insert_symbol(SymbolTable** table, const char* name, Symbol* symbol);
void remove_symbol(SymbolTable* table, const char* name);

// Symbol creation helpers
Symbol* create_int_symbol(int value);
Symbol* create_string_symbol(const char* value);
Symbol* create_bool_symbol(int value);
Symbol* create_int_array_symbol(int size);
Symbol* create_string_array_symbol(int size);
void free_symbol(Symbol* symbol);

#endif
