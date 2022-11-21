#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
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
main()
{
    long int valuew;
    top = -1;
    printf("Enter the infixw:"); // enter the whole expression here
    gets(infixw);
    strcpy(infixw, reversesw(infixw)); // Here we reverse the expression
    infix_to_postfixw();               // calling function
    printf("Prefix:%s\n", reversesw(postfixw));
    //    valuew = eval_postw();
    //    printf("valuew of expression: %ld\n", valuew);
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
long int eval_postw() // this function is for the evaluation of the expression
{
    long int a, b, temp, result;
    unsigned int i;
    for (i = 0; i < strlen(postfixw); i++)
    {
        if (postfixw[i] <= '9' && postfixw[i] >= '0')
        {
            pushw(postfixw[i] - '0'); // conversion of string format to numeric for calcultion
        }
        else
        {
            a = popw();
            b = popw();
            switch (postfixw[i])
            {
            case '+':
                temp = a + b;
                break;
            case '-':
                temp = a - b;
                break;
            case '*':
                temp = b * a;
                break;
            case '/':
                temp = a / b;
                break;
            case '%':
                temp = b % a;
                break;
            case '^':
                temp = pow(a, b);
                break;
            }
            pushw(temp);
        }
    }
    result = popw();
    return result;
}
