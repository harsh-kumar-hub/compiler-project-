#include "symbol_table.h"

SymbolTable* create_symbol_table(void) {
    return NULL;  // Empty table is represented by NULL
}

void free_symbol_table(SymbolTable* table) {
    while (table != NULL) {
        SymbolTable* next = table->next;
        free(table->name);
        free_symbol(table->symbol);
        free(table);
        table = next;
    }
}

Symbol* lookup_symbol(SymbolTable* table, const char* name) {
    while (table != NULL) {
        if (strcmp(table->name, name) == 0) {
            return table->symbol;
        }
        table = table->next;
    }
    return NULL;
}

void insert_symbol(SymbolTable** table, const char* name, Symbol* symbol) {
    // First check if symbol already exists
    SymbolTable* current = *table;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            // Replace the existing symbol
            free_symbol(current->symbol);
            current->symbol = symbol;
            return;
        }
        current = current->next;
    }

    // If not found, create new entry
    SymbolTable* new_entry = (SymbolTable*)malloc(sizeof(SymbolTable));
    new_entry->name = strdup(name);
    new_entry->symbol = symbol;
    new_entry->next = *table;
    *table = new_entry;
}

void remove_symbol(SymbolTable* table, const char* name) {
    SymbolTable* prev = NULL;
    SymbolTable* current = table;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                table = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->name);
            free_symbol(current->symbol);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

Symbol* create_int_symbol(int value) {
    Symbol* symbol = (Symbol*)malloc(sizeof(Symbol));
    symbol->type = TYPE_INT;
    symbol->value.int_val = value;
    symbol->array_size = 0;
    return symbol;
}

Symbol* create_string_symbol(const char* value) {
    Symbol* symbol = (Symbol*)malloc(sizeof(Symbol));
    symbol->type = TYPE_STRING;
    symbol->value.string_val = strdup(value);
    symbol->array_size = 0;
    return symbol;
}

Symbol* create_bool_symbol(int value) {
    Symbol* symbol = (Symbol*)malloc(sizeof(Symbol));
    symbol->type = TYPE_BOOL;
    symbol->value.bool_val = value;
    symbol->array_size = 0;
    return symbol;
}

Symbol* create_int_array_symbol(int size) {
    Symbol* symbol = (Symbol*)malloc(sizeof(Symbol));
    symbol->type = TYPE_INT_ARRAY;
    symbol->value.int_array = (int*)calloc(size, sizeof(int));
    symbol->array_size = size;
    return symbol;
}

Symbol* create_string_array_symbol(int size) {
    Symbol* symbol = (Symbol*)malloc(sizeof(Symbol));
    symbol->type = TYPE_STRING_ARRAY;
    symbol->value.string_array = (char**)calloc(size, sizeof(char*));
    symbol->array_size = size;
    return symbol;
}

void free_symbol(Symbol* symbol) {
    if (symbol == NULL) return;

    switch (symbol->type) {
        case TYPE_STRING:
            if (symbol->value.string_val) {
                free(symbol->value.string_val);
            }
            break;
        case TYPE_INT_ARRAY:
            if (symbol->value.int_array) {
                free(symbol->value.int_array);
            }
            break;
        case TYPE_STRING_ARRAY:
            if (symbol->value.string_array) {
                for (int i = 0; i < symbol->array_size; i++) {
                    if (symbol->value.string_array[i]) {
                        free(symbol->value.string_array[i]);
                    }
                }
                free(symbol->value.string_array);
            }
            break;
        default:
            break;
    }
    free(symbol);
}
