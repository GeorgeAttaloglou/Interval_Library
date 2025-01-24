%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>  // For file operations if used
#include <cstdio>   // For yyin if using Flex/Bison
#include <ctype.h>

int yylex(); // Declare lexer function
void yyerror(const char* s); // Declare error reporting function

extern FILE *yyin;
extern int yyparse();
extern char *yytext; // Χρησιμοποιείται για την εμφάνιση του token σε σφάλμα

char addtotable(char, char, char);

int index1 = 0;
char temp = 'A' - 1;


struct expr{
    
    char operand1;
    char operand2;
    char oprator;
    char result;
};

struct expr arr[30];

char addtotable(char a, char b, char o){
    temp++;
    arr[index1].operand1 = a;
    arr[index1].operand2 = b;
    arr[index1].oprator = o;
    arr[index1].result = temp;
    index1++;

    return temp;
}

void threeAdd(){

    int i = 0;
    char temp = 'A';
    while(i < index1){
        printf("%c :=\t", arr[i].result);
        printf("%c\t", arr[i].operand1);
        printf("%c\t", arr[i].oprator);
        printf("%c\t", arr[i].operand2);
        i++;
        temp++;
        printf("\n");
    }
}

void fourAdd(){
    int i = 0;
    char temp = 'A';
    while(i < index1){
        printf("%c\t", arr[i].oprator);
        printf("%c\t", arr[i].operand1);
        printf("%c\t", arr[i].operand2);
        printf("%c", arr[i].result);
        i++;
        temp++;
        printf("\n");
    }
}

int find(char p){
    int i;
    for(i = 0; i < index1; i++){
        if(arr[i].result == p) break;
        return i;
    }
}

void triple(){
    int i = 0;
    char temp = 'A';
    while(i < index1){
        printf("%c\t", arr[i].oprator);
        if(!isupper(arr[i].operand1)){
            printf("%c\t", arr[i].operand1);
        }
        else{
            printf("pointer");
            printf("%d\t", find(arr[i].operand1));
        }
        if(!isupper(arr[i].operand2)){
            printf("%c\t", arr[i].operand2);
        }
        else{
            printf("pointer");
            printf("%d\t", find(arr[i].operand2));
        }
        i++;
        temp++;
        printf("\n");
    }
}

%}





// Define token types
%union {
    char id;     // For identifiers
    double num;   // For numbers
    char ch;
}

// Declare tokens and link them to their types
%token <id> T_IDENTIFIER
%token <num> T_NUMBER
%token T_INTERVAL T_INTERVALVECTOR
%token <num> T_POS_INFINITY T_NEG_INFINITY
%token T_ASSIGN
%token <num> T_PI T_TWO_PI T_HALF_PI T_EMPTY_SET T_ALL_REALS T_ZERO T_ONE T_POS_REALS T_NEG_REALS
%token T_LPAREN T_RPAREN T_COMMA T_COLON T_SEMICOLON
%token T_PLUS T_MINUS T_MULT T_DIVIDE
%type <ch> arithmetic_expr

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
        { printf("Recognized interval declaration: %c  \n", $2); }
    | T_INTERVAL T_IDENTIFIER interval_expr T_SEMICOLON
        { printf("Recognized interval declaration with expression: %c \n", $2); }
    | T_INTERVALVECTOR T_IDENTIFIER intervalvector_expr T_SEMICOLON
        { printf("Recognized interval vector declaration: %c \n", $2); }
    | T_INTERVAL T_IDENTIFIER T_ASSIGN arithmetic_expr T_SEMICOLON 
        {addtotable((char)$2,(char)$4, '='); printf("Recognized interval declaration with assignment and calculation: %c \n", $2); }
    | T_INTERVAL T_IDENTIFIER interval_const_expr T_SEMICOLON
        { printf("Recognized interval declaration with constant expression: %c \n", $2); }     
    ;

interval_expr: 
    T_LPAREN T_IDENTIFIER T_RPAREN
    | T_LPAREN T_NUMBER T_RPAREN  
    | T_ASSIGN T_IDENTIFIER
    | T_LPAREN T_NUMBER T_COMMA T_NUMBER T_RPAREN
    | T_LPAREN T_NEG_INFINITY T_COMMA T_POS_INFINITY T_RPAREN 
    | T_LPAREN T_NEG_INFINITY T_COMMA T_NUMBER T_RPAREN
    | T_LPAREN T_NUMBER T_COMMA T_NEG_INFINITY T_RPAREN
    | T_LPAREN T_POS_INFINITY T_COMMA T_NUMBER T_RPAREN
    | T_LPAREN T_NUMBER T_COMMA T_POS_INFINITY T_RPAREN
    ;

arithmetic_expr:
    T_IDENTIFIER T_PLUS T_IDENTIFIER {$$ = addtotable((char)$1, (char)$3, '+'); }
    |  T_IDENTIFIER T_MINUS T_IDENTIFIER {$$ = addtotable((char)$1, (char)$3, '-'); }
    |  T_IDENTIFIER T_MULT T_IDENTIFIER {$$ = addtotable((char)$1, (char)$3, '*'); }
    |  T_IDENTIFIER T_DIVIDE T_IDENTIFIER {$$ = addtotable((char)$1, (char)$3, '/'); }

interval_const_expr:
    T_ASSIGN T_INTERVAL T_COLON constant 

constant:
    T_PI 
    | T_TWO_PI 
    | T_HALF_PI 
    | T_EMPTY_SET 
    | T_ALL_REALS 
    | T_ZERO 
    | T_ONE 
    | T_POS_REALS 
    | T_NEG_REALS
    ;

intervalvector_expr:
    T_LPAREN T_NUMBER T_COMMA T_IDENTIFIER T_RPAREN
    ;


%%


void yyerror(const char *s) {
    std::cerr << "Error: " << s << " at token: " << yytext << std::endl;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;
        return 1;
    }

    // Αναθέτουμε το αρχείο εισόδου στο yyin
    yyin = inputFile;

    // Εκτελούμε την ανάλυση
    int parseResult = yyparse();
    threeAdd();
    printf("\n");
    fourAdd();
    printf("\n");
    triple();

    if (parseResult == 0) {
        std::cout << "Parsing completed successfully." << std::endl;
    } else {
        std::cerr << "Parsing failed. Check the syntax and the token causing the error." << std::endl;
    }

    fclose(inputFile);
    return parseResult;
}
