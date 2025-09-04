%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int yylex();
extern int line_number;
void yyerror(const char *s);

ASTNode* root = NULL;
%}

%union {
    int ival;
    char* sval;
    struct ASTNode* ast;
}

%token <ival> NUMBER
%token <sval> IDENTIFIER STRING_LITERAL
%token IF ELSE WHILE FOR DO BREAK CONTINUE SWITCH CASE DEFAULT
%token PRINT READ INT STRING VOID BOOL TRUE FALSE MAIN RETURN
%token PLUS MINUS MULTIPLY DIVIDE MODULO
%token ASSIGN EQ NEQ LT GT LTE GTE
%token INCREMENT DECREMENT
%token PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token AND OR NOT
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token SEMICOLON COMMA COLON

%type <ast> program statement_list statement expression
%type <ast> declaration assignment if_statement while_statement
%type <ast> for_statement do_while_statement break_statement continue_statement
%type <ast> switch_statement case_list case_statement default_statement
%type <ast> print_statement read_statement return_statement function_declaration
%type <ast> param_list param function_call arg_list type bool_literal
%type <sval> compound_assign

/* Define operator precedence and associativity */
%right ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN MOD_ASSIGN
%left OR
%left AND
%left EQ NEQ
%left LT GT LTE GTE
%left PLUS MINUS
%left MULTIPLY DIVIDE MODULO
%right NOT
%right INCREMENT DECREMENT
%left LBRACKET RBRACKET

%%

program
    : function_declaration                        { root = $1; }
    | program function_declaration                { root = create_statement_list_node($1, $2); }
    ;

function_declaration
    : type MAIN LPAREN RPAREN LBRACE statement_list RBRACE
        { $$ = create_function_node($1, "main", NULL, $6); }
    | type IDENTIFIER LPAREN param_list RPAREN LBRACE statement_list RBRACE
        { $$ = create_function_node($1, $2, $4, $7); }
    | type IDENTIFIER LPAREN RPAREN LBRACE statement_list RBRACE
        { $$ = create_function_node($1, $2, NULL, $6); }
    ;

param_list
    : param                     { $$ = create_param_list($1, NULL); }
    | param COMMA param_list    { $$ = create_param_list($1, $3); }
    ;

param
    : type IDENTIFIER          { $$ = create_param_node($1, $2); }
    ;

type
    : INT       { $$ = create_type_node("int"); }
    | STRING    { $$ = create_type_node("string"); }
    | VOID      { $$ = create_type_node("void"); }
    | BOOL      { $$ = create_type_node("bool"); }
    ;

statement_list
    : statement                    { $$ = create_statement_list_node($1, NULL); }
    | statement statement_list     { $$ = create_statement_list_node($1, $2); }
    ;

statement
    : declaration SEMICOLON        { $$ = $1; }
    | assignment SEMICOLON         { $$ = $1; }
    | if_statement                 { $$ = $1; }
    | while_statement             { $$ = $1; }
    | for_statement               { $$ = $1; }
    | do_while_statement          { $$ = $1; }
    | break_statement SEMICOLON    { $$ = $1; }
    | continue_statement SEMICOLON { $$ = $1; }
    | switch_statement            { $$ = $1; }
    | print_statement SEMICOLON    { $$ = $1; }
    | read_statement SEMICOLON     { $$ = $1; }
    | return_statement SEMICOLON   { $$ = $1; }
    | function_call SEMICOLON      { $$ = $1; }
    | LBRACE statement_list RBRACE { $$ = $2; }
    ;

declaration
    : type IDENTIFIER                                { $$ = create_declaration_node($1, $2); }
    | type IDENTIFIER LBRACKET NUMBER RBRACKET       { $$ = create_array_declaration_node($1, $2, create_number_node($4)); }
    ;

assignment
    : IDENTIFIER ASSIGN expression                   { $$ = create_assignment_node($1, $3); }
    | IDENTIFIER LBRACKET expression RBRACKET ASSIGN expression 
        { $$ = create_array_assignment_node(create_array_access_node($1, $3), $6); }
    | IDENTIFIER compound_assign expression          { $$ = create_compound_assignment_node($1, $2, $3); }
    ;

compound_assign
    : PLUS_ASSIGN    { $$ = "+="; }
    | MINUS_ASSIGN   { $$ = "-="; }
    | MULT_ASSIGN    { $$ = "*="; }
    | DIV_ASSIGN     { $$ = "/="; }
    | MOD_ASSIGN     { $$ = "%="; }
    ;

expression
    : NUMBER                    { $$ = create_number_node($1); }
    | STRING_LITERAL           { $$ = create_string_node($1); }
    | bool_literal             { $$ = $1; }
    | IDENTIFIER               { $$ = create_identifier_node($1); }
    | IDENTIFIER LBRACKET expression RBRACKET { $$ = create_array_access_node($1, $3); }
    | expression PLUS expression      { $$ = create_binary_op_node("+", $1, $3); }
    | expression MINUS expression     { $$ = create_binary_op_node("-", $1, $3); }
    | expression MULTIPLY expression  { $$ = create_binary_op_node("*", $1, $3); }
    | expression DIVIDE expression    { $$ = create_binary_op_node("/", $1, $3); }
    | expression MODULO expression    { $$ = create_binary_op_node("%", $1, $3); }
    | expression EQ expression        { $$ = create_binary_op_node("==", $1, $3); }
    | expression NEQ expression       { $$ = create_binary_op_node("!=", $1, $3); }
    | expression LT expression        { $$ = create_binary_op_node("<", $1, $3); }
    | expression GT expression        { $$ = create_binary_op_node(">", $1, $3); }
    | expression LTE expression       { $$ = create_binary_op_node("<=", $1, $3); }
    | expression GTE expression       { $$ = create_binary_op_node(">=", $1, $3); }
    | expression AND expression       { $$ = create_binary_op_node("&&", $1, $3); }
    | expression OR expression        { $$ = create_binary_op_node("||", $1, $3); }
    | NOT expression                  { $$ = create_unary_op_node("!", $2); }
    | LPAREN expression RPAREN        { $$ = $2; }
    | INCREMENT IDENTIFIER            { $$ = create_unary_op_node("++", create_identifier_node($2)); }
    | DECREMENT IDENTIFIER            { $$ = create_unary_op_node("--", create_identifier_node($2)); }
    | function_call                   { $$ = $1; }
    ;

bool_literal
    : TRUE                     { $$ = create_bool_node(1); }
    | FALSE                    { $$ = create_bool_node(0); }
    ;

function_call
    : IDENTIFIER LPAREN arg_list RPAREN    { $$ = create_function_call_node($1, $3); }
    | IDENTIFIER LPAREN RPAREN             { $$ = create_function_call_node($1, NULL); }
    ;

arg_list
    : expression                  { $$ = create_arg_list($1, NULL); }
    | expression COMMA arg_list   { $$ = create_arg_list($1, $3); }
    ;

switch_statement
    : SWITCH LPAREN expression RPAREN LBRACE case_list RBRACE
        { $$ = create_switch_node($3, $6); }
    ;

case_list
    : case_statement                { $$ = $1; }
    | case_statement case_list      { $$ = create_case_list($1, $2); }
    | default_statement             { $$ = $1; }
    | case_statement default_statement { $$ = create_case_list($1, $2); }
    ;

case_statement
    : CASE NUMBER COLON statement_list
        { $$ = create_case_node(create_number_node($2), $4); }
    ;

default_statement
    : DEFAULT COLON statement_list
        { $$ = create_default_node($3); }
    ;

if_statement
    : IF LPAREN expression RPAREN statement
        { $$ = create_if_node($3, $5, NULL); }
    | IF LPAREN expression RPAREN statement ELSE statement
        { $$ = create_if_node($3, $5, $7); }
    ;

while_statement
    : WHILE LPAREN expression RPAREN statement
        { $$ = create_while_node($3, $5); }
    ;

for_statement
    : FOR LPAREN assignment SEMICOLON expression SEMICOLON assignment RPAREN statement
        { $$ = create_for_node($3, $5, $7, $9); }
    ;

do_while_statement
    : DO statement WHILE LPAREN expression RPAREN SEMICOLON
        { $$ = create_do_while_node($2, $5); }
    ;

break_statement
    : BREAK                    { $$ = create_break_node(); }
    ;

continue_statement
    : CONTINUE                 { $$ = create_continue_node(); }
    ;

print_statement
    : PRINT expression         { $$ = create_print_node($2); }
    ;

read_statement
    : READ IDENTIFIER          { $$ = create_read_node($2); }
    ;

return_statement
    : RETURN expression        { $$ = create_return_node($2); }
    | RETURN                   { $$ = create_return_node(NULL); }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", line_number, s);
}
