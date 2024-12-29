%{
#include "tokens.h"
#include <stdio.h>
%}

%%

"interval"          return T_INTERVAL;
"vector"            return T_VECTOR;
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

[ \t\r\n]+          /* Ignore whitespace */

.                   printf("Unexpected character: %s\n", yytext);

%%

int yywrap() {
    return 1;
}
