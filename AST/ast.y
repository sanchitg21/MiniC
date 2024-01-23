%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    #include<string.h>
    #include<ctype.h>

    #include "temp.c"
    extern FILE *yyin;
    int ex (nodeType *p, int flag);
    nodeType* opr(int oper, int nops, ...);
    nodeType* id(char *identifier);
    nodeType* con(char* value);

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

%union
{
    int ival;
    nodeType *nPtr;
    char string[100];
}

%left ASSIGN
%left LOR
%left LAND
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left MUL DIV MOD 
%left NOT

%token NUL GLOBAL QM FUNC_C
%type<nPtr> Const Decl DECL_TAIL Stmt Stmt_List Func_Decl For_stmt begin FACTOR TERM Expr Assgn
%type<nPtr> Para Para_List While_stmt If_stmt MAT Print Var_List Mixed_List Func_Call Brk_cnt Return Switch_stmt Case_stmt ARR_DECL
%token<string> ID INT_CONST FLOAT_CONST CHAR_CONST FUNC_NAME STRING_CONST ARR ARR_D
%token SIGNED_CONST
%token INT FLOAT CHAR 
%token IF ELSE WHILE FOR RETURN BREAK CONTINUE CASE DEFAULT SWITCH
%token VOID PRINTF
%token COLON
%token SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token HASH DQ
%token ARR2D ARR_E TYPE_SPEC

%%

S: begin {printf("reaching here\n"); ex($1, 0);}
    ;

begin : Func_Decl begin  {$$ = opr(GLOBAL, 2, $1, $2);}|  
        Func_Decl {printf("here as well\n");$$ = $1;}
        ;

Type : INT | FLOAT | CHAR | VOID 
    ;

Func_Decl : Type FUNC_NAME LPAREN Para_List RPAREN LBRACE Stmt_List RBRACE {$$ = opr(FUNC_NAME, 3, id($2), $4, $7);}
          | Type FUNC_NAME LPAREN RPAREN LBRACE Stmt_List RBRACE {$$ = opr(FUNC_NAME, 3, id($2), opr(NUL, 0), $6);}
        ;

Para_List : Para_List COMMA Para {$$ = opr(COMMA, 2, $1, $3);}| Para {$$ = $1;} 
    ;

Para : Type ID {$$ = id($2);}
    ;

Stmt_List : Stmt Stmt_List {$$ = opr(SEMICOLON, 2, $1, $2);}
            | Stmt {$$ = $1;}
            | LBRACE Stmt_List RBRACE {$$ = $2;}
            | LBRACE Stmt_List RBRACE Stmt_List {$$ = opr(SEMICOLON, 2, $2, $4);}
    ;

Stmt : Print {$$ = $1;}
        |Switch_stmt
        | Return {$$ = $1;}
        | Func_Call {$$ = $1;}
        | Brk_cnt {$$ = $1;}
        | ARR_DECL {$$ = $1;}
        | For_stmt {$$ = $1;}
        | While_stmt {$$ = $1;}
        | If_stmt {$$ = $1;}
        | Assgn SEMICOLON {$$ = $1;}
        | Decl SEMICOLON {$$ = $1;}
        | SEMICOLON {$$ = opr(NUL, 0);}
    ;


Brk_cnt : CONTINUE SEMICOLON {$$ = opr(CONTINUE, 0);} 
        | BREAK SEMICOLON {$$ = opr(BREAK, 0);} 
    ;

For_stmt : FOR LPAREN Assgn SEMICOLON Expr SEMICOLON Assgn RPAREN LBRACE Stmt_List RBRACE {$$ = opr(FOR, 4, $3, $5, $7, $10);}
         | FOR LPAREN Decl SEMICOLON Expr SEMICOLON Assgn RPAREN LBRACE Stmt_List RBRACE {$$ = opr(FOR, 4, $3, $5, $7, $10);}
         | FOR LPAREN SEMICOLON Expr SEMICOLON Assgn RPAREN LBRACE Stmt_List RBRACE {{$$ = opr(FOR, 4, opr(NUL, 0), $4, $6, $9);}}
         ;
         
While_stmt : WHILE LPAREN Expr RPAREN LBRACE Stmt_List RBRACE {$$ = opr(WHILE, 2, $3, $6);}
    ;

Switch_stmt : SWITCH LPAREN ID RPAREN LBRACE Case_stmt RBRACE {$$ = opr(SWITCH, 2, id($3), $6);}
    ;

Case_stmt : CASE INT_CONST COLON Stmt_List Case_stmt {$$ = opr(CASE, 3, con($2), $4, $5);}
    | DEFAULT COLON Stmt_List {$$ = opr(DEFAULT, 1, $3);}

Expr : Expr LT TERM {$$ = opr(LT, 2, $1, $3);}
    |Expr GT TERM   {$$ = opr(GT, 2, $1, $3);}
    |Expr GE TERM   {$$ = opr(GE, 2, $1, $3);}
    |Expr LE TERM   {$$ = opr(LE, 2, $1, $3);}
    |Expr NE TERM   {$$ = opr(NE, 2, $1, $3);}
    |Expr LAND TERM {$$ = opr(LAND, 2, $1, $3);}
    |Expr LOR TERM  {$$ = opr(LOR, 2, $1, $3);}
    |Expr EQ TERM   {$$ = opr(EQ, 2, $1, $3);}
    | TERM {$$ = $1;}
    ;

TERM : TERM PLUS FACTOR {$$ = opr(PLUS, 2, $1, $3);}
    | TERM MINUS FACTOR {$$ = opr(MINUS, 2, $1, $3);}
    | TERM MUL FACTOR   {$$ = opr(MUL, 2, $1, $3);}
    | TERM DIV FACTOR   {$$ = opr(DIV, 2, $1, $3);}    
    | FACTOR
    ;

FACTOR : LPAREN Expr RPAREN {$$ = $2;}
        | ID {$$ = id($1);}
        | Const {$$ = $1;}
    ;

Assgn : ID ASSIGN Expr COMMA Assgn {$$ = opr(COMMA, 2, opr(ASSIGN, 2, id($1), $3), $5);}
        | Expr {$$ = $1;}
        | ID ASSIGN Expr {$$ = opr(ASSIGN, 2, id($1), $3);}
        | Expr COMMA Assgn {$$ = opr(COMMA, 2, $1, $3);}
        | ARR LBRACKET INT_CONST RBRACKET ASSIGN Expr COMMA Assgn {$$ = opr(',', 2, opr('=', 2, opr(ARR, 3, id($1), opr(NUL, 0), con($3)), $6), $8);}
      | ARR LBRACKET INT_CONST RBRACKET ASSIGN Expr {$$ = opr('=', 2, opr(ARR, 3, id($1), opr(NUL, 0), con($3)), $6);}
      | ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET ASSIGN Expr COMMA Assgn {$$ = opr(',', 2, opr('=', 2, opr(ARR, 3, id($1), con($3), con($6)), $9), $11);} 
      | ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET ASSIGN Expr {$$ = opr('=', 2, opr(ARR, 3, id($1), con($3), con($6)), $9);}

Decl : Type DECL_TAIL {$$ = $2;}
    ;

DECL_TAIL : ID ASSIGN Expr {$$ = opr(ASSIGN, 2, id($1), $3);}
            | ID ASSIGN Expr COMMA DECL_TAIL {$$ = opr(COMMA,2,opr(ASSIGN, 2, id($1), $3),$5);} 
            | ID {$$ = id($1);}
            | ID COMMA DECL_TAIL {$$ = opr(COMMA, 2, id($1), $3);}
    ;

If_stmt : IF LPAREN Expr RPAREN LBRACE Stmt_List RBRACE {$$ = opr(IF, 2, $3, $6);}
        | IF LPAREN Expr RPAREN LBRACE Stmt_List RBRACE ELSE LBRACE Stmt_List RBRACE {$$ = opr(IF, 3, $3, $6, opr(ELSE, 1, $10));}
    ;   

Return : RETURN ID SEMICOLON {$$ = opr(RETURN, 1, id($2));}
        | RETURN Const SEMICOLON {$$ = opr(RETURN, 1, $2);}
        | RETURN SEMICOLON     {$$ = opr(RETURN, 1, opr(NUL, 0));}
    ;

Const : INT_CONST {$$ = con($1);} 
        | FLOAT_CONST {$$ = con($1);}
        | CHAR_CONST {$$ = con($1);}
        | ARR LBRACKET INT_CONST RBRACKET {$$ = opr(ARR, 3, id($1), opr(NUL,0), con($3));}
      | ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET {$$ = opr(ARR, 3, id($1), con($3), con($6));}
        | SIGNED_CONST 
    ;

Print : PRINTF LPAREN STRING_CONST RPAREN SEMICOLON {$$ = opr(PRINTF, 1, con($3));}
    | PRINTF LPAREN STRING_CONST COMMA Var_List RPAREN SEMICOLON {$$ = opr(PRINTF, 2, con($3), $5);}  
    ;

Var_List : ID {$$ = id($1);}
            | ID COMMA Var_List {$$ = opr(COMMA, 2, id($1), $3);}
    ;

Func_Call : Type ID ASSIGN FUNC_NAME LPAREN Mixed_List RPAREN SEMICOLON {$$ = opr(ASSIGN, 2, id($2), opr(FUNC_C, 2, id($4), $6));}
        | Type ID ASSIGN FUNC_NAME LPAREN RPAREN SEMICOLON {$$ = opr(ASSIGN, 2, id($2), opr(FUNC_C, 1, id($4)));}
        | FUNC_NAME LPAREN RPAREN SEMICOLON {$$ = opr(FUNC_C, 1, id($1));}
        | FUNC_NAME LPAREN Mixed_List RPAREN SEMICOLON {$$ = opr(FUNC_C, 2, id($1), $3);}
        | ID ASSIGN FUNC_NAME LPAREN RPAREN SEMICOLON {$$ = opr(ASSIGN, 2, id($1), opr(FUNC_C, 1, id($3)));}
        | ID ASSIGN FUNC_NAME LPAREN Mixed_List RPAREN SEMICOLON {$$ = opr(ASSIGN, 2, id($1), opr(FUNC_C, 2, id($3), $5));}
        ;

Mixed_List: ID COMMA Mixed_List {$$ = opr(COMMA, 2, id($1), $3);} 
        | Const COMMA Mixed_List   {$$ = opr(COMMA, 2, con($1), $3);}
        | ID   {$$ = id($1);}
        | Const {$$ = con($1);}

ARR_DECL : Type ARR LBRACKET INT_CONST RBRACKET SEMICOLON {$$ = opr(ARR, 3, id($2), opr(NUL, 0), con($4));}
         /* | TYPE ARR '=' '{' CONST_LIST '}' ';'
         | TYPE ARR_E '=' '{' CONST_LIST '}' ';' */
         | Type ARR LBRACKET INT_CONST RBRACKET LBRACKET INT_CONST RBRACKET SEMICOLON {$$ = opr(ARR, 3, id($2), con($4), con($7));}
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
    return 1;
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

nodeType *con(char *value)
{
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeCon;
	strcpy(p->con.value, value);
    printf("The copied value %s\n", p->con.value);
	return p;
}

nodeType *id(char *identifier) {
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeId;
	strcpy(p->id.name,identifier);
//	printf("The copied identifier %s\n", p->id.name);
	return p;
}

nodeType *opr(int oper, int nops, ...)
{
	va_list ap;
	nodeType *p;
	int i;
	/* allocate node, extending op array */
	if ((p = malloc(sizeof(nodeType) +(nops-1) * sizeof(nodeType *))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeOpr;
	p->opr.oper = oper;
	p->opr.nops = nops;
	va_start(ap, nops);
	for (i = 0; i < nops; i++)
		p->opr.op[i] = va_arg(ap, nodeType*);
	va_end(ap);
	return p;
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
    return 0;
}

void yyerror(){
    printf("Invalid statement\n");
    exit(0);
}

