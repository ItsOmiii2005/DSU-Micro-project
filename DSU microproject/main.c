// #define SIZE 50 // Size of Stack
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define max 50 // MACRO
char s[max];
long stack[100];
long top = -1;

char postfix[50];
char infix[50], ch, element;
long i = 0, k = 0;

int choice;
long exp[100];
long n1, n2, n3, num;
char *e, x;

void post_eval()
{
    printf("Enter the Postfix expression :: ");
    scanf("%s", exp);
    e = exp;
    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            num = *e - 48;
            push2(num);
        }
        else
        {
            n1 = pop2();
            n2 = pop2();
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
            push2(n3);
        }
        e++;
    }
    printf("\nTHE FINAL EVALUATION OF THE POSTFIX EXPRESSION %s  =  %d\n\n", exp, pop2());
    printf("--------------------------------------------------------------------------------------------------------------------------------");
}

void push(char element) // you can write push(char element) also:-void would be added by DEFAULT
{
    s[++top] = element;
}
char pop()
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

void push2(int x)
{
    stack[++top] = x;
}

int pop2()
{
    return stack[top--];
}

int main()

{

    printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
    printf("\n\n__________________________________DATA STRUCTURE USING C (DSU) MICRO-PROJECT BY CO3I STUDENTS OF VAPM__________________________");
    printf("\n\n_______________Subject:=>>> DEVELOP A C PROGRAM TO EVALUATE ARITHMATICAL EXPRESSIONS USING STACK & LIKED LIST REPRESENTATION.______________");
    printf("\n\n\t\t\t\t\t\ti]   2110950050          Omanand Prashant Swami");
    printf("\n\t\t\t\t\t\tii]  2110950103          Somesh Mahadev Bharbade");
    printf("\n\t\t\t\t\t\tiii] 2110950088          Amay Nitin Devshatwar\n");

    printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");

    while (1)
    {
        printf("\n\nWhat Do You Want To Do ?");
        printf("\nPlease Choose One Index Number To Perform Operations From Below Given List !");
        printf("\n\n1] Arithmatical Infix To Postfix Expression Converter ???");
        printf("\n\n2] Arithmatical Postfix To Infix Expression Converter ???");
        printf("\n\n3] Arithmatical Postfix Expression Evaluator ???\n\n");
        printf("4] Exit From Programm.\n\n");
        printf("===>>>");
        scanf("\n\n%d", &choice);

        if (choice == 1)
        {

            printf("\nEnter the Infix expression :: ");
            printf("::=====>>>");

            scanf(" %s", infix);
            // if(infix==0){
            //     main();
            // }
            push('#'); // # use for Checkpost
            while ((ch = infix[i++]) != '\0')
            {
                if (ch == '(')
                    push(ch);
                else if (isalnum(ch))
                    postfix[k++] = ch;
                else if (ch == ')')
                {
                    while (s[top] != '(')
                    {
                        postfix[k++] = pop();
                    }
                    element = pop(); // Used for removing '('
                }
                else
                {
                    while (priority(s[top]) >= priority(ch)) // note:- (+) >=(+) condition satisfy
                        postfix[k++] = pop();
                    push(ch);
                }
            }
            while (s[top] != '#')
            {
                postfix[k++] = pop();
            }
            postfix[k] = '\0';
            printf("\n\nGiven Infix Expression :) ===>>> %s\nConverted Postfix Expression :) ===>>> %s\n", infix, postfix);

            e = postfix;
            while (*e != '\0')
            {
                if (isdigit(*e))
                {
                    num = *e - 48;
                    push2(num);
                }
                else
                {
                    n1 = pop2();
                    n2 = pop2();
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
                    push2(n3);
                }
                e++;
            }
            printf("\nTHE FINAL EVALUATION OF THE CONVERTED POSTFIX EXPRESSION %s  :=)  %d\n\n", exp, pop2());
            printf("--------------------------------------------------------------------------------------------------------------------------------");
        }

        else if (choice == 2)
        {
            post_eval();
        }
        else if (choice == 3)
        {
            exit(0);
        }
        else
        {
            printf("Wrong Choice Number , Please enter a valid choice index again !");
        }
    }
    return 0;
}
