#include <stdio.h>
#include<ctype.h>             //use for excessing isalnum() function
#define max 50                //MACRO
char s[max];
int top = -1;
void push(char element)      //you can write push(char element) also:-void would be added by DEFAULT
{
	s[++top]=element;
}
char pop(){
	return(s[top--]);
}
int priority(char element){
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
 
int main(void) {
	char infix[50],postfix[50],ch,element;
	int i=0,k=0;
	printf("Enter The Infix Expression To Convert In Postfix ====>>>");
	scanf("%s",infix);
	push('#');                                 // # use for Checkpost
	while((ch = infix[i++])!='\0'){
		if(ch=='(')
		push(ch);
		else if(isalnum(ch))
		postfix[k++]=ch;
		else if(ch==')'){
			while(s[top]!='(')
			{
			postfix[k++]=pop();
			}
			element=pop();                    //Used for removing '('
		}
		else{
			while(priority(s[top])>=priority(ch))   // note:- (+) >=(+) condition satisfy
			postfix[k++]=pop();
			push(ch);
		}
	}
	while(s[top]!='#'){
		postfix[k++]=pop();
	}
	postfix[k]='\0';
	printf("\nGiven Infix Expression Is : %s\nConverted Postfix Expression Is : %s\n", infix, postfix);
	return 0;
}
/*
For Reference:-
http://www.c-program-example.com/2011/10/c-program-for-infix-to-postfix.html
*/ 