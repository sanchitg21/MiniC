%{
    #include "y.tab.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int line_no = 1;
%}

alpha [a-zA-Z]
digit [0-9]
und [_]
space [ ]
tab [\t]
line [\n]
char \'.\'
string \".*\"
%x FUNCTION

%%
{space}* {}
{tab}* {}
{string} {yylval.lexeme = strdup(yytext); return STRING_CONST;}
{char} {yylval.lexeme = strdup(yytext); return CHAR_CONST;}
{line} {line_no++;}

"#".* {;}
\/\/.* {;}
\/\*(.|{line})*\*\/ {for(int i=0; i<strlen(yytext); i++){if(yytext[i] == '\n'){line_no++;}}}

int {yylval.lexeme = strdup(yytext); return INT;}
float {yylval.lexeme = strdup(yytext); return FLOAT;}
char {yylval.lexeme = strdup(yytext); return CHAR;}

break {yylval.lexeme = strdup(yytext); return BREAK;}
case {yylval.lexeme = strdup(yytext); return CASE;}
default {yylval.lexeme = strdup(yytext); return DEFAULT;}
continue {yylval.lexeme = strdup(yytext); return CONTINUE;}
else {yylval.lexeme = strdup(yytext); return ELSE;}
for {yylval.lexeme = strdup(yytext); return FOR;}
if {yylval.lexeme = strdup(yytext); return IF;}
return {yylval.lexeme = strdup(yytext); return RETURN;}
switch {yylval.lexeme = strdup(yytext); return SWITCH;}
void {yylval.lexeme = strdup(yytext); return VOID;}
while {yylval.lexeme = strdup(yytext); return WHILE;}

printf {yylval.lexeme = strdup(yytext); return PRINTF;}

{alpha}({alpha}|{digit}|{und})* {yylval.lexeme = strdup(yytext); return ID;}

[-][0-9]{digit}*(\.{digit}+)? {yylval.lexeme = strdup(yytext); return SIGNED_CONST;}

">" {yylval.lexeme = strdup(yytext); return GT;}
"<" {yylval.lexeme = strdup(yytext); return LT;}
">=" {yylval.lexeme = strdup(yytext); return GE;}
"<=" {yylval.lexeme = strdup(yytext); return LE;}
"==" {yylval.lexeme = strdup(yytext); return EQ;}
"!=" {yylval.lexeme = strdup(yytext); return NE;}
"&&" {yylval.lexeme = strdup(yytext); return LAND;}
"\|\|" {yylval.lexeme = strdup(yytext); return LOR;}
"!" {yylval.lexeme = strdup(yytext); return NOT;}
"=" {yylval.lexeme = strdup(yytext); return ASSIGN;}
"+" {yylval.lexeme = strdup(yytext); return PLUS;}
"-" {yylval.lexeme = strdup(yytext); return MINUS;}
"*" {yylval.lexeme = strdup(yytext); return MUL;}
"/" {yylval.lexeme = strdup(yytext); return DIV;}yylval.lexeme = strdup(yytext); 
"%" {yylval.lexeme = strdup(yytext); return MOD;}

":" {yylval.lexeme = strdup(yytext); return COLON;}
";" {yylval.lexeme = strdup(yytext); return SEMICOLON;}
"," {yylval.lexeme = strdup(yytext); return COMMA;}
"(" {yylval.lexeme = strdup(yytext); return LPAREN;}
")" {yylval.lexeme = strdup(yytext); return RPAREN;}
"{" {yylval.lexeme = strdup(yytext); return LBRACE;}
"}" {yylval.lexeme = strdup(yytext); return RBRACE;}
"[" {yylval.lexeme = strdup(yytext); return LBRACKET;}
"]" {yylval.lexeme = strdup(yytext); return RBRACKET;}
"\"" {yylval.lexeme = strdup(yytext); return DQ;}

"%d"|"%f"|"%s"|"%c" {yylval.lexeme = strdup(yytext); return TYPE_SPEC;}

{digit}+ {yylval.lexeme = strdup(yytext);return INT_CONST;}
{digit}+\.{digit}+ {yylval.lexeme = strdup(yytext);return FLOAT_CONST;}

{alpha}({alpha}|{digit}|{und})*\[\] {yylval.lexeme = strdup(yytext);return ARR_E;}
{alpha}({alpha}|{digit}|{und})*\[{digit}*\] {yylval.lexeme = strdup(yytext);return ARR;}
{alpha}({alpha}|{digit}|{und})*\[{digit}*\]\[{digit}*\] {yylval.lexeme = strdup(yytext);return ARR2D;}
{alpha}({alpha}|{digit}|{und})*\(({alpha}|{digit}|{und}|{space}|,)*\) {
                                                    for(int i = yyleng-1; i>=0; i--){
                                                        unput(yytext[i]);
                                                    }
                                                    BEGIN(FUNCTION);
                                                }

<FUNCTION>{alpha}({alpha}|{digit})* {
                                    BEGIN(INITIAL);
                                    if(strcmp("if", yytext)==0){yylval.lexeme = strdup(yytext);  return IF;}
                                    else if(strcmp("printf", yytext)==0){yylval.lexeme = strdup(yytext);  return PRINTF;}
                                    else if(strcmp("for", yytext)==0){yylval.lexeme = strdup(yytext); return FOR;}
                                    else if(strcmp("while", yytext)==0){yylval.lexeme = strdup(yytext);  return WHILE;}
                                    else if(strcmp("switch", yytext)==0){yylval.lexeme = strdup(yytext);  return SWITCH;}
                                    yylval.lexeme = strdup(yytext);
                                    yylval.lexeme = strdup(yytext); 
                                    return FUNC_NAME;
                                }

%%

int yywrap(){
return(1);
}