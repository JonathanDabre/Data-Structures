/*
Title: Infix
Roll No.: 9529
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //for isalnum 

#define size 10

typedef struct
{
    int top;
    char a[size];
} Stack;

void push(Stack *s, char ele)
{
    if (s->top == size - 1)
    {
        printf("Stack overflow");
        return;
    }
    else
    {
        s->top++;
        s->a[s->top] = ele;
    }
}

char pop(Stack *s)
{

    int x = s->a[s->top];
    s->top--;
    return x;
}

int isEmpty(Stack s)
{
    if (s.top == -1)
        return 1;
    else
        return 0;
}

int precedence(char c) // funtion to check the precedence of the operator
{
    if (c == '(') // lowest precedence is given to ( in a stack
        return 0;
    else if (c == '+' || c == '-') // + and - has the same precedence
        return 1;
    else if (c == '*' || c == '/') // * and / has the same precedence
        return 2;
    else if (c == '^' || c == '$') // highest precedence is given to ^(ie power)
        return 3;
}

//main Function here
int main()
{
    Stack s1;
    char str[size], post[size]; // str for infix input string
    // post is for postfix output string
    int i, j = 0;
    char x;

    s1.top = -1;
    printf("Enter Infix Expression: ");
    gets(str); // use scanf for linux and online gdb compiler and  use gets for any other platform(programiz.com)
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalnum(str[i])) // condition where the token is an operand
        {
            post[j] = str[i]; // put it in postfix string
            j++;
        }
        else // for operator
        {
            if (str[i] == ')')
            {
                x = pop(&s1);    // pops the operators from stack and puts it in postfix string
                while (x != '(') // if popped element is ( ignore
                {
                    post[j] = x;
                    j++;
                    x = pop(&s1);
                }
            }
            else if (isEmpty(s1) || str[i] == '(' || (precedence(str[i]) > precedence(s1.a[s1.top]))) // for str[i] is an operator
            {
                // stack is empty so push
                //  if str[i] = '('push it in stack
                // if str[i] is operator having higher precedence than stack top operator, push it on the previous operator

                push(&s1, str[i]);
            }
            else
            {
                while ((!isEmpty(s1)) && (precedence(str[i]) <= precedence(s1.a[s1.top])))
                {                       // is stacktop has greater precedence than str[i],pop while comparing thr precedence and ensure that the stack is not empty
                    post[j] = pop(&s1); // pop and put in postfix arry the operators from stack having higher or equal precedence
                    j++;
                }
                push(&s1, str[i]); // push the current token on stack
            }
        }
    }
    while (!isEmpty(s1)) // at the end if stack is not empty pop all operators and put them in postfix string
    {
        post[j] = pop(&s1);
        j++;
    }
    post[j] = '\0';                            // put null character at the end to let the computer know that the postfix string is complete
    printf("Postfix expression is: %s", post); // print the postfix string
    return (0);
}