/* 
Title: Stack using array
Roll No: 9529
*/
#include<stdio.h>
#include<stdlib.h> //for exit function

#define SIZE 5 //macro definition

int x; //global variable for different use


//we define a structure to keep all things related to stack in one thing
typedef struct{
    int a[SIZE];
    int top;
}stack;

void push(stack *s);
void pop(stack *s);
void peek(stack *s);
void isEmpty(stack *s);
void isFull(stack *s);
void display(stack *s);
void size(stack *s);


int main(){

    stack s;
    s.top=-1;

    int ch;

    while(1){
    printf("\nEnter your choice\n");
    printf("1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n7. Size\n8. Exit\n");
    scanf("%d",&ch);

    switch(ch){

        case 1: {
                push(&s);
                }break;

        case 2: {
                pop(&s);
                }break;

        case 3:{
                peek(&s);
                }break;

        case 4:{
                isEmpty(&s);
                }break;

        case 5:{
                isFull(&s);
                }break;

        case 6:{
                display(&s);
                }break;

        case 7:{
                size(&s);
                }break;

        case 8:{
                exit(0);
                }break; //break not necessary here

        default:{
                printf("Check your inputs");
                }
    }

    }


    return 0;
}

void push(stack *s){
    
    if(s->top == SIZE-1){
        printf("Stack over-flow ");
    }
    else{
    printf("Enter the number to be pushed:");
    scanf("%d", &x);
    s->top++;
    s->a[s->top]= x;
    }  
}

void pop(stack *s){
    if(s->top == -1){
        printf("Stack under-flow");
    }
    else{
        x= s->a[s->top--];  //decrementing top after use 
        printf("Poped element: %d\n", x);
    }
}

void peek(stack *s){
    if(s->top==-1){
        printf("Stack is empty");
    }
    else{
    printf("Top element: %d", s->a[s->top]); //Just displaying the top element without popping
    }
}

void isEmpty(stack *s){
    if(s->top==-1){
        printf("Stack is empty");
    }
    else{
        printf("Stack not empty");
    }
}

void isFull(stack *s){
    if(s->top == SIZE-1){
        printf("Stack is Full");
    }
    else{
        printf("Stack is not full");
    }
}

void display(stack *s){
    if(s->top==-1){
        printf("Stack is empty");
    }
    else{
        for(int i=s->top; i>=0; i--){
            printf("%d\t", s->a[i]);
        }
    }
}

void size(stack *s){
    int i;
    for(i=0; s->a[i]!='\0'; i++){

    }
    printf("The size: %d", i-1); //i-1 beacause, i increments then checks for condition
}

/* Output

Enter your choice
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Display
7. Size
8. Exit
1
Enter the number to be pushed:5

Enter your choice
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Display
7. Size
8. Exit
1
Enter the number to be pushed:4

Enter your choice
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Display
7. Size
8. Exit
1
Enter the number to be pushed:3

Enter your choice
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Display
7. Size
8. Exit
1
Enter the number to be pushed:2

Enter your choice
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Display
7. Size
8. Exit
2
Poped element: 2

Enter your choice
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Display
7. Size
8. Exit
3
Top element: 3
Enter your choice
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Display
7. Size
8. Exit
4
Stack not empty
Enter your choice
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Display
7. Size
8. Exit
5
Stack is not full
Enter your choice
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Display
7. Size
8. Exit
6
3       4       5
Enter your choice
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Display
7. Size
8. Exit
7
The size: 3
Enter your choice
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Display
7. Size
8. Exit
8
PS C:\Users\Jonathan Dabre\Desktop\jonny> 

*/