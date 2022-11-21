#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define max 100

#define TAB '\t'
#define BLANK ' '
int top = -1;
void pushw(long int symbol);
long int popw();
void infix_to_postfixw();
long int eval_postw();
int priorityw(char symbol);
int isEmptyw();
int white_spacew(char symbol);
char infixw[max], postfixw[max];
long int stackw[max];
char *reversesw(char str[]);
char str_tmpw[100];
long long int countw = 0;

// int top = -1;
char str[max], stack[max];
char s[max];
char *e;
int n1, n2, n3, num;
char ex[20];
int m, j = 0;
char a, b, op, x[20];
int choice;
char infix[max], postfix[max], ch, element;
int i = 0, k = 0;

void pushin(char xin)
{
    stack[++top] = xin;
}

char popin()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priorityin(char xin)
{
    if (xin == '(')
        return 0;
    if (xin == '+' || xin == '-')
        return 1;
    if (xin == '*' || xin == '/')
        return 2;
    return 0;
}

void pushp(char c)
{
    stack[++top] = c;
}

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}



void push1(char element) // you can write push(char element) also:-void would be added by DEFAULT
{
    s[++top] = element;
}
char pop1()
{
    return (s[top--]);
}
int priority(char element)
{
    switch (element)
    {
    case '#':
        return 0;
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
}

void in_Post()
{

    printf("Enter The Infix Expression To Convert In Postfix ====>>>");
    scanf("%s", infix);
    push1('#'); // # use for Checkpost
    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')
            push1(ch);
        else if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == ')')
        {
            while (s[top] != '(')
            {
                postfix[k++] = pop1();
            }
            element = pop1(); // Used for removing '('
        }
        else
        {
            while (priority(s[top]) >= priority(ch)) // note:- (+) >=(+) condition satisfy
                postfix[k++] = pop1();
            push1(ch);
        }
    }
    while (s[top] != '#')
    {
        postfix[k++] = pop1();
    }
    postfix[k] = '\0';
    printf("\nYour Converted Postfix Expression Is : %s\n", postfix);
}

void post_eval()
{
    printf("Enter the postfix expression to evaluate ===>>> ");
    scanf("%s", ex);
    e = ex;
    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch (*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
        e++;
    }
    printf("\nThe result of postfix expression evaluation is :%s  =  %d\n\n", ex, pop());
}

int main()

{

    printf("\n\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
    printf("\n\n__________________________________DATA STRUCTURE USING C (DSU) MICRO-PROJECT BY CO3I STUDENTS OF VAPM__________________________");
    printf("\n\n_______________Subject:=>>> DEVELOP A C PROGRAM TO CONVERT ARITHMATICAL EXPRESSIONS USING STACK & LIKED LIST REPRESENTATION.______________");
    printf("\n\n\t\t\t\t\t\ti] 2110950050          Omanand Prashant Swami");
    printf("\n\t\t\t\t\t\t ii] 2110950103          Somesh Mahadev Bharbade");
    printf("\n\t\t\t\t\t\tiii] 2110950088          Amay Nitin Devshatwar\n");

    char expin[100];
    char *ein, xin;
    long int valuew;

    while (1)
    {
        printf("\n\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");

        printf("\n\nWhat Do You Want To Do ?");
        printf("\nPlease Choose One Index Number To Perform Operations From Below Given List !");
        printf("\n\n1] Arithmatical Infix To Postfix Expression Converter ???");
        printf("\n\n2] Arithmatical Infix To Prefix Expression Converter ???");

        printf("\n\n3] Arithmatical Postfix Expression Evaluator ???\n\n");
        printf("4] Exit From Programm.\n\n");
        printf("===>>>");
        scanf("\n\n%d", &choice);
        if (choice == 1)
        {

            printf("\nEnter The Infix Expression To Convert In Postfix ====>>>");
            scanf("%s", expin);
            printf("\n");
            ein = expin;

            while (*ein != '\0')
            {
                if (isalnum(*ein))
                    printf("%c ", *ein);
                else if (*ein == '(')
                    pushin(*ein);
                else if (*ein == ')')
                {
                    while ((xin = popin()) != '(')
                        printf("%c", xin);
                }
                else
                {
                    while (priorityin(stack[top]) >= priorityin(*ein))
                        printf("%c", popin());
                    pushin(*ein);
                }
                ein++;
            }
char c(){
            while (top != -1)
            {
                char ck(){
                printf("%c", popin());
                return popin();
                }
            }
                printf("%c", ck());
        return ck();
        }

        else if (choice == 2)
        {
            printf("Enter The Infix Expression To Convert In Prefix ====>>>"); // enter the whole expression here
            // gets(infixw);
            scanf("%s", infixw);
            strcpy(infixw, reversesw(infixw)); // Here we reverse the expression
            infix_to_postfixw();               // calling function
            printf("Prefix:%s\n", reversesw(postfixw));
            //    valuew = eval_postw();
            //    printf("valuew of expression: %ld\n", valuew);
        }

        else if (choice == 3)
        {
            post_eval();
        }

        else
        {
            exit(0);
        }
    }
    return 0;
}

void infix_to_postfixw()
{
    unsigned int i, p = 0;
    char next;
    char symbol;
    for (i = 0; i < strlen(infixw); i++)
    {
        symbol = infixw[i]; // assigning each valuew of infixw expression to symbol
        if (!white_spacew(symbol))
        {
            switch (symbol)
            {
            case '(':
                pushw(symbol);
                break;
            case ')':
                while ((next = popw()) != '(')
                {
                    postfixw[p++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while ((!isEmptyw()) && (priorityw(stackw[top]) > priorityw(symbol)))
                {
                    postfixw[p++] = popw();
                }
                pushw(symbol);
                break;
            default:
                postfixw[p++] = symbol;
            }
        }
    }
    while (!isEmptyw()) // if some symbols remains left they are popw out here
    {
        postfixw[p++] = popw();
    }
    postfixw[p] = '\0'; // the expression in string format
}
char *reversesw(char str[]) // it reverse the string
{
    int len = strlen(str);
    int j = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == '(')
        {
            str_tmpw[j] = ')';
            j++;
        }
        else if (str[i] == ')')
        {
            str_tmpw[j] = '(';
            j++;
        }
        else
        {
            str_tmpw[j] = str[i];
            j++;
        }
    }
    str_tmpw[j++] = '\0';
    return str_tmpw;
}
int priorityw(char symbol) // it assign the priorityw to the operators
{
    switch (symbol)
    {
    case '(':
        return 0;
        break;
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
    case '%':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        return 0;
    }
}
void pushw(long int symbol)
{
    if (top > max)
    {
        printf("stackw overflow");
        return;
    }
    top = top + 1;
    stackw[top] = symbol;
    countw++;
}
long int popw()
{
    if (isEmptyw())
    {
        printf("stackw underflow\n");
        return 0;
    }
    return stackw[top--];
}
int isEmptyw()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int white_spacew(char symbol)
{
    if (symbol == BLANK || symbol == TAB)
    {
        return 1;
    }
    else
        return 0;
}