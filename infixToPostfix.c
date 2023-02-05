#include<stdio.h>
#include<stdlib.h>

struct stack{
    char arr[100];
    int top; 
};

int isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
        return 1;
    }
    else{
        return 0;
    }
}

int precedence(char c){
    if( c == '^'){
        return 4;
    }
    else if( c == '*' || c=='/'){
        return 3;
    }
    else if(c == '+' || c == '-'){
        return 2;
    }
    else{
        return 0;
    } 
}

int isEmpty(struct stack* s){
    if(s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack* s, char c){
    s->top++;
    s->arr[s->top] = c;    
}

char pop(struct stack* s){
    if(s->top == -1){
        printf("Stack is empty.\n");
    }
    else{
        char st = s->arr[s->top];
        s->top--;
        return st;       
    }
}

void inToPost(struct stack* s, char infix[], char postfix[]){

    int i=0;
    int j=0;

    while(infix[i] != '\0'){

        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(isEmpty(s)){
                push(s, infix[i]);
                i++;
            }

            else if( precedence(infix[i]) > precedence(s->arr[s->top])){
                push(s, infix[i]);
                i++;
            }
            else{

                while( precedence(s->arr[s->top]) >= precedence(infix[i]) ){

                    postfix[j] = pop(s);
                    j++;
                    if(isEmpty(s)){
                        break;
                    }
                }

                push(s, infix[i]);
                i++;
            }
        }
    }
    
    while(!isEmpty(s)){

        postfix[j] = pop(s);
        j++;
    }

    postfix[j] = '\0';
}

//Main
int main(){

    struct stack s;
    s.top =-1;

    char infix[100];
    char postfix[100];

    printf("Enter the infix expression: ");
    fgets(infix, 100, stdin);

    inToPost(&s, infix, postfix);

    printf("Postfix: %s", postfix);

    return 0;
}