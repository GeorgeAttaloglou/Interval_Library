%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
%token T_POS_INFINITY T_NEG_INFINITY
%token T_PLUS T_MINUS T_MULT T_DIV T_ASSIGN
%token T_LPAREN T_RPAREN T_COMMA T_SEMICOLON

%type <num> interval_expr vector_expr

%%

program:
    declaration_list
    ;

declaration_list:
    declaration_list declaration
    | declaration
    ;

declaration:
    T_INTERVAL T_IDENTIFIER T_ASSIGN interval_expr T_SEMICOLON
        { printf("Interval '%s' assigned.\n", $2); free($2); }
    | T_INTERVALVECTOR T_IDENTIFIER T_ASSIGN vector_expr T_SEMICOLON
        { printf("IntervalVector '%s' assigned.\n", $2); free($2); }
    ;

interval_expr:
    T_LPAREN T_NUMBER T_COMMA T_NUMBER T_RPAREN
        { printf("Interval: [%f, %f]\n", $2, $4); $$ = 0; }
    | T_LPAREN T_NEG_INFINITY T_COMMA T_POS_INFINITY T_RPAREN
        { printf("Interval: [-∞, +∞]\n"); $$ = 0; }
    ;

vector_expr:
    T_INTERVALVECTOR T_LPAREN interval_expr_list T_RPAREN
        { printf("IntervalVector created.\n"); $$ = 0; }
    ;

interval_expr_list:
    interval_expr_list T_COMMA interval_expr
    | interval_expr
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
