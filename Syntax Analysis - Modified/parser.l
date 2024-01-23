%{
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
at [@]
char \'.\'
string \".*\"
%x FUNCTION
%x ARRAY

%%
{space}* {}
{tab}* {}
{string} {if(check_mlc()){inserttoLL("STRING CONSTANT", yytext, line_no);return STRING_CONST;}}
{char} {if(check_mlc()){inserttoLL("CHARACTER CONSTANT", yytext, line_no);return CHAR_CONST;}}
{line} {line_no++;}

int {if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return INT;}}
float {if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return FLOAT;}}
char {if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return CHAR;}}

break {if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return BREAK;}}
case {if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return CASE;}}
default {if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return DEFAULT;}}
continue {if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return CONTINUE;}}
else {if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return ELSE;}}
for {if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return FOR;}}
if {if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return IF;}}
return {if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return RETURN;}}
switch {if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return SWITCH;}}
void {if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return VOID;}}
while {if(check_mlc()){inserttoLL("KEYWORD",yytext,line_no);return WHILE;}}

printf {if(check_mlc()){inserttoLL("KEYWORD", yytext, line_no);return PRINTF;}}

{alpha}({alpha}|{digit}|{und})* {if(check_mlc()){inserttoLL("IDENTIFIER",yytext,line_no);return ID;}}

[-][0-9]{digit}*(\.{digit}+)? {if(check_mlc()){inserttoLL("SIGNED CONSTANT", yytext, line_no);return SIGNED_CONST;}}

\/\/.* ;
"/*" {if(check_mlc()){mlcline=line_no;set_mlc();}}
"*/" {if(check_mlc()){
        yyerror();
        exit(1);
    }
    else{
        reset_mlc();
    }
}


">" {if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return GT;}}
"<" {if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return LT;}}
">=" {if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return GE;}}
"<=" {if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return LE;}}
"==" {if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return EQ;}}
"!=" {if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return NE;}}
"&&" {if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return LAND;}}
"\|\|" {if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return LOR;}}
"!" {if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return NOT;}}
"=" {if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return ASSIGN;}}
"+" {if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return PLUS;}}
"-" {if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return MINUS;}}
"*" {if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return MUL;}}
"/" {if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return DIV;}}
"%" {if(check_mlc()){inserttoLL("OPERATOR",yytext,line_no);return MOD;}}

":" {if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return COLON;}}
";" {if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return SEMICOLON;}}
"," {if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return COMMA;}}
"(" {if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return LPAREN;}}
")" {if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return RPAREN;}}
"{" {if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return LBRACE;}}
"}" {if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return RBRACE;}}
"[" {if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return LBRACKET;}}
"]" {if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return RBRACKET;}}
"#".* {;}
"\"" {if(check_mlc()){inserttoLL("SPECIAL SYMBOL",yytext,line_no);return DQ;}}

"%d"|"%f"|"%s"|"%c" {if(check_mlc()){inserttoLL("TYPE_SPEC", yytext, line_no);return TYPE_SPEC;}}

{digit}+ {if(check_mlc()){inserttoLL("INTEGER CONSTANT", yytext, line_no);return INT_CONST;}}
{digit}+\.{digit}+ {if(check_mlc()){inserttoLL("FLOAT CONSTANT", yytext, line_no);return FLOAT_CONST;}}

{alpha}({alpha}|{digit}|{und})*\[\] {if(check_mlc()){inserttoLL("C ARRAY", yytext, line_no);return ARR_E;}}
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

<ARRAY>{alpha}({alpha}|{digit})* {BEGIN(INITIAL); inserttoLL("ARR", yytext, line_no); return ARR;}


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