

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int x;

typedef struct{
    int a[SIZE];
    int top1, top2;
}stack;

void push_1(stack *s);
void pop_1(stack *s);
void push_2(stack *s);
void pop_2(stack *s);
void display_1(stack *s);
void display_2(stack *s);
void peek_1(stack *s);
void peek_2(stack *s);

int main(){

    stack s;
    s.top1= -1;
    s.top2= SIZE;

    int ch;
    
    

    while(1){

        printf("Enter\n1. Push_1\n2. Pop_1\n3. Push_2\n4. Pop_2\n5. Display_1\n6. Display_2\n7.Peek_1\n8. Peek_2\n9. Exit ");
        printf("\nEnter your choice here:");
        scanf("%d", &ch);

        switch(ch){
            case 1: push_1(&s);
                    break;
                
            case 2: pop_1(&s);
                    break;

            case 3: push_2(&s);
                    break;

            case 4: pop_2(&s);
                    break;
            
            case 5: display_1(&s);
                    break;

            case 6: display_2(&s);
                    break;

            case 7: peek_1(&s);
                    break;
            
            case 8: peek_2(&s);
                    break;  

            case 9: exit(0);
                    break; //break is not necessary when exit function

            default: printf("Check your inputs");            
        }
    }




    return 0;
}

void push_1(stack *s){
    if(s->top1== s->top2 -1){
        printf("Stack_1 overflow");
    }
    else{
       printf("Enter the element to be pushed:");
       scanf("%d", &x);
       s->top1++;
       s->a[s->top1]= x; 
    }
}

void pop_1(stack *s){
    if(s->top1==-1){
        printf("Stack_1 underflow");
    }
    else{
        printf("The popped element: %d\n", s->a[s->top1--]);  //Decrementing top1 after popping
    }
}

void push_2(stack *s){
    if(s->top2== s->top1 + 1){
        printf("Stack_2 overflow");
    }
    else{
       printf("Enter the element to be pushed:");
       scanf("%d", &x);
       s->top2--;
       s->a[s->top2]= x; 
    }
}

void pop_2(stack *s){
    if(s->top2 == SIZE){
        printf("Stack_2 underflow");
    }
    else{
        printf("The popped element: %d\n", s->a[s->top2++]); //Incrementing top2 after popping
    }
}

void display_1(stack *s){
    if(s->top1==-1){
        printf("Stack_1 is empty");
    }
    else{
        for(int i=s->top1; i>=0; i--){
            printf("%d\t", s->a[i]);
        }
    }
}

void display_2(stack *s){
    if(s->top2 == SIZE){
        printf("Stack_2 is empty");
    }
    else{
        for(int i=s->top2; i<=SIZE-1; i++){
            printf("%d\t", s->a[i]);
        }
    }
}

void peek_1(stack *s){
    if(s->top1 == -1){
        printf("Stack_1 is empty");
    }
    else{
        printf("The top element in Stack_1: %d\n", s->a[s->top1]);
    }
}

void peek_2(stack *s){
    if(s->top2 == SIZE){
        printf("Stack_2 is empty");
    }
    else{
        printf("The top element in Stack_2: %d\n", s->a[s->top2]);
    }
}


