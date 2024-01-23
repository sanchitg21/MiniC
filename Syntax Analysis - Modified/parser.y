%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    #include<string.h>
    #include<ctype.h>
    extern FILE *yyin;

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
%}

%left ASSIGN
%left LOR
%left LAND
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left MUL DIV MOD 
%left NOT
%token STRING_CONST INT_CONST FLOAT_CONST CHAR_CONST SIGNED_CONST
%token INT FLOAT CHAR 
%token IF ELSE WHILE FOR RETURN BREAK CONTINUE CASE DEFAULT SWITCH
%token VOID MAIN PRINTF
%token ID COLON
%token SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token HASH DQ
%token ARR ARR2D ARR_E FUNC TYPE_SPEC FUNC_NAME

%%

S: begin {printf("reaching here\n");}
    ;

begin : Func_Decl begin |  
        Func_Decl {printf("here as well\n");}
        ;

Type : INT | FLOAT | CHAR | VOID 
    ;

Func_Decl : Type FUNC_NAME LPAREN Para_List RPAREN LBRACE Stmt_List RBRACE 
          | Type FUNC_NAME LPAREN RPAREN LBRACE Stmt_List RBRACE
        ;

Para_List : Para_List COMMA Para | Para 
    ;

Para : Type ID 
    ;

Stmt_List : Stmt Stmt_List | Stmt | LBRACE Stmt_List RBRACE | LBRACE Stmt_List RBRACE Stmt_List
    ;

Stmt : Print |SWITCH_STMT| Return | Func_Call | Brk_cnt | Arr_Decl | For_stmt | Expr | While_stmt | If_stmt | Assgn SEMICOLON | Decl SEMICOLON | SEMICOLON 
    ;

SWITCH_STMT : SWITCH LPAREN ID RPAREN LBRACE CASE_STMT RBRACE

CASE_STMT : CASE INT_CONST COLON Stmt_List CASE_STMT
        | DEFAULT COLON Stmt_List


Brk_cnt : CONTINUE SEMICOLON | BREAK SEMICOLON 
    ;

For_stmt : FOR LPAREN Assgn SEMICOLON Expr SEMICOLON Assgn RPAREN LBRACE Stmt_List RBRACE
         | FOR LPAREN Decl SEMICOLON Expr SEMICOLON Assgn RPAREN LBRACE Stmt_List RBRACE 
         | FOR LPAREN SEMICOLON Expr SEMICOLON Assgn RPAREN LBRACE Stmt_List RBRACE
         ;
         
While_stmt : WHILE LPAREN Expr RPAREN LBRACE Stmt_List RBRACE
    ;

Expr : Expr COMP_OP TERM | TERM
    ;

COMP_OP : GT | LT | GE | LE | NE | LAND | LOR | NOT | EQ
    ;

TERM : TERM PLUS FACTOR | TERM MINUS FACTOR | TERM MUL FACTOR | TERM DIV FACTOR | FACTOR
    ;

FACTOR : LPAREN Expr RPAREN | ID | Const
    ;

Assgn : ID ASSIGN Expr ASSGN_TAIL
        | ARR LBRACKET INT_CONST RBRACKET ASSIGN Expr COMMA Assgn 
      | ARR LBRACKET INT_CONST RBRACKET ASSIGN Expr 
      | ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET ASSIGN Expr COMMA Assgn 
      | ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET ASSIGN
    ;

ASSGN_TAIL :  COMMA ID ASSIGN Expr ASSGN_TAIL |
    ;

Decl : Type ID DECL_TAIL
    ;

DECL_TAIL : COMMA ID DECL_TAIL | ASSIGN Expr DECL_TAIL |
    ;

If_stmt : MAT | UNMAT
    ;   

MAT : IF LPAREN Expr RPAREN LBRACE Stmt_List RBRACE
    ;

UNMAT : IF LPAREN Expr RPAREN LBRACE Stmt_List RBRACE ELSE LBRACE Stmt_List RBRACE
    ;

Return : RETURN ID SEMICOLON | RETURN Const SEMICOLON | RETURN SEMICOLON    
    ;

Const : INT_CONST | FLOAT_CONST | CHAR_CONST | SIGNED_CONST 
        | ARR LBRACKET INT_CONST RBRACKET 
    | ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET 
    ;

Print : PRINTF LPAREN STRING_CONST RPAREN SEMICOLON 
    | PRINTF LPAREN STRING_CONST COMMA Var_List RPAREN SEMICOLON
    ;

Var_List : ID | ID COMMA Var_List 
    ;

Func_Call : Type ID ASSIGN FUNC_NAME LPAREN Mixed_List RPAREN SEMICOLON
        | Type ID ASSIGN FUNC_NAME LPAREN RPAREN SEMICOLON
        | FUNC_NAME LPAREN RPAREN SEMICOLON
        | FUNC_NAME LPAREN Mixed_List RPAREN SEMICOLON
        | ID ASSIGN FUNC_NAME LPAREN RPAREN SEMICOLON
        | ID ASSIGN FUNC_NAME LPAREN Mixed_List RPAREN SEMICOLON
        ;

Mixed_List: ID COMMA Mixed_List | Const COMMA Mixed_List | ID | Const

Arr_Decl : Type ARR LBRACKET INT_CONST RBRACKET SEMICOLON
         /* | TYPE ARR '=' '{' CONST_LIST '}' ';'
         | TYPE ARR_E '=' '{' CONST_LIST '}' ';' */
         | Type ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET SEMICOLON 
         /* | TYPE ARR2 '=' '{' CONST_LIST2 '}' ';' *//*Type ARR SEMICOLON
        | Type ARR ASSIGN LBRACE Const_List RBRACE SEMICOLON
        | Type ARR_E ASSIGN LBRACE Const_List RBRACE SEMICOLON
		| Type ARR2D SEMICOLON
        | Type ARR2D ASSIGN LBRACE Const_List2 RBRACE SEMICOLON*/
        ;

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