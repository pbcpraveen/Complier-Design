%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "y.tab.h"
void yyerror(char*);
extern char* yylval;

%}
WHILE "while"
DO "do"
OPERATORS [+-*/]
IDENTIFIERS [a-zA-Z_][a-zA-Z0-9_]*
INTEGER [0-9]+
BRACES [{}]
RELOP [<>]
SEMICOLON [;]
%%
[ \t]+ ;
INTEGER { yylval=(char *)malloc(strlen(yytext));
        strcpy(yylval,yytext);
        return INTEGER;}
OPERATORS { yylval=(char *)malloc(strlen(yytext));
    strcpy(yylval,yytext);
    return OPERATORS;}
WHILE { yylval=(char *)malloc(strlen(yytext));
    strcpy(yylval,yytext);
    return WHILE;}
DO { yylval=(char *)malloc(strlen(yytext));
    strcpy(yylval,yytext);
    return DO;}       
BRACES { yylval=(char *)malloc(strlen(yytext));
    strcpy(yylval,yytext);
    return BRACES;}
RELOP { yylval=(char *)malloc(strlen(yytext));
    strcpy(yylval,yytext);
    return RELOP;}
IDENTIFIERS { yylval=(char *)malloc(strlen(yytext));
    strcpy(yylval,yytext);
    return IDENTIFIERS;}
SEMICOLON { yylval=(char *)malloc(strlen(yytext));
    strcpy(yylval,yytext);
    return SEMICOLON;}
\n {}
. {printf("error");}
                

%%

