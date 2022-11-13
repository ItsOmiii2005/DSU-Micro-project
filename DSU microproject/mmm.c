#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define max 50 // MACRO
// # define MAX 20
char str[max], stack[max];
char s[max];
int top = -1;

char *e;
int n1, n2, n3, num;
char ex[20];

int m, ii, jj = 0;
char a, b, op, x[20];

int choice;
char infix[50], postfix[50], ch, element;
int i = 0, k = 0;

// Function to Push Elements into Stack
void pushp(char c)
{
    stack[++top] = c;
}
char popp()
{
    return stack[top--];
}

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

void pre_in()
{
    printf("Enter the prefix expression to convert in infix===>>>");
    fflush(stdin);
    gets(str);
    m = strlen(str);
    for (ii = 0; ii < max; ii++)
        stack[ii] = '\0';
    printf("Your Converted Infix Expression is:");
    for (ii = 0; ii < m; ii++)
    {
        if (str[ii] == '+' || str[ii] == '-' || str[ii] == '*' || str[ii] == '/')
        {
            push(str[ii]);
        }
        else
        {
            op = pop();
            a = str[ii];
            printf("%c%c", a, op);
        }
    }
    printf("%c\n", str[top--]);
}

void post_in()
{

    printf("Enter the postfix expression to convert in infix===>>>");
    fflush(stdin);
    gets(str);
    strrev(str);
    m = strlen(str);
    for (ii = 0; ii < max; ii++)
        stack[ii] = '\0';
    printf("Your Converted Infix expression is:");
    for (ii = 0; ii < m; ii++)
    {
        if (str[ii] == '+' || str[ii] == '-' || str[ii] == '*' || str[ii] == '/')
        {
            pushp(str[ii]);
        }
        else
        {
            x[jj] = str[ii];
            jj++;
            x[jj] = popp();
            jj++;
        }
    }
    x[jj] = str[top--];
    strrev(x);
    printf("%s\n", x);
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
    printf("Enter the postfix expression ===>>> ");
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

    printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
    printf("\n\n__________________________________DATA STRUCTURE USING C (DSU) MICRO-PROJECT BY CO3I STUDENTS OF VAPM__________________________");
    printf("\n\n_______________Subject:=>>> DEVELOP A C PROGRAM TO CONVERT ARITHMATICAL EXPRESSIONS USING STACK & LIKED LIST REPRESENTATION.______________");
    printf("\n\n\t\t\t\t\t\ti]   2110950050          Omanand Prashant Swami");
    printf("\n\t\t\t\t\t\tii]  2110950103          Somesh Mahadev Bharbade");
    printf("\n\t\t\t\t\t\tiii] 2110950088          Amay Nitin Devshatwar\n");

   

    while (1)
    {
         printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");

        printf("\n\nWhat Do You Want To Do ?");
        printf("\nPlease Choose One Index Number To Perform Operations From Below Given List !");
        printf("\n\n1] Arithmatical Infix To Postfix Expression Converter ???");
        printf("\n\n2] Arithmatical Prefix To Infix Expression Converter ???");
        printf("\n\n3] Arithmatical Postfix To Infix Expression Converter ???");
        printf("\n\n4] Arithmatical Postfix Expression Evaluator ???\n\n");
        printf("5] Exit From Programm.\n\n");
        printf("===>>>");
        scanf("\n\n%d", &choice);
        if (choice == 1)
        {

            in_Post();
        }

        else if (choice == 2)
        {
            pre_in();
        }
        else if (choice == 3)
        {
            post_in();
        }
        else if (choice == 4)
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