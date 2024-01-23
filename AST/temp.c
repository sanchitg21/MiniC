#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#include <stdbool.h>
#include "y.tab.h"
int del = 1; /* distance of graph columns */
int eps = 3; /* distance of graph lines */
int flag = 0; // flag to print main initially
/* interface for drawing (can be replaced by "real" graphic using GD or other) */
void graphInit (void);
void graphFinish();
void graphBox (char *s, int *w, int *h);
void graphDrawBox (char *s, int c, int l);
void graphDrawArrow (int c1, int l1, int c2, int l2);
bool brk_cnt = true;
bool cont_cnt = true;
char *exprEvaluate(nodeType *p,int index);
char *addEvaluate(nodeType *p1,nodeType *p2, int index);
char *subEvaluate(nodeType *p1,nodeType *p2, int index);
char *mulEvaluate(nodeType *p1,nodeType *p2, int index);
char *divEvaluate(nodeType *p1,nodeType *p2, int index);
bool ltEvaluate(nodeType *p, int index);
bool gtEvaluate(nodeType *p, int index);
bool gtrEvaluate(nodeType *p, int index);
bool lteEvaluate(nodeType *p, int index);
bool eqeqEvaluate(nodeType *p, int index);
bool neEvaluate(nodeType *p, int index);
bool evaluate(nodeType *p,int index);
void printfEvaluate(nodeType *p, int index);
void funcEvaluate(nodeType *p, int index);
char *arrEvaluate(nodeType *p, int index);	

typedef struct id_sym{
    char *type;
    char *name;
    char *val;
	char *val2[100];
	int row_n;
	int col_n;
}id_sym;

typedef struct func_sym{
	char *type;
	char *name;
	char *val;
	// char *arg[100];
	// int arg_count;
	int fun_id_cnt;
	id_sym fun_id[1000];
	nodeType *body;
	
}func_sym;

int fun_IND = 0;
id_sym func_temp_table[100];
int id_count = 0;
id_sym id_table[1000];
func_sym func_table[1000];
int cnt = 0;
int func_count = 0;
/* recursive drawing of the syntax tree */
void exNode (nodeType *p, int c, int l, int *ce, int *cm);
/***********************************************************/
/* main entry point of the manipulation of the syntax tree */
int ex (nodeType *p, int f)
{
	flag = f;
	int rte, rtm;
	graphInit ();
	exNode (p, 0, 0, &rte, &rtm);
	evaluate(p,0);
	graphFinish();
	// print_Id_Table();
	// printFuncs();
	//printFuncTable();
	return 0;
}


void exNode( nodeType *p,  int c, int l, /* start column and line of node */  int *ce, int *cm /* resulting end column and mid of node */)
{
    printf("check\n");
	int w, h; /* node width and height */
	char *s; /* node text */
	int cbar; /* "real" start column of node (centred above subnodes)
	*/
	int k; /* child number */
	int che, chm; /* end column and mid of children */
	int cs; /* start column of children */
	char word[20]; /* extended node text */
	if (!p) return;
	strcpy (word, "???"); /* should never appear */
	s = word;
	switch(p->type) 
	{
		case typeCon: sprintf (word, "c[%s]", p->con.value); break;
		case typeId: sprintf (word, "id[%s]", p->id.name); break;
		case typeOpr:
		switch(p->opr.oper)
		{
			case FOR: s = "for"; 
            case WHILE: s = "while"; break;
            case IF: s = "if"; break;
            case NUL: s = "null"; break;
            case ELSE: s = "else"; break;
            case BREAK: s = "break"; break;
            case CONTINUE: s = "continue"; break;
            case RETURN: s = "return"; break;
            case PRINTF: s = "printf"; break;
            case FUNC_NAME: s = "func_name"; break;
            case FUNC_C: s = "func_call"; break;
            case SWITCH: s = "switch"; break;
            case CASE: s = "case"; break;
            case DEFAULT: s = "default"; break;
            case GLOBAL: s = "global"; break;
			case SEMICOLON: "[;]"; {if(flag == 0) {s = "main"; flag = 1;} else if(flag == 2) {s = "global"; flag = 1;} else {s = "[;]";} break;}
			case ASSIGN: s = "[=]"; break;
            case COMMA: s = "[,]"; break;
			case ARR: s = "array"; break;
			case PLUS: s = "[+]"; break;
			case MINUS: s = "[-]"; break;
			case MUL: s = "[*]"; break;
			case DIV: s = "[/]"; break;
			case LT: s = "[<]"; break;
			case GT: s = "[>]"; break;
			case COLON: s = "[:]"; break;
			case QM: s = "[?]"; break;
			case MOD: s = "[%]"; break;
			case GE: s = "[>=]"; break;
			case LE: s = "[<=]"; break;
			case NE: s = "[!=]"; break;
			case EQ: s = "[==]"; break;
            case LAND: s = "[&&]"; break;
            case LOR: s = "[||]"; break;
		}
	break;
	}
 	/* construct node text box */
	graphBox (s, &w, &h);
	cbar = c;
	*ce = c + w;
	*cm = c + w / 2;
	/* node is leaf */
	if (p->type == typeCon || p->type == typeId || p->opr.nops == 0) 
	{
		graphDrawBox (s, cbar, l);
		return;
	}

 	/* node has children */
 	cs = c;
	for (k = 0; k < p->opr.nops; k++) 
	{
		exNode (p->opr.op[k], cs, l+h+eps, &che, &chm);
		cs = che;
	}
	/* total node width */
	if (w < che - c) 
	{
		cbar += (che - c - w) / 2;
		*ce = che;
		*cm = (c + che) / 2;
	}
	/* draw node */
	graphDrawBox (s, cbar, l);
	/* draw arrows (not optimal: children are drawn a second time) */
	cs = c;
	for (k = 0; k < p->opr.nops; k++)
	{
		exNode (p->opr.op[k], cs, l+h+eps, &che, &chm);
		graphDrawArrow (*cm, l+h, chm, l+h+eps-1);
		cs = che;
	}
	// if(s == "[=]")evaluate_assgn_3(p);
}

/* interface for drawing */
#define lmax 250
#define cmax 250
char graph[lmax][cmax]; /* array for ASCII-Graphic */
int graphNumber = 0;

void graphTest (int l, int c)
{ 
	int ok;
	ok = 1;
	if (l < 0) ok = 0;
	if (l >= lmax) ok = 0;
	if (c < 0) ok = 0;
	if (c >= cmax) ok = 0;
	if (ok) return;
	printf ("\n+++error: l=%d, c=%d not in drawing rectangle 0, 0 ... %d, %d", l, c, lmax, cmax);
	exit (1);
}


void graphInit (void) 
{
	int i, j;
	for (i = 0; i < lmax; i++)
	{
		for (j = 0; j < cmax; j++) 
		{
			graph[i][j] = ' ';
		}
	}
}


void graphFinish()
{
	int i, j;
	for (i = 0; i < lmax; i++)
	{
		for (j = cmax-1; j > 0 && graph[i][j] == ' '; j--);
		graph[i][cmax-1] = 0;
		if (j < cmax-1) 
			graph[i][j+1] = 0;
		if (graph[i][j] == ' ') 
			graph[i][j] = 0;
	}
	for (i = lmax-1; i > 0 && graph[i][0] == 0; i--);
	printf ("\n\nGraph %d:\n", graphNumber++);
	for (j = 0; j <= i; j++) printf ("\n%s", graph[j]);
	printf("\n");
}

void graphBox (char *s, int *w, int *h)
{
	*w = strlen (s) + del;
	*h = 1;
}
void graphDrawBox (char *s, int c, int l)
{
	int i;
	graphTest (l, c+strlen(s)-1+del);
	for (i = 0; i < strlen (s); i++) {
	graph[l][c+i+del] = s[i];
	}
}

void graphDrawArrow (int c1, int l1, int c2, int l2)
{
	int m;
	graphTest (l1, c1);
	graphTest (l2, c2);
	m = (l1 + l2) / 2;
	while (l1 != m)
	{
		graph[l1][c1] = '|'; if (l1 < l2) l1++; else l1--;
	}
	while (c1 != c2)
	{
		graph[l1][c1] = '-'; if (c1 < c2) c1++; else c1--;
	}
	while (l1 != l2)
	{
		graph[l1][c1] = '|'; if (l1 < l2) l1++; else l1--;
	}
	graph[l1][c1] = '|';
}


bool evaluate(nodeType* p,int index){
    printf("asdf\n");
	if(!brk_cnt)return 0;
	if(!cont_cnt)return 0;
	if(p->type==typeOpr)
	{printf("funct\n");
        	switch (p->opr.oper)
	{
		case ASSIGN:printf("asdf\n");eqEvaluate(p,index);return 1;break;
		case GT:return gtEvaluate(p, index);break;
		case LT:return ltEvaluate(p, index);break;
		case GE:return gtrEvaluate(p, index);break;
		case LE:return lteEvaluate(p, index);break;
		case NE:return neEvaluate(p, index);break;
		case EQ:return eqeqEvaluate(p, index);break;
		case IF: ifEvaluate(p,index);return 1; break;
		case WHILE: whileEvaluate(p,index);return 1; break;
		case FOR : forEvaluate(p,index);return 1; break;
		case BREAK : brk_cnt = false; return 0; break;
		case CONTINUE : cont_cnt = false; return 0; break;
		case PRINTF: printfEvaluate(p ,index);return 1; break;
		case FUNC_NAME: funcEvaluate(p, index); return 1;break;
		case FUNC_C : funcCallEvaluate(p, index); return 1;break;
		case RETURN : returnEvaluate(p, index); return 1;break;
		case ARR : arrDeclare(p, index); return 1;break;
		default:
			break;
	}
    printf("dfdfd\n");

	}
	for(auto i=0;i<p->opr.nops;i++)
		evaluate(p->opr.op[i],index);
}

void arrDeclare(nodeType *p,int index){
	char *arr_name = p->opr.op[0]->id.name;
	int col_temp = atoi(p->opr.op[2]->con.value);
	int row_temp = atoi(p->opr.op[1]->con.value);
	int i = func_table[index].fun_id_cnt;
	func_table[index].fun_id[i].name = (char *)malloc(sizeof(char)*100);
	func_table[index].fun_id[i].name = arr_name;
	func_table[index].fun_id[i].row_n = row_temp;
	func_table[index].fun_id[i].col_n = col_temp;
	func_table[index].fun_id_cnt++;
}

char *arrEvaluate(nodeType *p, int index){
	char *arr_name = p->opr.op[0]->id.name;
	int col_temp = atoi(p->opr.op[2]->con.value);
	int row_temp = atoi(p->opr.op[1]->con.value);
	int ind_cnt_arr = func_table[index].fun_id_cnt;
	int i ;
	for(i = 0;i<ind_cnt_arr;i++){
		if(strcmp(arr_name,func_table[index].fun_id[i].name)==0){
			break;
		}
	}
	return func_table[index].fun_id[i].val2[row_temp * col_temp + col_temp];
	// return "";
}

void returnEvaluate(nodeType *p, int index){
	if(p->opr.nops == 0){
		return ;
	}
	else{
		char *ret = exprEvaluate(p->opr.op[0],index);
		if(ret == NULL){
			printf("Error in return statement\n");
			exit(1);
		}
		else{
			func_table[index].val = ret;
		}
	}
}

char *paraV[100];
int paraV_ind = 0;
void paraVRec(nodeType *p,int index){
	if(p->type == typeOpr){
		paraVRec(p->opr.op[1],index);
	}
	else 
	{
		paraV[paraV_ind] = exprEvaluate(p,index);
		paraV_ind++;
		return;
	}
	paraV[paraV_ind] = exprEvaluate(p->opr.op[0],index);
	paraV_ind++;


}

void printFuncTable(){
	printf("NEW Function TABLE----------------------\n");
	for(int i=0;i<func_count;i++){
		printf("Function name : %s\n",func_table[i].name);
		printf("Function return value : %s\n",func_table[i].val);
		for(int j=0;j<func_table[i].fun_id_cnt;j++){
			printf("Variable name : %s\n",func_table[i].fun_id[j].name);
			printf("Variable value : %s\n",func_table[i].fun_id[j].val);
		}
	}
}

void funcCallEvaluate(nodeType *p, int index){
	char *name = p->opr.op[0]->id.name;
	int i;
	for(i=0;i<fun_IND;i++){
		if(strcmp(name,func_table[i].name)==0)
			break;
	}
	paraVRec(p->opr.op[1],index);
	// for(int j = paraV_ind-1;jparaV_ind;j++){
	// 	// func_temp_table[j].value = paraV[j];
	// 	printf(" PRinting the values %s\n",paraV[j]);
	// }
	for(int j = paraV_ind-1;j>=0;j--){
		func_table[i].fun_id[paraV_ind - j - 1].val = paraV[j];
	}
	paraV_ind = 0;
	evaluate(func_table[i].body, i);

}
char *valu[100];
int ind = 0;
void rec(nodeType *p,int index){
	if(p->type == typeOpr){
		rec(p->opr.op[1],index);
	}
	else 
		{valu[ind] = exprEvaluate(p,index);ind++;return;}
	valu[ind] = exprEvaluate(p->opr.op[0],index);
	ind++;
}

void parRec(nodeType *p){
	if(p->type == typeOpr){
		parRec(p->opr.op[0]);
	}
	else 
	{
		func_temp_table[fun_IND].name = (char *)malloc(sizeof(char)*100);
		func_temp_table[fun_IND].name = p->id.name;
		fun_IND++;
		return;
	}
	func_temp_table[fun_IND].name = (char *)malloc(sizeof(char)*100);
	func_temp_table[fun_IND].name = p->opr.op[1]->id.name;
	fun_IND++;
}

void funcEvaluate(nodeType *p, int index){
	func_table[func_count].name = (char *)malloc(sizeof(char)*100);
	func_table[func_count].name = p->opr.op[0]->id.name;
	parRec(p->opr.op[1]);
	func_table[func_count].fun_id_cnt = 0;

	for(int i = 0;i<fun_IND;i++){
		func_table[func_count].fun_id[i].name = (char *)malloc(sizeof(char)*100);
		func_table[func_count].fun_id[i].val = (char *)malloc(sizeof(char)*100);
		func_table[func_count].fun_id[i].name = func_temp_table[i].name;
		func_table[func_count].fun_id[i].val = 0;
		func_table[func_count].fun_id_cnt++;
		cnt++;
	}
	func_table[func_count].body = p->opr.op[2];
	if(strcmp(func_table[func_count].name ,"main") == 0){
		evaluate(func_table[func_count].body,func_count);
	}
	fun_IND = 0;
	func_count++;
}

void printFuncs(){
	for(int i = 0;i<func_count;i++){
		printf("%s\n",func_table[i].name);
		
	}
}

void printfEvaluate(nodeType *p, int index){
	if(p->opr.op[1]->opr.oper == 261)
		printf("%s\n",p->opr.op[0]->con.value);
	else{
		rec(p->opr.op[1], index);
		ind--;
		char *temp2 = (char *)malloc(sizeof(char)*100);
		char *temp3 = (char *)malloc(sizeof(char)*100);
		temp2 = p->opr.op[0]->con.value;
		for(int j = 1;j<strlen(temp2)-1;j++){
			if(temp2[j] == '%' && strlen(temp2)>j+1){
				if(temp2[j+1] == 'c')
				{
					strncat(temp3,&valu[ind][1],1);
					ind--;
					j++;
				}
				else {
					strcat(temp3,valu[ind]);
					ind--;
					j++;
				}
			}
			else{
				strncat(temp3,&temp2[j],1);
			}
		}
		ind = 0;
		printf("%s",temp3);
	}
}

void forEvaluate(nodeType *p,int index){
	evaluate(p->opr.op[0],index);
	char * temp1 = exprEvaluate(p->opr.op[1], index);
	while(strcmp(temp1,"true")==0 && brk_cnt)
	{
		evaluate(p->opr.op[3],index);
		cont_cnt = true;
		evaluate(p->opr.op[2],index);
		temp1 = exprEvaluate(p->opr.op[1], index);

	}
	
	brk_cnt = true;
}
void whileEvaluate(nodeType*p,int index){
	char * temp1 = exprEvaluate(p->opr.op[0], index);
	while(strcmp(temp1,"true")==0 && brk_cnt)
	{
		evaluate(p->opr.op[1],index);
		cont_cnt = true;
		temp1 = exprEvaluate(p->opr.op[0], index);
	}
	brk_cnt = true;
}
void ifEvaluate(nodeType*p,int index){
	char * temp1 = exprEvaluate(p->opr.op[0], index);
	if(strcmp(temp1,"true")==0)
		evaluate(p->opr.op[1],index);
	// printf("%d\n",p->opr.op[2]->opr.oper);
	if(p->opr.op[2]->opr.oper != 261){
		evaluate(p->opr.op[2],index);
	}
	
}
bool gtEvaluate(nodeType* p,int index){
	char *lefval = exprEvaluate(p->opr.op[0],index);
	char *rightval = exprEvaluate(p->opr.op[1],index);
	float a = atof(lefval);
	float b = atof(rightval);
	if(a>b)
		return true;
	else
		return false;
}
bool neEvaluate(nodeType* p,int index){
	char *lefval = exprEvaluate(p->opr.op[0],index);
	char *rightval = exprEvaluate(p->opr.op[1],index);
	float a = atof(lefval);
	float b = atof(rightval);
	if(a!=b)
		return true;
	else
		return false;
}
bool eqeqEvaluate(nodeType* p,int index){
	char *lefval = exprEvaluate(p->opr.op[0],index);
	char *rightval = exprEvaluate(p->opr.op[1],index);
	float a = atof(lefval);
	float b = atof(rightval);
	if(a==b)
		return true;
	else
		return false;
}

bool gtrEvaluate(nodeType* p,int index){
	char *lefval = exprEvaluate(p->opr.op[0],index);
	char *rightval = exprEvaluate(p->opr.op[1],index);
	float a = atof(lefval);
	float b = atof(rightval);
	if(a>=b)
		return true;
	else
		return false;
}
bool ltEvaluate(nodeType *p,int index){
	char *lefval = exprEvaluate(p->opr.op[0],index);
	char *rightval = exprEvaluate(p->opr.op[1],index);
	float a = atof(lefval);
	float b = atof(rightval);
	if(a<b)
		return true;
	else
		return false;
	// if(strcmp(lefval,rightval)<0)
	// 	return true;
	// else
	// 	return false;
}
bool lteEvaluate(nodeType *p,int index){
	char *lefval = exprEvaluate(p->opr.op[0],index);
	char *rightval = exprEvaluate(p->opr.op[1],index);
	float a = atof(lefval);
	float b = atof(rightval);
	if(a<=b)
		return true;
	else
		return false;
}

void eqEvaluate(nodeType* p,int index){
	char *temp;
	if(p->opr.op[0]->type == typeOpr){
		temp = exprEvaluate(p->opr.op[1],index);
		// printf("inside arr\n");
		printf("temp: %s\n",temp);
		char *arr_name = p->opr.op[0]->opr.op[0]->id.name;
		int row_index = atoi(exprEvaluate(p->opr.op[0]->opr.op[1],index));
		int col_index = atoi(exprEvaluate(p->opr.op[0]->opr.op[2],index));
		printf("arr_name: %s\n",arr_name);
		printf("row_index: %d\n",row_index);
		printf("col_index: %d\n",col_index);
		for(int i = 0;i<func_table[index].fun_id_cnt;i++){
			if(strcmp(func_table[index].fun_id[i].name,arr_name)==0){
				// strcpy(func_table[index].fun_id[i].val,temp);
				int num_of_col = func_table[index].fun_id[i].col_n;
				func_table[index].fun_id[i].val2[row_index * num_of_col + col_index]  = temp;
				return;
			}
		}
		return;
	}
	char *leftName = p->opr.op[0]->id.name;
	char rightValue[100] ;
	temp = exprEvaluate(p->opr.op[1],index);
	// assuming that right of equal to is expr
	strcpy(rightValue,temp);
	// printf("type %d\n",p->opr.op[1]->type);
	// printf("leftName: %s\n", leftName); 
	// printf("rightValue: %s\n", rightValue);
	for(int i = 0;i<func_table[index].fun_id_cnt;i++){
		if(strcmp(func_table[index].fun_id[i].name,leftName)==0){
			// strcpy(func_table[index].fun_id[i].val,temp);
			func_table[index].fun_id[i].val  = temp;
			return;
		}
	}
	int i = func_table[index].fun_id_cnt;
	func_table[index].fun_id[i].name = (char *)malloc(sizeof(char)*100);
	func_table[index].fun_id[i].val = (char *)malloc(sizeof(char)*100);
	strcpy(func_table[index].fun_id[i].name,leftName);
	strcpy(func_table[index].fun_id[i].val,temp);
	// id_count++;
	func_table[index].fun_id_cnt++;
	cnt++;
}

char *exprEvaluate(nodeType *p,int index){
    printf("adsf\n");
	char *s = (char *)malloc(sizeof(char)*100);
	if(!brk_cnt && !cont_cnt){
		return s;
	}
	if(p->type == typeCon){
		// printf("come CON\n");
		strcpy(s,p->con.value);
		return s;
	}
	else if(p->type == typeId){
		// s = getValue(p->id.name);
		for(int i = 0;i<func_table[index].fun_id_cnt;i++){
			if(strcmp(func_table[index].fun_id[i].name,p->id.name)==0){
				strcpy(s,func_table[index].fun_id[i].val);
				return s;
			}
		}
		printf("error: variable not declared\n");
		exit(0);
	}
	else if(p->type == typeOpr){
		bool ff = false;
		switch (p->opr.oper)
		{	case ARR:
				return arrEvaluate(p,index);
			case PLUS: 
				return addEvaluate(p->opr.op[0],p->opr.op[1],index);
			case MINUS: 
				return subEvaluate(p->opr.op[0],p->opr.op[1],index);
			case MUL: 
				return mulEvaluate(p->opr.op[0],p->opr.op[1],index);
			case DIV: 
				return divEvaluate(p->opr.op[0],p->opr.op[1],index);
			case LT: 
				ff = ltEvaluate(p,index);
				if(ff)
					{strcpy(s,"true");}
				else
					strcpy(s,"false");
				return s;
			case GT: 
				 ff = gtEvaluate(p,index);
				if(ff)
					strcpy(s,"true");
				else
					strcpy(s,"false");
				return s;
			case GE: 
				ff = gtrEvaluate(p,index);
				if(ff)
					strcpy(s,"true");
				else
					strcpy(s,"false");
				return s;
			case LE: 
				ff = lteEvaluate(p,index);
				if(ff)
					strcpy(s,"true");
				else
					strcpy(s,"false");
				return s;
			case NE: 
				ff = neEvaluate(p,index);
				if(ff)
					strcpy(s,"true");
				else
					strcpy(s,"false");
				return s;
			 case EQ: 
				ff = eqeqEvaluate(p,index);
				if(ff)
					strcpy(s,"true");
				else
					strcpy(s,"false");
				return s;
			// case AND: 
			// 	return andEvaluate(p->opr.op[0],p->opr.op[1]);
			// case OR: 
			// 	return orEvaluate(p->opr.op[0],p->opr.op[1]);
			default:
				break;
		}
		return s;
	
	}
}
char *addEvaluate(nodeType *p1,nodeType *p2,int index){
	char *s1 = (char *)malloc(sizeof(char)*100);
	char *s2 = (char *)malloc(sizeof(char)*100);
	s1 = exprEvaluate(p1,index);
	s2 = exprEvaluate(p2,index);
	float a = atof(s1);
	float b = atof(s2);
	float c = a+b;
	char *s = (char *)malloc(sizeof(char)*100);
	sprintf(s,"%f",c);
	return s;
}
char *subEvaluate(nodeType *p1,nodeType *p2,int index){
	char *s1 = (char *)malloc(sizeof(char)*100);
	char *s2 = (char *)malloc(sizeof(char)*100);
	s1 = exprEvaluate(p1,index);
	s2 = exprEvaluate(p2,index);
	float a = atof(s1);
	float b = atof(s2);
	float c = a-b;
	char *s = (char *)malloc(sizeof(char)*100);
	sprintf(s,"%f",c);
	return s;
}
char *mulEvaluate(nodeType *p1,nodeType *p2,int index){
	char *s1 = (char *)malloc(sizeof(char)*100);
	char *s2 = (char *)malloc(sizeof(char)*100);
	s1 = exprEvaluate(p1,index);
	s2 = exprEvaluate(p2,index);
	float a = atof(s1);
	float b = atof(s2);
	float c = a*b;
	char *s = (char *)malloc(sizeof(char)*100);
	sprintf(s,"%f",c);
	return s;
}
char *divEvaluate(nodeType *p1,nodeType *p2,int index){
	char *s1 = (char *)malloc(sizeof(char)*100);
	char *s2 = (char *)malloc(sizeof(char)*100);
	s1 = exprEvaluate(p1,index);
	s2 = exprEvaluate(p2,index);
	float a = atof(s1);
	float b = atof(s2);
	float c = a/b;
	char *s = (char *)malloc(sizeof(char)*100);
	sprintf(s,"%f",c);
	return s;
}
void print_Id_Table(){
    printf("NEW SYMBOL TABLE----------------------\n");
    for(int i = 0;i<id_count;i++){
        printf("name: %s\n",id_table[i].name);
		printf("type: %s\n",id_table[i].val);

    }
}