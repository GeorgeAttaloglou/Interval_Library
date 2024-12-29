%{
#include "tokens.h"
#include <stdio.h>
%}

%token T_INTERVAL T_IDENTIFIER T_INTERVALVECTOR 
%token T_NUMBER T_POS_INFINITY T_NEG_INFINITY
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
    T_INTERVAL T_IDENTIFIER T_ASSIGN interval_expr T_SEMICOLON
    | T_INTERVALVECTOR T_IDENTIFIER T_ASSIGN vector_expr T_SEMICOLON
    ;

interval_expr:
    T_LPAREN T_NUMBER T_COMMA T_NUMBER T_RPAREN
    | T_LPAREN T_NEG_INFINITY T_COMMA T_POS_INFINITY T_RPAREN
    ;

vector_expr:
    T_INTERVALVECTOR T_LPAREN interval_expr_list T_RPAREN
    ;

interval_expr_list:
    interval_expr_list T_COMMA interval_expr
    | interval_expr
    ;

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
}
