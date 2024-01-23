%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    #include<string.h>
    #include<ctype.h>
    extern FILE *yyin;
    
    int label = 0;
    int tempVariable = 0;

    char* genTempVariable(int x){
        char* temp = (char*)malloc(sizeof(char)*10);
        temp[0] = 'T';
        snprintf(temp, 10, "T%d", x);
        return temp;
    }

    int gencode(char* lhs, char* op, char* rhs){
        printf("T%d = %s %s %s\n", tempVariable, lhs, op, rhs);
        return tempVariable;
    }

    void assignment(char* lhs, char* rhs){
        //printf("in assign function");
        printf("%s = %s\n", lhs, rhs);
    }

%}

%union{
    char* lexeme;
}
%left <lexeme> ASSIGN
%left <lexeme> PLUS MINUS
%left <lexeme> MUL DIV MOD
%token ARR ARR2D SIGNED_CONST HASH DQ TYPE_SPEC ARR_E
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COMMA COLON
%token IF ELSE WHILE FOR SWITCH CONTINUE BREAK RETURN PRINTF DEFAULT CASE
%token <lexeme> INT FLOAT CHAR VOID GE LE NE LAND LOR NOT EQ LT GT
%token <lexeme> ID INT_CONST FLOAT_CONST CHAR_CONST FUNC_NAME STRING_CONST
%type <lexeme> CONST Type DECL EXPR FACTOR TERM COMP_OP FUNC_DECL Para_List
%%

S : BEGIN

BEGIN : FUNC_DECL BEGIN
      | FUNC_DECL


Type : INT {$$ = $1;}
    | FLOAT {$$ = $1;}
    | CHAR {$$ = $1;}
    | VOID {$$ = $1;}
    ;

FUNC_DECL: Type FUNC_NAME LPAREN Para_List RPAREN LBRACE Stmt_Lis RBRACE 
        | Type FUNC_NAME LPAREN RPAREN LBRACE Stmt_Lis RBRACE

Para_List: Para_List COMMA Type ID 
        | Type ID

Stmt_Lis: Stmt Stmt_Lis
        | Stmt
        | LBRACE Stmt_Lis RBRACE 
        | LBRACE Stmt_Lis RBRACE Stmt_Lis

Stmt: PRINT 
    | RTRN_STMT 
    | FUNC_CALL 
    | BRK 
    | ARR_DECL
    | {printf("\nL%d: \n", ++label);} FOR_STMT 
    | {printf("\nL%d: \n", ++label);} IF_STMT 
    | {printf("\nL%d: \n", ++label);} WHILE_STMT 
    | EXPR 
    | SWITCH_STMT 
    | Assgn SEMICOLON 
    | DECL SEMICOLON
    | SEMICOLON

FOR_STMT: FOR LPAREN DECL SEMICOLON EXPR SEMICOLON Assgn RPAREN LBRACE Stmt_Lis {printf("\niftrue %s goto L%d\n", $5, label);} RBRACE
        | FOR LPAREN Assgn SEMICOLON EXPR SEMICOLON Assgn RPAREN LBRACE Stmt_Lis {printf("\niftrue %s goto L%d\n", $5, label);} RBRACE
        | FOR LPAREN SEMICOLON EXPR SEMICOLON Assgn RPAREN LBRACE Stmt_Lis {printf("\niftrue %s goto L%d\n", $4, label);} RBRACE


SWITCH_STMT : SWITCH LPAREN ID RPAREN LBRACE CASE_STMT RBRACE

CASE_STMT : CASE INT_CONST COLON Stmt_Lis CASE_STMT
        | DEFAULT COLON Stmt_Lis

BRK: CONTINUE SEMICOLON 
        | BREAK SEMICOLON

WHILE_STMT : WHILE LPAREN EXPR RPAREN LBRACE Stmt_Lis {printf("\niftrue %s goto L%d\n", $3, label);} RBRACE        


Assgn: ID ASSIGN EXPR ASSGN_TAIL {assignment($1, $3);}
ASSGN_TAIL : COMMA ID ASSIGN EXPR ASSGN_TAIL {assignment($2, $4);} 
            |
            ; 

IF_STMT : MAT | UNMAT

MAT : IF LPAREN EXPR RPAREN LBRACE Stmt_Lis RBRACE

UNMAT : IF LPAREN EXPR RPAREN LBRACE Stmt_Lis RBRACE ELSE LBRACE Stmt_Lis RBRACE

PRINT : PRINTF LPAREN STRING_CONST RPAREN SEMICOLON
      | PRINTF LPAREN STRING_CONST COMMA VAR_LIST RPAREN SEMICOLON

FUNC_CALL : Type ID ASSIGN FUNC_NAME LPAREN MIXED_LIST RPAREN SEMICOLON
          | Type ID ASSIGN FUNC_NAME LPAREN RPAREN SEMICOLON
          | FUNC_NAME LPAREN RPAREN SEMICOLON
          | FUNC_NAME LPAREN MIXED_LIST RPAREN SEMICOLON
          | ID ASSIGN FUNC_NAME LPAREN RPAREN SEMICOLON
          | ID ASSIGN FUNC_NAME LPAREN MIXED_LIST RPAREN SEMICOLON

VAR_LIST : ID 
         | ID COMMA VAR_LIST

RTRN_STMT : RETURN ID SEMICOLON
       | RETURN CONST SEMICOLON
       | RETURN SEMICOLON

ARR_DECL : Type ARR SEMICOLON
         | Type ARR2D SEMICOLON

CONST_LIST : INT_LIST | FLOAT_LIST | CHAR_LIST

MIXED_LIST : ID COMMA MIXED_LIST 
            | CONST COMMA MIXED_LIST 
            | ID 
            | CONST

CONST_LIST2 : LBRACE CONST_LIST RBRACE
            | LBRACE CONST_LIST RBRACE COMMA CONST_LIST2

INT_LIST : INT_CONST | INT_CONST COMMA INT_LIST

FLOAT_LIST : FLOAT_CONST | FLOAT_CONST COMMA FLOAT_LIST

CHAR_LIST : CHAR_CONST | CHAR_CONST COMMA CHAR_LIST

DECL : Type ID ASSIGN EXPR DECL_TAIL {assignment($2, $4);}
        |Type ID DECL_TAIL 
        ;

DECL_TAIL : COMMA ID DECL_TAIL
           | COMMA ID ASSIGN EXPR DECL_TAIL {assignment($2, $4);}
           |
           ;

EXPR : EXPR COMP_OP TERM{
        int a = gencode($1, $2 , $3);
        char* tempVar = genTempVariable(a);
        $$ = tempVar;
        tempVariable++;
    }   
       |TERM
       ;

COMP_OP :  LT {$$ = $1;}
         | LE {$$ = $1;} 
         | GT {$$ = $1;}
         | GE {$$ = $1;}
         | LOR {$$ = $1;}
         | LAND {$$ = $1;}
         | NE {$$ = $1;}
         | EQ {$$ = $1;}
        ;

TERM : TERM PLUS FACTOR {
        int a = gencode($1, $2 , $3);
        char* tempVar = genTempVariable(a);
        $$ = tempVar;
        tempVariable++;
    }
      |TERM MINUS FACTOR {
        int a = gencode($1, $2 , $3);
        char* tempVar = genTempVariable(a);
        $$ = tempVar;
        tempVariable++;
      }
      |TERM MUL FACTOR {
        int a = gencode($1, $2 , $3);
        char* tempVar = genTempVariable(a);
        $$ = tempVar;
        tempVariable++;
      }
      |TERM DIV FACTOR{
        int a = gencode($1, $2 , $3);
        char* tempVar = genTempVariable(a);
        $$ = tempVar;
        tempVariable++;
      }
      |TERM MOD FACTOR{
        int a = gencode($1, $2 , $3);
        char* tempVar = genTempVariable(a);
        $$ = tempVar;
        tempVariable++;
      }
      |FACTOR {$$ = $1;}
      ;
      
FACTOR : LPAREN EXPR RPAREN {$$ = $2;}
        |ID {$$ = $1;}
        |CONST {$$ = $1;}
        ;
       
CONST : INT_CONST {$$ = $1;}
      |FLOAT_CONST {$$ = $1;}
      |CHAR_CONST {$$ = $1;}
      |STRING_CONST {$$ = $1;}


%%

int yyerror(char *s){
    printf("Error: %s\n", s);
    return 0;
}
int main(int argc , char *argv[]){
    //printf("hello");
    yyin = fopen(argv[1], "r");
    if(yyparse()==0){
        printf("success\n");
    }
}