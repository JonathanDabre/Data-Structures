#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    char arr[50];
};

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

void pop(struct stack* s){
    if(s->top == -1){
        printf("Stack empty");
    }
    else{
        s->top--;
    }
}

int parenthesis_match(struct stack* s, char exp[]){
    for(int i=0; exp[i] != '\0'; i++){

        if(exp[i] == '('){
            push(s, exp[i]);
        }
        else if(exp[i] == ')'){

            if(isEmpty(s)){

                printf("\nParenthesis Unbalanced.\n");
                return 0;
            }
            else{
                pop(s);
            }
        }
    }

    if(isEmpty(s)){
        printf("\nParenthesis Balanced successfully.\n");
        return 1;
    }
    else{
        printf("\nParenthesis Unbalanced.\n");
        return 0;
    }
}

//Main
int main(){

    struct stack s;
    s.top = -1;
    char exp[100];

    printf("Enter the expression: ");
    fgets(exp, 100, stdin);

    int status = parenthesis_match(&s, exp);

    return 0;
}