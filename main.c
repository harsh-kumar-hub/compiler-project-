#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "ast.h"
#include "interpreter.h"

#define MAX_BUFFER 10000

// Declare external variables and functions from flex/bison
extern FILE* yyin;
extern int yyparse(void);
extern void yy_scan_string(const char* str);
extern void yyrestart(FILE* input_file);
extern ASTNode* root;

void print_usage(char* program_name) {
    printf("Usage: %s [input_file]\n", program_name);
    printf("If no input file is provided, starts in interactive mode.\n");
}

char* get_input() {
    char* buffer = (char*)malloc(MAX_BUFFER);
    buffer[0] = '\0';
    char* line;
    
    printf("\nMiniC Interactive Mode\n");
    printf("Enter your code (press Ctrl+D on an empty line to execute):\n");
    
    while ((line = readline("> ")) != NULL) {
        if (strlen(line) > 0) {
            add_history(line);  // Add to history for arrow key access
            strcat(buffer, line);
            strcat(buffer, "\n");
        } else {
            free(line);
            break;  // Empty line, break the loop
        }
        free(line);
    }
    
    return buffer;
}

int run_file(const char* filename) {
    FILE* input_file = fopen(filename, "r");
    if (!input_file) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }

    yyin = input_file;
    printf("Parsing file '%s'...\n", filename);
    int parse_result = yyparse();
    fclose(input_file);

    if (parse_result != 0) {
        printf("Parsing failed!\n");
        return 1;
    }

    printf("Parsing successful!\n");
    printf("Executing program...\n");
    interpret_program(root);
    root = NULL;

    return 0;
}

int run_interactive() {
    printf("Welcome to MiniC Interactive Interpreter!\n");
    printf("Type your code and press Ctrl+D to execute.\n");

    while (1) {
        char* input = get_input();
        if (!input || strlen(input) == 0) {
            free(input);
            break;
        }

        if (strcmp(input, "exit\n") == 0) {
            free(input);
            break;
        }

        yy_scan_string(input);
        if (yyparse() == 0 && root) {
            interpret_program(root);
            root = NULL;
        }
        yyrestart(stdin);
        free(input);
        printf("\n");  // Add a newline between executions
    }

    return 0;
}

int main(int argc, char** argv) {
    if (argc > 2) {
        print_usage(argv[0]);
        return 1;
    }

    if (argc == 2) {
        return run_file(argv[1]);
    } else {
        return run_interactive();
    }
}
