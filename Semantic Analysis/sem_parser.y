%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    #include<string.h>
    #include<ctype.h>
    #include<limits.h>
    extern FILE *yyin;
    #include "table.c"

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
    int mlc;

        
    int list_c = 0;
    char *listType[100];
    char *returnType_func = "VOID";
    
    void insertEntry(char* t);

%}
%union{
    struct{
        char *lexeme;
        float val;
    }n;
}
%left PLUS MINUS
%left MUL DIV MOD
%token <n> LOR LAND EQ NE LT LE GT GE NOT ASSIGN ARR
%token <n> ID STRING_CONST INT_CONST FLOAT_CONST CHAR_CONST SIGNED_CONST FUNC_NAME
%type <n> Const Type Decl Expr FACTOR TERM COMP_OP Func_Decl Para_List 
%token INT FLOAT CHAR 
%token IF ELSE WHILE FOR RETURN BREAK CONTINUE CASE DEFAULT SWITCH
%token VOID MAIN PRINTF 
%token SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token HASH DQ COLON
%token ARR2D ARR_E TYPE_SPEC

%%

S: begin {printf("reaching here\n");}
    ;

begin : Func_Decl begin |  
        Func_Decl {printf("here as well\n");}
        ;

Type : INT {$$.lexeme = "INT";}
    | FLOAT {$$.lexeme = "FLOAT";}
    | CHAR {$$.lexeme = "CHAR";}
    | VOID {$$.lexeme = "VOID";}
    ;

Func_Decl : Type FUNC_NAME LPAREN Para_List {insertFunc($2.lexeme,$1.lexeme); updateFunc((int)$4.val, dec); decCounter = 0;} RPAREN LBRACE Stmt_List RBRACE {if(strcmp($1.lexeme,returnType_func)!=0){printf("ERROR : Unexpected Return Type");exit(0);}print_Id_Table(); id_count = 0;returnType_func = "VOID";}
          | Type FUNC_NAME LPAREN {insertFunc($2.lexeme,$1.lexeme);} RPAREN LBRACE Stmt_List RBRACE {printf("return %s return Type %s\n",$1.lexeme,returnType_func);if((strcmp($1.lexeme,returnType_func)!=0)){printf("ERROR : Unexpected Return Type");exit(0);}print_Id_Table();id_count = 0;returnType_func = "VOID";}
        ;

Para_List : Para_List COMMA Type ID {$$.val = $1.val + 1; insertID($4.lexeme, $3.lexeme); dec[decCounter].type = $3.lexeme; dec[decCounter].name = $4.lexeme; decCounter++;}
          | Type ID {$$.val = 1; insertID($2.lexeme, $1.lexeme); dec[decCounter].type = $1.lexeme; dec[decCounter].name = $2.lexeme; decCounter++;}


Stmt_List : LBRACE Stmt_List RBRACE |
             LBRACE Stmt_List RBRACE Stmt_List 
             | Stmt Stmt_List 
             | Stmt 
             ;
    ;

Stmt : Print | Return {} | Func_Call | Brk_cnt | Arr_Decl | For_stmt | Expr | While_stmt | If_stmt | Assgn SEMICOLON | Switch_stmt | Decl SEMICOLON | SEMICOLON 
    ;

Switch_stmt : SWITCH LPAREN ID RPAREN LBRACE Case_stmt RBRACE {if(strcmp(findIdType($3.lexeme),"INT")!=0){printf("ERROR: Unexpected variable type passed in Switch\n"); exit(0);}}

Case_stmt : CASE INT_CONST COLON Stmt_List Case_stmt 
    | DEFAULT COLON Stmt_List

Brk_cnt : CONTINUE SEMICOLON | BREAK SEMICOLON 
    ;

For_stmt : FOR LPAREN Assgn SEMICOLON Expr SEMICOLON Assgn RPAREN LBRACE Stmt_List RBRACE
         | FOR LPAREN Decl SEMICOLON Expr SEMICOLON Assgn RPAREN LBRACE Stmt_List RBRACE 
         | FOR LPAREN SEMICOLON Expr SEMICOLON Assgn RPAREN LBRACE Stmt_List RBRACE
         ;
         
While_stmt : WHILE LPAREN Expr RPAREN LBRACE Stmt_List RBRACE
    ;

Expr : Expr COMP_OP TERM {if(strcmp($1.lexeme, $3.lexeme)!=0){
                                print_Id_Table();
                                printf("ERROR: Unexpected type for expression\n");
                                exit(0);
                            }
                            $$.lexeme = $1.lexeme;
                            $$.val = (float)comparator($1.val,$3.val,$2.lexeme);
                         }
    | TERM {$$.lexeme = $1.lexeme; $$.val = $1.val;}
    ;

COMP_OP : GT {$$.lexeme = $1.lexeme;}
    | LT {$$.lexeme = $1.lexeme;}
    | GE {$$.lexeme = $1.lexeme;}
    | LE {$$.lexeme = $1.lexeme;}
    | NE {$$.lexeme = $1.lexeme;}
    | LAND {$$.lexeme = $1.lexeme;}
    | LOR {$$.lexeme = $1.lexeme;}
    | NOT {$$.lexeme = $1.lexeme;}
    | EQ {$$.lexeme = $1.lexeme;}
    ;

TERM : TERM PLUS FACTOR {termsolve1($1.lexeme,$3.lexeme,$$.lexeme,$$.val,$1.val,$3.val);}
    | TERM MINUS FACTOR {termsolve2($1.lexeme,$3.lexeme,$$.lexeme,$$.val,$1.val,$3.val);}
    | TERM MUL FACTOR {termsolve3($1.lexeme,$3.lexeme,$$.lexeme,$$.val,$1.val,$3.val);}
    | TERM DIV FACTOR {termsolve4($1.lexeme,$3.lexeme,$$.lexeme,$$.val,$1.val,$3.val);}
    | TERM MOD FACTOR {termsolve5($1.lexeme,$3.lexeme,$$.lexeme,$$.val,$1.val,$3.val);}
    | FACTOR {termsolve6($$.lexeme,$1.lexeme);}
    ;

FACTOR : LPAREN Expr RPAREN {$$.lexeme = $2.lexeme; $$.val = $2.val;}
    | ID{bool found = true;
             for(int i = 0; i<id_count; i++){
                if(strcmp(id_table[i].name,$1.lexeme)==0){
                    found = false;
                    $$.lexeme = id_table[i].type;
                    $$.val = id_table[i].val;
                    break;
                }
            }
            if(found){  
                printf("ERROR: Undeclared variable %s\n", $1.lexeme);
                exit(0);
            }
        }
    | Const { $$.lexeme = $1.lexeme; $$.val = $1.val;}
    ;

Assgn : ID ASSIGN Expr ASSGN_TAIL {assign1($1.lexeme,$3.lexeme,$3.val);}
        | ARR LBRACKET INT_CONST RBRACKET ASSIGN Expr COMMA Assgn   {assign2($1.lexeme,$3.lexeme,$3.val);}
      | ARR LBRACKET INT_CONST RBRACKET ASSIGN Expr { assign3($1.lexeme,$3.lexeme,$3.val); }
      | ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET ASSIGN Expr COMMA Assgn {assign4($1.lexeme,$3.lexeme,$3.val,$6.val);}
      | ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET ASSIGN Expr { assign5($1.lexeme,$3.lexeme,$3.val,$6.val); }

ASSGN_TAIL :  COMMA ID ASSIGN Expr ASSGN_TAIL{typeCheck($2.lexeme,$4.lexeme); updateID($2.lexeme,$4.val);}
    |
    ;

Decl : Type ID ASSIGN Expr DECL_TAIL {declsolve1($$.lexeme,$1.lexeme,$2.lexeme,$4.lexeme,$4.val);}
    | Type ID DECL_TAIL {declsolve2($$.lexeme,$1.lexeme,$2.lexeme);}
    ;

DECL_TAIL : COMMA ID DECL_TAIL {decltail1($2.lexeme);} 
    | COMMA ID ASSIGN Expr DECL_TAIL {decltail2($2.lexeme,$4.lexeme,$4.val);}
    |
    ;

If_stmt : MAT | UNMAT
    ;   

MAT : IF LPAREN Expr RPAREN LBRACE Stmt_List RBRACE
    ;

UNMAT : IF LPAREN Expr RPAREN LBRACE Stmt_List RBRACE ELSE LBRACE Stmt_List RBRACE
    ;

Return : RETURN ID SEMICOLON {returnType_func = findIdType($2.lexeme);printf("return type :%s\n",returnType_func);}
        | RETURN Const SEMICOLON {returnType_func = $2.lexeme; }
        | RETURN SEMICOLON
    ;

Const : INT_CONST {$$.val = $1.val;$$.lexeme = "INT";}
    | FLOAT_CONST {$$.val = $1.val;$$.lexeme = "FLOAT";}
    | CHAR_CONST {$$.val = $1.val;$$.lexeme = "CHAR";}
    | ARR LBRACKET INT_CONST RBRACKET {if($3.val < 0 || !findArrSize($1.lexeme, 0, $3.val)){printf("ERROR: Array %s out of bounds\n", $1.lexeme); exit(0);} $$.lexeme = findArrType($1.lexeme); $$.val = findArrVal($1.lexeme, 0, $3.val);}
    | ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET {if($3.val < 0 || $6.val < 0 || !findArrSize($1.lexeme, $3.val, $6.val)){printf("ERROR: Array %s out of bounds\n", $1.lexeme); exit(0);} $$.lexeme = findArrType($1.lexeme); $$.val = findArrVal($1.lexeme, $3.val, $6.val);}
    | SIGNED_CONST 
    ;

Print : PRINTF LPAREN STRING_CONST RPAREN SEMICOLON 
    | PRINTF LPAREN STRING_CONST COMMA Var_List RPAREN SEMICOLON {
                                                    printsolve($3.lexeme,listType[list_c - 1],list_c);
                                                    }
    ;

Var_List : ID {listType[list_c] = findIdType($1.lexeme); list_c++;}
             | ID COMMA Var_List {listType[list_c] = findIdType($1.lexeme); list_c++;}

Func_Call : Type ID ASSIGN FUNC_NAME LPAREN Mixed_List RPAREN SEMICOLON {
                                                            funccall1($4.lexeme,list_c,listType,$1.lexeme);
                                                        }
        | Type ID ASSIGN FUNC_NAME LPAREN RPAREN SEMICOLON {
                                                funccall2($4.lexeme,$2.lexeme,$1.lexeme,list_c);
                                                }
        | FUNC_NAME LPAREN RPAREN SEMICOLON {findFunc($1.lexeme);}
        | FUNC_NAME LPAREN Mixed_List RPAREN SEMICOLON {
                                            funccall3($1.lexeme,list_c,listType);
                                            }
                                            
        | ID ASSIGN FUNC_NAME LPAREN RPAREN SEMICOLON {
                                                funccall4($1.lexeme,$3.lexeme,list_c);
                                            }
        | ID ASSIGN FUNC_NAME LPAREN Mixed_List RPAREN SEMICOLON {
                                                funccall5($1.lexeme,$3.lexeme,list_c);
                                            }
        ;

Mixed_List: ID COMMA Mixed_List {listType[list_c] = findIdType($1.lexeme); list_c++;}
    | Const COMMA Mixed_List {listType[list_c] = $1.lexeme; list_c++;}
    | ID {listType[list_c] = findIdType($1.lexeme); list_c++;}
    | Const {listType[list_c] = $1.lexeme; list_c++;}

Arr_Decl : Type ARR LBRACKET INT_CONST RBRACKET SEMICOLON {insertArr($2.lexeme, $1.lexeme, 0, $4.val);}
         /* | TYPE ARR '=' '{' CONST_LIST '}' ';'
         | TYPE ARR_E '=' '{' CONST_LIST '}' ';' */
         | Type ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET SEMICOLON {insertArr($2.lexeme, $1.lexeme, $4.val, $7.val);}
         /* | TYPE ARR2 '=' '{' CONST_LIST2 '}' ';' */

Const_List : int_list | float_list | char_list
    ;

Const_List2 : LBRACE Const_List RBRACE | LBRACE Const_List RBRACE COMMA Const_List2
    ;

int_list : INT_CONST COMMA int_list | INT_CONST 
    ;

float_list : FLOAT_CONST COMMA float_list | FLOAT_CONST 
    ;

char_list : CHAR_CONST COMMA char_list | CHAR_CONST
    ;

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

int check_mlc()
{
    if(mlc == 0)
        return 1;
    return 0;
}

void set_mlc()
{
    mlc = 1;
    return;
}

void reset_mlc()
{
    mlc = 0;
    return;
}



int main(int argc , char *argv[]){
    yyin = fopen(argv[1],"r");
    main_list = (struct ll *)malloc(sizeof(struct ll));
    main_list->head = NULL;
    main_list->tail = NULL;
    main_list->count = 0;
    mlc = 0;
    yyparse();
    dis();
}

void yyerror(){
    printf("Invalid statement\n");
}