%{
#include "parser.tab.h" // Includes token definitions from Bison
%}

%%

"Interval"          return T_INTERVAL;
"IntervalVector"    return T_INTERVALVECTOR;
"POS_INFINITY"      return T_POS_INFINITY;
"NEG_INFINITY"      return T_NEG_INFINITY;
[0-9]+(\.[0-9]+)?   { yylval.num = atof(yytext); return T_NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.id = strdup(yytext); return T_IDENTIFIER; }
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
