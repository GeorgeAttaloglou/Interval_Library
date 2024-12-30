%{
#include "tokens.h"
#include <stdio.h>
%}

%%

"Interval"          return T_INTERVAL;
"IntervalVector"    return T_INTERVALVECTOR;
[0-9]+(\.[0-9]+)?   return T_NUMBER;
"\+"                return T_PLUS;
"-"                 return T_MINUS;
"\*"                return T_MULT;
"/"                 return T_DIV;
"="                 return T_ASSIGN;
"("                 return T_LPAREN;
")"                 return T_RPAREN;
","                 return T_COMMA;
";"                 return T_SEMICOLON;
[a-zA-Z_][a-zA-Z0-9_]*   return T_IDENTIFIER; // Matches variable names

[ \t\r\n]+          /* Ignore whitespace */

.                   printf("Unexpected character: %s\n", yytext);

%%

int yywrap() {
    return 1;
}
