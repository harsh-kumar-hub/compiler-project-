/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    IDENTIFIER = 259,              /* IDENTIFIER  */
    STRING_LITERAL = 260,          /* STRING_LITERAL  */
    IF = 261,                      /* IF  */
    ELSE = 262,                    /* ELSE  */
    WHILE = 263,                   /* WHILE  */
    FOR = 264,                     /* FOR  */
    DO = 265,                      /* DO  */
    BREAK = 266,                   /* BREAK  */
    CONTINUE = 267,                /* CONTINUE  */
    SWITCH = 268,                  /* SWITCH  */
    CASE = 269,                    /* CASE  */
    DEFAULT = 270,                 /* DEFAULT  */
    PRINT = 271,                   /* PRINT  */
    READ = 272,                    /* READ  */
    INT = 273,                     /* INT  */
    STRING = 274,                  /* STRING  */
    VOID = 275,                    /* VOID  */
    BOOL = 276,                    /* BOOL  */
    TRUE = 277,                    /* TRUE  */
    FALSE = 278,                   /* FALSE  */
    MAIN = 279,                    /* MAIN  */
    RETURN = 280,                  /* RETURN  */
    PLUS = 281,                    /* PLUS  */
    MINUS = 282,                   /* MINUS  */
    MULTIPLY = 283,                /* MULTIPLY  */
    DIVIDE = 284,                  /* DIVIDE  */
    MODULO = 285,                  /* MODULO  */
    ASSIGN = 286,                  /* ASSIGN  */
    EQ = 287,                      /* EQ  */
    NEQ = 288,                     /* NEQ  */
    LT = 289,                      /* LT  */
    GT = 290,                      /* GT  */
    LTE = 291,                     /* LTE  */
    GTE = 292,                     /* GTE  */
    INCREMENT = 293,               /* INCREMENT  */
    DECREMENT = 294,               /* DECREMENT  */
    PLUS_ASSIGN = 295,             /* PLUS_ASSIGN  */
    MINUS_ASSIGN = 296,            /* MINUS_ASSIGN  */
    MULT_ASSIGN = 297,             /* MULT_ASSIGN  */
    DIV_ASSIGN = 298,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 299,              /* MOD_ASSIGN  */
    AND = 300,                     /* AND  */
    OR = 301,                      /* OR  */
    NOT = 302,                     /* NOT  */
    LPAREN = 303,                  /* LPAREN  */
    RPAREN = 304,                  /* RPAREN  */
    LBRACE = 305,                  /* LBRACE  */
    RBRACE = 306,                  /* RBRACE  */
    LBRACKET = 307,                /* LBRACKET  */
    RBRACKET = 308,                /* RBRACKET  */
    SEMICOLON = 309,               /* SEMICOLON  */
    COMMA = 310,                   /* COMMA  */
    COLON = 311                    /* COLON  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "parser.y"

    int ival;
    char* sval;
    struct ASTNode* ast;

#line 126 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
