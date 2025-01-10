%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int yylex(); // Declare lexer function
void yyerror(const char* s); // Declare error reporting function
%}

// Define token types
%union {
    char* id;     // For identifiers
    double num;   // For numbers
}

// Declare tokens and link them to their types
%token <id> T_IDENTIFIER
%token <num> T_NUMBER
%token T_INTERVAL T_INTERVALVECTOR
%token <num> T_POS_INFINITY T_NEG_INFINITY
%token T_PLUS T_MINUS T_MULT T_DIV T_ASSIGN
%token T_LPAREN T_RPAREN T_COMMA T_SEMICOLON

%%

program:
    declaration_list
    ;

declaration_list:
    declaration_list declaration
    | declaration
    ;

declaration:
    T_INTERVAL T_IDENTIFIER T_SEMICOLON
        { free($2); }
    | T_INTERVAL T_IDENTIFIER interval_expr T_SEMICOLON
        { free($2); }
    | T_INTERVALVECTOR T_IDENTIFIER intervalvector_expr T_SEMICOLON
        { free($2); }
    ;

interval_expr: 
    T_LPAREN T_IDENTIFIER T_RPAREN
    | T_LPAREN T_NUMBER T_RPAREN 
    | T_ASSIGN T_IDENTIFIER 
    | T_LPAREN T_NUMBER T_COMMA T_NUMBER T_RPAREN 
    | T_LPAREN T_NEG_INFINITY T_COMMA T_POS_INFINITY T_RPAREN 
    ;

intervalvector_expr:
    T_LPAREN T_NUMBER T_COMMA T_IDENTIFIER T_RPAREN
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Starting parser...\n");
    if (yyparse() == 0) {
        printf("Parsing completed successfully.\n");
    } else {
        printf("Parsing failed.\n");
    }
    return 0;
}
