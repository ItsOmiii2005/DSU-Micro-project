void pushpr(char x)
{
    apr[++top] = x;
}
char poppr()
{
    if (top == -1)
        return -1;
    else
        return apr[top--];
}

int prcdpr(char c)
{
    if (c == ')')
        return 0;
    else if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
}
void infixtoprefixpr(char infix[max], char prefix[max])
{
    char temp, x;
    int i = 0, j = 0;
    strrev(infix);
    while (infix[i] != '\0')
    {
        temp = infix[i];
        if (isalnum(temp))
        {
            prefix[j++] = temp;
        }
        else if (temp == ')')
            pushpr(temp);
        else if (temp == '(')
        {
            while ((x = poppr()) != ')')
            {
                prefix[j++] = x;
            }
        }
        else
        {
            while (prcdpr(apr[top]) >= prcdpr(temp))
            {
                prefix[j++] = poppr();
            }
            pushpr(temp);
        }
        i++;
    }
    while (top != -1)
        prefix[j++] = poppr();
    prefix[j] = '\0';
    strrev(prefix);
}