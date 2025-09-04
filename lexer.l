%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

int line_number = 1;
%}

%option noyywrap

/* Definitions */
DIGIT       [0-9]
ID          [a-zA-Z][a-zA-Z0-9_]*
NUMBER      {DIGIT}+
WHITESPACE  [ \t\r]+
NEWLINE     \n

%%

{WHITESPACE}    { /* Ignore whitespace */ }
{NEWLINE}       { line_number++; }

"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"for"           { return FOR; }
"do"            { return DO; }
"break"         { return BREAK; }
"continue"      { return CONTINUE; }
"switch"        { return SWITCH; }
"case"          { return CASE; }
"default"       { return DEFAULT; }
"print"         { return PRINT; }
"read"          { return READ; }
"int"           { return INT; }
"string"        { return STRING; }
"void"          { return VOID; }
"bool"          { return BOOL; }
"true"          { return TRUE; }
"false"         { return FALSE; }
"main"          { return MAIN; }
"return"        { return RETURN; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULTIPLY; }
"/"             { return DIVIDE; }
"%"             { return MODULO; }
"="             { return ASSIGN; }
"=="            { return EQ; }
"!="            { return NEQ; }
"<"             { return LT; }
">"             { return GT; }
"<="            { return LTE; }
">="            { return GTE; }
"++"            { return INCREMENT; }
"--"            { return DECREMENT; }
"+="            { return PLUS_ASSIGN; }
"-="            { return MINUS_ASSIGN; }
"*="            { return MULT_ASSIGN; }
"/="            { return DIV_ASSIGN; }
"%="            { return MOD_ASSIGN; }
"&&"            { return AND; }
"||"            { return OR; }
"!"             { return NOT; }

"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
";"             { return SEMICOLON; }
","             { return COMMA; }
":"             { return COLON; }

{NUMBER}        { 
                  yylval.ival = atoi(yytext);
                  return NUMBER; 
                }

{ID}            {
                  yylval.sval = strdup(yytext);
                  return IDENTIFIER;
                }

\"[^\"]*\"      {
                  // Strip quotes from string literal
                  yytext[strlen(yytext) - 1] = '\0';  // Remove closing quote
                  yylval.sval = strdup(yytext + 1);   // Skip opening quote
                  return STRING_LITERAL;
                }

"//".*          { /* Ignore single-line comments */ }

"/*"([^*]|\*+[^*/])*\*+"/" { /* Ignore multi-line comments */ }

.               { printf("Lexical error: Unknown token '%s' at line %d\n", yytext, line_number); }

%%
