%{
#include "parser.tab.h" // Includes token definitions from Bison
#include <cmath>
#include <cstdlib>
#include <string>
void showerror();
%}

%%
"Interval"              { return (T_INTERVAL); }
"IntervalVector"        { return (T_INTERVALVECTOR); }

"POS_INFINITY"          { return (T_POS_INFINITY); }
"NEG_INFINITY"          { return (T_NEG_INFINITY); }
"PI"                    { return (T_PI); }
"TWO_PI"                { return (T_TWO_PI); }
"HALF_PI"               { return (T_HALF_PI); }
"EMPTY_SET"             { return (T_EMPTY_SET); }
"ALL_REALS"             { return (T_ALL_REALS); }
"ZERO"                  { return (T_ZERO); }
"ONE"                   { return (T_ONE); }
"POS_REALS"             { return (T_POS_REALS); }
"NEG_REALS"             { return (T_NEG_REALS); }

-?[0-9]+(\.[0-9]+)?     { yylval.num = atof(yytext); return (T_NUMBER); }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.id = (char)(yytext[0]); return (T_IDENTIFIER); }


";"                     { return (T_SEMICOLON); }
"::"                    { return (T_COLON); }
"="                     { return (T_ASSIGN); }
"("                     { return (T_LPAREN); }
")"                     { return (T_RPAREN); }
","                     { return (T_COMMA); }
"\+"                     { return (T_PLUS); }
"-"                     { return (T_MINUS); }
"\*"                     { return (T_MULT); }
"/"                     { return (T_DIVIDE); }


[ \t\r\n]+          /* Ignore whitespace */

.                   printf("Unexpected character: %s\n", yytext);

%%

void showerror() {
    printf("Wrong input\n");
}

int yywrap() {
    return 1;
}
