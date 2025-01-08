%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>


// Forward declaration for yylex
int yylex(void);
void yyerror(const char *s);
%}

%union {
    double num;          // Για αριθμούς
    char str[100];    // Για ονόματα μεταβλητών
}


%token <num> NUMBER
%token <str> IDENTIFIER
%token INTERVAL
%token POS_INFINITY NEG_INFINITY EMPTY_SET ALL_REALS PI TWO_PI HALF_PI ZERO ONE POS_REALS NEG_REALS

%type <str> variable_declaration
%type <str> interval_expression

%%

program:
    /* Empty */
    | program statement
;

statement:
    variable_declaration ';'
    | interval_constant ';'
    | error ';' { yyerror("Syntax error"); }
;

variable_declaration:
    INTERVAL IDENTIFIER ';'                           { printf("Variable %s initialized as (-∞, +∞)\n", $2); }
    | INTERVAL IDENTIFIER '=' interval_expression     { printf("Variable %s assigned an interval\n", $2); }
;

interval_expression:
    '(' NUMBER ',' NUMBER ')'        { printf("Interval [%f, %f]\n", $2, $4); }
    | '(' NUMBER ',' POS_INFINITY ')' { printf("Interval [%f, +∞)\n", $2); }
    | '(' NEG_INFINITY ',' NUMBER ')' { printf("Interval (-∞, %f]\n", $4); }
    | IDENTIFIER                     { printf("Reference to variable %s\n", $1); }
;

interval_constant:
    "Interval::PI"      { printf("Interval::PI\n"); }
    | "Interval::TWO_PI" { printf("Interval::TWO_PI\n"); }
    | "Interval::HALF_PI" { printf("Interval::HALF_PI\n"); }
    | "Interval::EMPTY_SET" { printf("Interval::EMPTY_SET\n"); }
    | "Interval::ALL_REALS" { printf("Interval::ALL_REALS\n"); }
    | "Interval::ZERO" { printf("Interval::ZERO\n"); }
    | "Interval::ONE" { printf("Interval::ONE\n"); }
    | "Interval::POS_REALS" { printf("Interval::POS_REALS\n"); }
    | "Interval::NEG_REALS" { printf("Interval::NEG_REALS\n"); }
;

%%

void yyerror(const char *s) {
    std::cerr << "Error: " << s << std::endl;
}

int main() {
    printf("Enter your program (end input with Ctrl+D):\n");

    int parseResult = yyparse();

    if (parseResult == 0) {
        printf("Parsing completed successfully.\n");
    } else {
        printf("Parsing failed. Please check your syntax.\n");
    }

    return parseResult;
}