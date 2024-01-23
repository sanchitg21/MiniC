%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>


    /* TYPE */
    #define INT 1
    #define CHAR 2
    #define FLOAT 3

    /* OPERATOR */
    #define PLUS 4
    #define MINUS 5
    #define MULT 6
    #define DIV 7
    #define MOD 8
    #define ASSIGN 9
    #define EQ 10
    #define NE 11
    #define GT 12
    #define LS 13
    #define GE 14
    #define LE 15
    #define LAND 16
    #define LOR 17
    #define NOT 49

    /* DELIMITER */
    #define SEMICOLON 18
    #define COMMA 19
    #define LPAREN 20
    #define RPAREN 21
    #define LBRACE 22
    #define RBRACE 23
    #define LBRACKET 24
    #define RBRACKET 25

    /* KEYWORD */
    #define IF 26
    #define ELSE 27
    #define WHILE 28
    #define FOR 29
    #define DO 30
    #define SWITCH 31
    #define CASE 32
    #define DEFAULT 33
    #define BREAK 34
    #define CONTINUE 35
    #define RETURN 36
    #define PRINTF 37
    #define VOID 38
    #define COLON 999

    /* IDENTIFIER */
    #define ID 39

    /* CONSTANT */
    #define INT_CONST 40
    #define FLOAT_CONST 41
    #define CHAR_CONST 50
    #define SIGNED_CONST 51
    #define STRING_CONST 52

    /* OTHER */
    #define SLCOMMENT 43
    #define MLCOMMENT_S 44
    #define MLCOMMENT_E 45
    #define ERROR 46
    #define MAIN 47
    #define HEADER 48

    #define TYPE_SPEC 53

    #define ARR 54
    #define FUNC 55
    #define ARR2D 56
    #define DQ 57
    #define HASH 58


    /* GLOBAL VARIABLE */
    int line_no = 1;
    int scan, slcline=0, mlc=0, mlcline=0, dq=0, dqline=0;

    struct node{
        char lexeme[100];
        char  token[100];
        int line_no;
        struct node *next;
    };

    struct ll{
        struct node *head;
        struct node *tail;
        int count;
    };

    struct ll *main_list = NULL;
%}

alpha [a-zA-Z]
digit [0-9]
und [_]
space [ ]
tab [\t]
line [\n]
at [@]
char \'.\'
string "@"

%%
{space}* {}
{tab}* {}
{string} return STRING_CONST;
{char} return CHAR_CONST;
{line} {line_no++;}


break return BREAK;
case return CASE;
default return DEFAULT;
char return CHAR;
continue return CONTINUE;
else return ELSE;
float return FLOAT;
for return FOR;
if return IF;
int return INT;
return return RETURN;
switch return SWITCH;
void return VOID;
while return WHILE;

printf return PRINTF;

{alpha}({alpha}|{digit}|{und})* return ID;

[+-][0-9]{digit}*(\.{digit}+)? return SIGNED_CONST;

\/\/.* return SLCOMMENT;
"/*" return MLCOMMENT_S;
"*/" return MLCOMMENT_E;

">" return GT;
"<" return LS;
"<=" return LE;
">=" return GE;
"==" return EQ;
"!=" return NE;
"&&" return LAND;
"\|\|" return LOR;
"!" return NOT;
"=" return ASSIGN;
"+" return PLUS;
"-" return MINUS;
"*" return MULT;
"/" return DIV;
"%" return MOD;

";" return SEMICOLON;
":" return COLON;
"," return COMMA;

"#".* {;}

{digit}+ return INT_CONST;
{digit}+\.{digit}+ return FLOAT_CONST;

"%d"|"%f"|"%s"|"%c" return TYPE_SPEC;
"\"" return DQ;
"(" return LPAREN;
")" return RPAREN;
"{" return LBRACE;
"}" return RBRACE;
"[" return LBRACKET;
"]" return RBRACKET;

{alpha}({alpha}|{digit}|{und})*\[{digit}*\] return ARR;
{alpha}({alpha}|{digit}|{und})*\[{digit}*\]\[{digit}*\] return ARR2D;
{alpha}({alpha}|{digit}|{und})*\(({digit}*"."{digit}*|{alpha}|{digit}|{und}|{space})*\) {
    inserttoLL("FUNC", yytext, line_no);
    REJECT;
    return FUNC;}
%%

struct node *create_node(char *lexeme, char *token, int line_no){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->lexeme, lexeme);
    temp->line_no = line_no;
    strcpy(temp->token, token);
    temp->next = NULL;
    return temp;
}

void inserttoLL(char* lexeme, char* token, int line_no){
    struct node *temp = create_node(lexeme, token, line_no);
    if(main_list->head == NULL){
        main_list->head = temp;
        main_list->tail = temp;
    }
    else{
        main_list->tail->next = temp;
        main_list->tail = temp;
    }
    main_list->count++;
}

void dis(){
    struct node *temp = main_list->head;
    printf("--------------------------------------------------------------------\n");
    printf("Line No.\tLexeme\t\t\tToken\n");
    printf("--------------------------------------------------------------------\n");
    while(temp != NULL){
        printf("%d\t\t%s\t\t\t%s\n", temp->line_no, temp->lexeme, temp->token);
        temp = temp->next;
    }
    printf("--------------------------------------------------------------------\n");
}

int main(int argc, char *argv[]){
    main_list = (struct ll *)malloc(sizeof(struct ll));
    main_list->head = NULL;
    main_list->tail = NULL;
    main_list->count = 0;
    yyin = fopen(argv[1], "r");
    scan = yylex();
    while(scan){
        /*
        if(line_no==slcline){
            scan = yylex();
            continue;
        }
        */
        if(line_no!=dqline && dqline!=0){
            if(dq%2!=0){
                printf("incomplete string");
            }
            dq = 0;
        }
        if((scan>=26 && scan<=36 ||scan==38|| scan==1 || scan == 2 || scan==3)&& mlc ==0){
            inserttoLL("KEYWORD",yytext,line_no);
        }
        if(scan==39 && mlc==0){
            inserttoLL("IDENTIFIER",yytext,line_no);
        }
        if(scan==43){
            //inserttoLL("SINGLE LINE COMMENT",yytext,line_no);
            //slcline = line_no;
        }
        if(scan == 44 && mlc == 0){
            //inserttoLL("MULTI LINE COMMENT START",yytext,line_no);
            mlcline = line_no;
            mlc = 1;
        }
        if(scan==45 && mlc == 0){
            printf("unmatched comment");
        }
        if(scan == 45 && mlc == 1){
            mlc = 0;
            //inserttoLL("MULTI LINE COMMENT END",yytext,line_no);
        }
        if(((scan>=4 && scan<=17) || scan==49) && mlc == 0){
            inserttoLL("OPERATOR",yytext,line_no);
        }
        if(((scan>=18 && scan<=25) || scan==57 || scan ==58 || scan == 999) && mlc == 0){
            if(scan==57){
                dq++;
                dqline = line_no;
            }
            inserttoLL("SPECIAL SYMBOL",yytext,line_no);
        }
        if(mlc == 0){
            switch(scan){
                case 37:
                    inserttoLL("PRE_DEFINED_FUNCTION", yytext, line_no);
                    break;
                case 40:
                    inserttoLL("INTEGER CONSTANT", yytext, line_no);
                    break;
                case 41:
                    inserttoLL("FLOAT CONSTANT", yytext, line_no);
                    break;
                case 47:
                    inserttoLL("IDENTIFIER", yytext, line_no);
                    break;
                case 48:
                    inserttoLL("HEADER", yytext, line_no);
                    break;
                case 50:
                    inserttoLL("CHARACTER CONSTANT", yytext, line_no);
                    break;
                case 51:
                    inserttoLL("SIGNED CONSTANT", yytext, line_no);
                    break;
                case 52:
                    inserttoLL("STRING CONSTANT", yytext, line_no);
                    break;
                case 53:
                    inserttoLL("TYPE_SPEC", yytext, line_no);
                    break;
                case 54:
                    inserttoLL("1D ARRAY", yytext, line_no);
                    break;
                case 56:
                    inserttoLL("2D ARRAY", yytext, line_no);
                    break;
                case 55:
                    inserttoLL("FUNCTION", yytext, line_no);
                    break;

            }
        }
        scan = yylex();
    }
    if(mlc==1){
        printf("unmatched comment starting at line %d", mlcline);
    }
    dis();
    return 0;
}















