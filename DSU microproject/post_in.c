#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
# define MAX 20
char str[MAX],stack[MAX];
int top=-1;
void pushp(char c)
{
   stack[++top]=c;
}
char popp()
{
   return stack[top--];
}
void post_in()
{
   int m,ii,jj=0;
   char a,b,op,x[20];
   printf("Enter the postfix expression\n");
   fflush(stdin);
   gets(str);
   strrev(str);
   m=strlen(str);
   for(ii=0;ii<MAX;ii++)
      stack[ii]='\0';
   printf("Infix expression is:\t");
   for(ii=0;ii<m;ii++)
   {
      if(str[ii]=='+'||str[ii]=='-'||str[ii]=='*'||str[ii]=='/')
      {
         pushp(str[ii]);
      }
      else
      {
         x[jj]=str[ii]; jj++;
         x[jj]=popp(); jj++;
      }
   }
   x[jj]=str[top--];
    strrev(x);
   printf("%s\n",x);
}

void pre_in()
{
   int n,i;
   char a,b,op;
   printf("Enter the prefix expression\n");
   fflush(stdin);
   gets(str);
   n=strlen(str);
   for(i=0;i<MAX;i++)
      stack[i]='\0';
   printf("Infix expression is:\t");
   for(i=0;i<n;i++)
   {
      if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
      {
         push(str[i]);
      }
      else
      {
         op=pop();
         a=str[i];
         printf("%c%c",a,op);
      }
   }
   printf("%c\n",str[top--]);
}
void main()
{  int ch;
    while(1)
   {  printf("Enter choice:1 for prefix to infix, 2 for postfix to infix,3 to exit\n");
    scanf("%d",&ch);
    switch(ch)
    {case 1: {pre_in(); break;}
     case 2:{post_in(); break;}
     case 3:{exit(0); break;}
     default: printf("Wrong chioce\n");
   }
   printf("Enter 1 to continue, 0 to exit\n");
   scanf("%d",&ch);
   if(ch==0)
    break;
   }
}