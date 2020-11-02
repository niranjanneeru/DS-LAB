#include<stdio.h>
#include<ctype.h>
#include <math.h>
char stack[20];
int top=-1;
int stack1[20];
int top1 = -1;
void push1(int x)
{
    stack1[++top1] = x;
}
int pop1()
{
    return stack1[top1--];
}

void push(char x)
{
    stack[++top]=x;
}
char pop()
{
    if (top==-1)
        return -1;
    else
        return stack[top--];
}
int value(int x1, int x2, char item) {
    switch (item) {
        case '+':
            return x1 + x2;
        case '-':
            return x1 - x2;
        case '*':
            return x1 * x2;
        case '/':
            return x1 / x2;
        case '^':
            return pow(x1, x2);
    }
}
int priority(char x)
{
    if(x=='(')
        return 0;
    if(x=='+'||x=='-')
        return 1;
    if(x=='*'||x=='/')
        return 2;
}
int main()
{
    char out[20];
    char exp[20];
    char *e,x;
    printf("Enter the Infix expression:");
    scanf("%s",exp);
    e=exp;
    int c = 0;
    while(*e!='\0')
    {
        if(isalnum(*e))
            out[c++] = *e;
        else if(*e=='(')
            push(*e);
        else if(*e==')')
        {
            while((x=pop())!='(')
                out[c++] = x;
        }
        else
        {
            while((priority(stack[top]))>=(priority(*e)))
                out[c++] = pop();
            push(*e);
        }
        e++;
    }
    while(top!=-1)
    {
        out[c++] = pop();
    }
    out[c] = '\0';
    char *p;
    int n1,n2,n3,num;
    printf("The Postfix form of  expression : %s",out);
    p = out;
    while(*p != '\0')
    {
        if(isdigit(*p))
        {
            num = *p - 48;
            push1(num);
        }
        else
        {
            n1 = pop1();
            n2 = pop1();
            switch(*p)
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
            push1(n3);
        }
        p++;
    }
    printf("The result of expression %s  =  %d\n",out,pop1());
    return 0;
}