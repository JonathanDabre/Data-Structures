/*
Title: Postfix
Roll No.: 9529
*/
#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <ctype.h> // for isdigit

#define size 20

struct stack
{
    int str[size];
    int top;
};

int isEmpty(struct stack *p)
{
    if (p->top == -1)
        return (1);
    else
        return (0);
}

void push(struct stack *p, int a)
{
    if ((p->top) == size - 1)
        printf("Stack overflow");
    else
        p->str[++(p->top)] = a;
}

int pop(struct stack *p)
{
    if (isEmpty(p))
    {
        printf("Stack underflow");
        exit(1);
    }
    return (p->str[(p->top)--]);
}

int op(int a, int b, char sign)
{
    switch (sign) // to do the appropriate operation
    {
    case '+':
        return (a + b);
    case '-':
        return (a - b);
    case '*':
        return (a * b);
    case '/':
        return (a / b);
    case '^':
        return (pow(a, b));
    }
}


//main function here
int main()
{
    struct stack s1;
    s1.top = -1;
    int i = 0;

    char eq[size];
    int t1, t2;
    printf("Enter the postfix expression = ");
    scanf("%s", eq);
    while (eq[i])
    {
        if (isdigit(eq[i])) // checking for the operand
        {
            push(&s1, eq[i] - '0'); // using the ascii value of 0- ascii value of the said operand no
        }
        else
        {
            t1 = pop(&s1);
            t2 = pop(&s1);
            push(&s1, op(t2, t1, eq[i]));
        }
        i++;
    }
    printf("\n\nResult = %d", pop(&s1));
    return 0;
}
