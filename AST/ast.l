%{
    #include "header.h"
    #include "y.tab.h"
    int mlcline = 0, line_no = 1;
    struct node *create_node(char *lexeme, char *token, int line_no);
    void inserttoLL(char* lexeme, char* token, int line_no);
    void dis();
    int check_mlc();
    void set_mlc();
    void reset_mlc();
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
%x ARRAY

%%
{space}* {}
{tab}* {}
{string} {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("STRING CONSTANT", yytext, line_no);return STRING_CONST;}}
{char} {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("CHARACTER CONSTANT", yytext, line_no);return CHAR_CONST;}}
{line} {strcpy(yylval.string, yytext);line_no++;}

int {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return INT;}}
float {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return FLOAT;}}
char {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return CHAR;}}

break {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return BREAK;}}
case {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return CASE;}}
default {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return DEFAULT;}}
continue {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return CONTINUE;}}
else {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return ELSE;}}
for {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return FOR;}}
if {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return IF;}}
return {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return RETURN;}}
switch {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return SWITCH;}}
void {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return VOID;}}
while {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return WHILE;}}

printf {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("KEYWORD", yytext, line_no);return PRINTF;}}

{alpha}({alpha}|{digit}|{und})* {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("IDENTIFIER",yytext,line_no);return ID;}}

[-][0-9]{digit}*(\.{digit}+)? {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("SIGNED CONSTANT", yytext, line_no);return SIGNED_CONST;}}

\/\/.* ;
"/*"(.|{line})*"*/" {for(int i=0; i<strlen(yytext); i++){if(yytext[i] == '\n'){line_no++;}}}


">" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return GT;}}
"<" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return LT;}}
">=" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return GE;}}
"<=" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return LE;}}
"==" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return EQ;}}
"!=" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return NE;}}
"&&" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return LAND;}}
"\|\|" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return LOR;}}
"!" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return NOT;}}
"=" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return ASSIGN;}}
"+" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return PLUS;}}
"-" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return MINUS;}}
"*" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return MUL;}}
"/" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return DIV;}}
"%" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return MOD;}}

":" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return COLON;}}
";" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return SEMICOLON;}}
"," {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return COMMA;}}
"(" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return LPAREN;}}
")" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return RPAREN;}}
"{" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return LBRACE;}}
"}" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return RBRACE;}}
"[" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return LBRACKET;}}
"]" {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return RBRACKET;}}
"#".* {;}
"\"" {if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return DQ;}}

"%d"|"%f"|"%s"|"%c" {if(check_mlc()){inserttoLL("TYPE_SPEC", yytext, line_no);return TYPE_SPEC;}}

{digit}+ {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("INTEGER CONSTANT", yytext, line_no);return INT_CONST;}}
{digit}+\.{digit}+ {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("FLOAT CONSTANT", yytext, line_no);return FLOAT_CONST;}}

{alpha}({alpha}|{digit}|{und})*\[\] {strcpy(yylval.string, yytext);if(check_mlc()){inserttoLL("C ARRAY", yytext, line_no);return ARR_E;}}
{alpha}({alpha}|{digit})*\[({digit}+)\] {
                                    for(int i = yyleng - 1;i>=0; i--){
                                        unput(yytext[i]);
                                    }
                                    BEGIN(ARRAY);
                                    }

{alpha}({alpha}|{digit})*\[({digit}*)\]\[({digit}*)\] {
                                                    for(int i = yyleng - 1;i>=0; i--){
                                                        unput(yytext[i]);
                                                    }
                                                    BEGIN(ARRAY);
                                                  }

<ARRAY>{alpha}({alpha}|{digit})* {BEGIN(INITIAL); inserttoLL("ARR", yytext, line_no); strcpy(yylval.string, yytext); return ARR;}


{alpha}({alpha}|{digit}|{und})*\(({alpha}|{digit}|{und}|{space}|,)*\) {
                                                    if(check_mlc())
                                                    {
                                                        for(int i = yyleng-1; i>=0; i--){
                                                            unput(yytext[i]);
                                                        }
                                                        BEGIN(FUNCTION);
                                                    }
                                                }

<FUNCTION>{alpha}({alpha}|{digit})* {
                                    strcpy(yylval.string, yytext);
                                    BEGIN(INITIAL);
                                    if(strcmp("if", yytext)==0){inserttoLL("KEYWORD", yytext, line_no); return IF;}
                                    else if(strcmp("printf", yytext)==0){inserttoLL("KEYWORD", yytext, line_no); return PRINTF;}
                                    else if(strcmp("for", yytext)==0){inserttoLL("KEYWORD",yytext, line_no); return FOR;}
                                    else if(strcmp("while", yytext)==0){inserttoLL("KEYWORD", yytext, line_no); return WHILE;}
                                    else if(strcmp("switch", yytext)==0){inserttoLL("KEYWORD", yytext, line_no); return SWITCH;}
                                    inserttoLL("FUNCTION", yytext, line_no);
                                    return FUNC_NAME;
                                }

%%

int yywrap(){
return(1);
}