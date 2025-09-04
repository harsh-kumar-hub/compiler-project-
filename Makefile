CC = gcc
CFLAGS = -Wall -g
FLEX = flex
BISON = bison
LIBS = -lreadline

all: minic

minic: lex.yy.c parser.tab.c ast.c main.c interpreter.c symbol_table.c
	$(CC) $(CFLAGS) -o minic lex.yy.c parser.tab.c ast.c main.c interpreter.c symbol_table.c $(LIBS)

lex.yy.c: lexer.l parser.tab.h
	$(FLEX) lexer.l

parser.tab.c parser.tab.h: parser.y
	$(BISON) -d parser.y

clean:
	rm -f minic lex.yy.c parser.tab.c parser.tab.h *.o

.PHONY: all clean
