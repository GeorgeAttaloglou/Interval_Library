%{
#include "parser.tab.h"
#include <cmath>
#include <cstdlib>
#include <string>

#define MAX_VAR_NAME 100
%}

DIGIT       [0-9]
NUMBER      {DIGIT}+(\.{DIGIT}*)?([eE][+-]?{DIGIT}+)?

%%

"Interval"              { return INTERVAL; }
"Interval::PI"          { return PI; }
"Interval::TWO_PI"      { return TWO_PI; }
"Interval::HALF_PI"     { return HALF_PI; }
"Interval::EMPTY_SET"   { return EMPTY_SET; }
"Interval::ALL_REALS"   { return ALL_REALS; }
"Interval::ZERO"        { return ZERO; }
"Interval::ONE"         { return ONE; }
"Interval::POS_REALS"   { return POS_REALS; }
"Interval::NEG_REALS"   { return NEG_REALS; }
"POS_INFINITY"          { return POS_INFINITY; }
"NEG_INFINITY"          { return NEG_INFINITY; }

{NUMBER}                { yylval.num = atof(yytext); return NUMBER; }

[a-zA-Z_][a-zA-Z0-9_]*  { strncpy(yylval.str, yytext, MAX_VAR_NAME - 1); yylval.str[MAX_VAR_NAME - 1] = '\0'; return IDENTIFIER; }

"("                     { return '('; }
")"                     { return ')'; }
","                     { return ','; }
"="                     { return '='; }
";"                     { return ';'; }

[ \t\r\n]+              { /* Ignore whitespace */ }
.                       { printf("Unknown character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}