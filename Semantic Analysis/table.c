#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>>

int decCounter = 0;
struct dec
{
    char *type;
    char *name;
    float val;
} dec[10];

typedef struct id_symbol
{
    char *type;
    char *name;
    float val;
} id_symbol;

typedef struct func_symbol
{
    char *returnType;
    int para;
    char *paraType[10];
    char *name;
    char *paraName[10];
    float val[10];
} func_symbol;

typedef struct arr_symbol
{
    char *type;
    char *name;
    int r, c;
    float val[1000];
} arr_symbol;

int id_count = 0;
int func_count = 0;
int arr_count = 0;

id_symbol id_table[1000];
func_symbol func_table[10];
arr_symbol arr_table[1000];

bool isPresentArr(char *name)
{
    for (int i = 0; i < arr_count; i++)
    {
        if (strcmp(arr_table[i].name, name) == 0)
        {
            return true;
        }
    }
    return false;
}

void insertID(char *name, char *type)
{
    if (isPresentArr(name))
    {
        printf("ERROR: Identifier %s already declared\n", name);
        exit(0);
    }
    for (int i = 0; i < id_count; i++)
    {
        if (strcmp(id_table[i].name, name) == 0)
        {
            printf("ERROR: Variable %s already declared\n", name);
            exit(0);
        }
    }
    id_symbol *new_sym = (id_symbol *)malloc(sizeof(id_symbol));
    new_sym->name = strdup(name);
    new_sym->type = strdup(type);
    new_sym->val = 0;
    id_table[id_count++] = *new_sym;

    free(new_sym);
}

bool isPresentId(char *name)
{
    for (int i = 0; i < id_count; i++)
    {
        if (strcmp(id_table[i].name, name) == 0)
        {
            return true;
        }
    }
    return false;
}

void insertArr(char *name, char *type, int r, int c)
{
    if (isPresentId(name))
    {
        printf("ERROR: Identifier %s already declared\n", name);
        exit(0);
    }
    for (int i = 0; i < arr_count; i++)
    {
        if (strcmp(arr_table[i].name, name) == 0)
        {
            printf("ERROR: Array %s already declared\n", name);
            exit(0);
        }
    }
    arr_table[arr_count] = *(arr_symbol *)malloc(sizeof(arr_symbol));
    arr_table[arr_count].name = strdup(name);
    arr_table[arr_count].type = strdup(type);
    arr_table[arr_count].r = r;
    arr_table[arr_count].c = c;
    arr_count++;
}

void insertFunc(char *name, char *returnType)
{
    for (int i = 0; i < func_count; i++)
    {
        if (strcmp(func_table[i].name, name) == 0)
        {
            printf("ERROR: Function %s already declared\n", name);
            exit(0);
        }
    }
    func_symbol *new_func = (func_symbol *)malloc(sizeof(func_symbol));
    if (new_func == NULL)
    {
        printf("ERROR: Failed to allocate memory for function %s\n", name);
        exit(0);
    }
    new_func->name = strdup(name);
    new_func->returnType = strdup(returnType);
    new_func->para = 0;

    // Add the new function symbol to the table
    func_table[func_count] = *new_func;
    func_count++;

    free(new_func);
}

char *findFunc(char *name)
{
    for (int i = 0; i < func_count; i++)
    {
        if (strcmp(func_table[i].name, name) == 0)
        {
            return func_table[i].returnType;
        }
    }
    printf("ERROR: Function %s not declared\n", name);
    exit(0);
}

char *findArrType(char *name)
{
    for (int i = 0; i < arr_count; i++)
    {
        if (strcmp(arr_table[i].name, name) == 0)
        {
            return arr_table[i].type;
        }
    }
    printf("ERROR: Array %s not declared\n", name);
    exit(0);
}

char *findIdType(char *name)
{
    for (int i = 0; i < id_count; i++)
    {
        if (strcmp(id_table[i].name, name) == 0)
        {
            return id_table[i].type;
        }
    }
    printf("ERROR: Variable %s not declared\n", name);
    exit(0);
}

float findArrVal(char *name, int r, int c)
{
    for (int i = 0; i < arr_count; i++)
    {
        if (strcmp(arr_table[i].name, name) == 0)
        {
            return arr_table[i].val[r * arr_table[i].c + c];
        }
    }
    printf("ERROR: Array %s not declared\n", name);
    exit(0);
}

void updateFunc(int para, struct dec *d)
{
    func_table[func_count - 1].para = para;
    for (int i = 0; i < para; i++)
    {
        func_table[func_count - 1].paraType[i] = strdup(d[i].type);
        func_table[func_count - 1].paraName[i] = strdup(d[i].name);
    }
}

void updateID(char *name, float val)
{
    for (int i = 0; i < id_count; i++)
    {
        if (strcmp(id_table[i].name, name) == 0)
        {
            id_table[i].val = val;
        }
    }
}

void print_func_Table()
{
    printf("NEW FUNCTION TABLE----------------------\n");
    for (int i = 0; i < func_count; i++)
    {
        printf("%s\t%s\t", func_table[i].name, func_table[i].returnType);
        for (int j = 0; j < func_table[i].para; j++)
        {
            printf("%s %s\t", func_table[i].paraType[j], func_table[i].paraName[j]);
        }
        printf("\n");
    }
}

void print_Id_Table()
{
    printf("NEW SYMBOL TABLE----------------------\n");
    for (int i = 0; i < id_count; i++)
    {
        switch (id_table[i].type[0])
        {
        case 'I':
            printf("%s\t%s\t%d\n", id_table[i].name, id_table[i].type, (int)id_table[i].val);
            break;
        case 'F':
            printf("%s\t%s\t%f\n", id_table[i].name, id_table[i].type, id_table[i].val);
            break;
        case 'C':
            printf("%s\t%s\t%c\n", id_table[i].name, id_table[i].type, (int)id_table[i].val + 'a');
            break;
        }
    }
}

int comparator(float a, float b, char *op)
{
    int result;
    switch (*op)
    {
    case '>':
        if (op[1] == '=')
        {
            result = a >= b;
        }
        else
        {
            result = a > b;
        }
        break;
    case '<':
        if (op[1] == '=')
        {
            result = a <= b;
        }
        else
        {
            result = a < b;
        }
        break;
    case '!':
        if (op[1] == '=')
        {
            result = a != b;
        }
        else
        {
            printf("ERROR: Invalid operator\n");
            exit(0);
        }
        break;
    case '=':
        if (op[1] == '=')
        {
            result = a == b;
        }
        else
        {
            printf("ERROR: Invalid operator\n");
            exit(0);
        }
        break;
    case '&':
        if (op[1] == '&')
        {
            result = a && b;
        }
        else
        {
            printf("ERROR: Invalid operator\n");
            exit(0);
        }
        break;
    case '|':
        if (op[1] == '|')
        {
            result = a || b;
        }
        else
        {
            printf("ERROR: Invalid operator\n");
            exit(0);
        }
        break;
    default:
        printf("ERROR: Invalid operator\n");
        exit(0);
    }
    return result;
}

void typeCheck(char *name, char *type)
{
    int i;
    for (i = 0; i < id_count; i++)
    {
        if (strcmp(id_table[i].name, name) == 0)
        {
            break;
        }
    }
    if (i == id_count)
    {
        printf("ERROR: Variable %s not declared\n", name);
        exit(0);
    }
    if (strcmp(id_table[i].type, type) != 0)
    {
        printf("ERROR: Type mismatch for %s\n", name);
        exit(0);
    }
}

void print_Arr_Table()
{
    printf("NEW ARRAY TABLE----------------------\n");
    for (int i = 0; i < arr_count; i++)
    {
        printf("%s\t%s\t%d\t%d\n", arr_table[i].name, arr_table[i].type, arr_table[i].r, arr_table[i].c);
    }
}

bool findArrSize(char *name, int r, int c)
{
    for (int i = 0; i < arr_count; i++)
    {
        if (strcmp(arr_table[i].name, name) == 0)
        {
            return (r < arr_table[i].r || r == 0) && c < arr_table[i].c;
        }
    }
    printf("ERROR: Array %s not declared\n", name);
    exit(0);
}

void printsolve(char *a, char *listType[], int d)
{
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] == '%')
        {
            if (d <= 0)
            {
                printf("ERROR: Too few arguments for printf\n");
                exit(0);
            }
            if (a[i + 1] == 'd')
            {
                if (strcmp(listType, "INT") != 0)
                {
                    printf("ERROR: Type mismatch for printf\n");
                    exit(0);
                }
                d--;
            }
            else if (a[i + 1] == 'f')
            {
                if (strcmp(listType, "FLOAT") != 0)
                {
                    printf("ERROR: Type mismatch for printf\n");
                    exit(0);
                }
                d--;
            }
            else if (a[i + 1] == 'c')
            {
                if (strcmp(listType, "CHAR") != 0)
                {
                    printf("ERROR: Type mismatch for printf\n");
                    exit(0);
                }
                d--;
            }
        }
    }
    if (d > 0)
    {
        printf("ERROR: Too many arguments for printf\n");
        exit(0);
    }
    d = 0;
}

void funccall1(char *a, int b, char *listType[], char *c)
{
    if (strcmp(c, findFunc(a)) != 0)
    {
        printf("ERROR: Type mismatch for function %s\n", a);
        exit(0);
    }
    for (int i = 0; i < func_count; i++)
    {
        if (strcmp(func_table[i].name, a) == 0)
        {
            if (func_table[i].para != b)
            {
                printf("ERROR: Number of arguments mismatch for function %s\n", a);
                exit(0);
            }
            for (int j = b - 1; j >= 0; j--)
            {
                if (strcmp(func_table[i].paraType[b - j - 1], listType[j]) != 0)
                {
                    printf("ERROR: Type mismatch for function %s\n", a);
                    exit(0);
                }
            }
        }
    }
    b = 0;
}

void insertEntry(char *t)
{
    printf("%s\n", t);
    for (int i = 0; i < decCounter; i++)
    {
        printf("%s %s\n", dec[i].name, dec[i].type);
        insertID(dec[i].name, t);
        if (dec[i].val != INT_MIN)
        {
            if (strcmp(dec[i].type, t) != 0)
            {
                printf("ERROR: Type mismatch for variable %s\n", dec[i].name);
                exit(0);
            }
            updateID(dec[i].name, dec[i].val);
        }
    }
    decCounter = 0;
}

void funccall2(char *a, char *b, char *c, int d)
{
    if (strcmp(c, findFunc(a)) != 0)
    {
        printf("ERROR: Type mismatch for function %s\n", a);
        exit(0);
    }
    for (int i = 0; i < func_count; i++)
    {
        if (strcmp(func_table[i].name, a) == 0)
        {
            if (func_table[i].para != d)
            {
                printf("ERROR: Number of arguments mismatch for function %s\n", a);
                exit(0);
            }
        }
    }
    insertID(b, c);
}

void funccall3(char *a, int b, char *listType[])
{
    printf("Hello ");
    findFunc(a);
    for (int i = 0; i < func_count; i++)
    {
        if (strcmp(func_table[i].name, a) == 0)
        {
            if (func_table[i].para != b)
            {
                printf("ERROR: Number of arguments mismatch for function %s\n", a);
                exit(0);
            }
            for (int j = b - 1; j >= 0; j--)
            {
                if (strcmp(func_table[i].paraType[b - j - 1], listType[j]) != 0)
                {
                    printf("ERROR: Type mismatch for function %s\n", a);
                    exit(0);
                }
            }
        }
    }
    b = 0;
}

void funccall4(char *a, char *b, int c)
{
    if (strcmp(findIdType(a), findFunc(b)) != 0)
    {
        printf("ERROR: Type mismatch for function %s\n", b);
        exit(0);
    }
    for (int i = 0; i < func_count; i++)
    {
        if (strcmp(func_table[i].name, b) == 0)
        {
            if (func_table[i].para != c)
            {
                printf("ERROR: Number of arguments mismatch for function %s\n", b);
                exit(0);
            }
        }
    }
}

void funccall5(char *a, char *b, int c)
{
    if (strcmp(findIdType(a), findFunc(b)) != 0)
    {
        printf("ERROR: Type mismatch for function %s\n", b);
        exit(0);
    }
    for (int i = 0; i < func_count; i++)
    {
        if (strcmp(func_table[i].name, b) == 0)
        {
            if (func_table[i].para != c)
            {
                printf("ERROR: Number of arguments mismatch for function %s\n", b);
                exit(0);
            }
        }
    }
    c = 0;
}

void termsolve1(char *a, char *b, char *c, float d, float e, float f)
{
    if (strcmp(a, b) != 0)
    {
        print_Id_Table();
        printf("ERROR: Type mismatch for expression\n");
        exit(0);
    }
    c = a;
    d = e + f;
}

void termsolve2(char *a, char *b, char *c, float d, float e, float f)
{
    if (strcmp(a, b) != 0)
    {
        print_Id_Table();
        printf("ERROR: Type mismatch for expression\n");
        exit(0);
    }
    c = a;
    d = e - f;
}

void termsolve3(char *a, char *b, char *c, float d, float e, float f)
{
    if (strcmp(a, b) != 0)
    {
        print_Id_Table();
        printf("ERROR: Type mismatch for expression\n");
        exit(0);
    }
    c = a;
    d = e * f;
}

void termsolve4(char *a, char *b, char *c, float d, float e, float f)
{
    if (strcmp(a, b) != 0)
    {
        print_Id_Table();
        printf("ERROR: Type mismatch for expression\n");
        exit(0);
    }
    c = a;
    d = e / f;
}

void termsolve5(char *a, char *b, char *c, float d, float e, float f)
{
    if (strcmp(a, b) != 0)
    {
        print_Id_Table();
        printf("ERROR: Type mismatch for expression\n");
        exit(0);
    }
    c = a;
    d = (int)e % (int)f;
}

void termsolve6(char *a, char *b)
{
    a = b;
}

void declsolve1(char *a, char *b, char *c, char *d, float e)
{
    a = b;
    dec[decCounter] = *(struct dec *)malloc(sizeof(dec));
    dec[decCounter].name = c;
    dec[decCounter].val = e;
    dec[decCounter].type = d;
    decCounter++;
    insertEntry(b);
}

void declsolve2(char *a, char *b, char *c)
{
    a = b;
    dec[decCounter] = *(struct dec *)malloc(sizeof(dec));
    dec[decCounter].name = c;
    dec[decCounter].val = INT_MIN;
    decCounter++;
    insertEntry(b);
}

void decltail1(char *a)
{
    dec[decCounter] = *(struct dec *)malloc(sizeof(dec));
    dec[decCounter].name = a;
    dec[decCounter].val = INT_MIN;
    decCounter++;
}

void decltail2(char *a, char *b, float c)
{
    dec[decCounter] = *(struct dec *)malloc(sizeof(dec));
    dec[decCounter].name = a;
    dec[decCounter].val = c;
    dec[decCounter].type = b;
    decCounter++;
}

void assign1(char *a, char *b, float c)
{
    typeCheck(a, b);
    updateID(b, c);
}

void assign2(char *a, char *b, float c)
{
    if (strcmp(findArrType(a), b) != 0)
    {
        printf("ERROR: Wrong variable type passed in Array\n");
        exit(0);
    }
    if (c < 0 || !findArrSize(b, 0, c))
    {
        printf("ERROR: Array index out of bounds\n");
        exit(0);
    }
}

void assign3(char *a, char *b, float c)
{
    if (strcmp(findArrType(a), b) != 0)
    {
        printf("ERROR: Wrong variable type passed in Array\n");
        exit(0);
    }
    if (c < 0 || !findArrSize(a, 0, c))
    {
        printf("ERROR: Array index out of bounds\n");
        exit(0);
    }
}

void assign4(char *a, char *b, float c, float d)
{
    if (strcmp(findArrType(a), b) != 0)
    {
        printf("ERROR: Wrong variable type passed in Array\n");
        exit(0);
    }
    if (c < 0 || d < 0 || !findArrSize(a, c, d))
    {
        printf("ERROR: Array index out of bounds\n");
        exit(0);
    }
}

void assign5(char *a, char *b, float c, float d)
{
    if (strcmp(findArrType(a), b) != 0)
    {
        printf("ERROR: Wrong variable type passed in Array\n");
        exit(0);
    }
    if (c < 0 || d < 0 || !findArrSize(a, c, d))
    {
        printf("ERROR: Array index out of bounds\n");
        exit(0);
    }
}