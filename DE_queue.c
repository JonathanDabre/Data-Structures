//All the operations
//insertFront
//insertRear
//DeleteFront
//insertRear

#include<stdio.h>
#include<stdlib.h>

struct DEqueue{
    int f;
    int r;
    int size;
    int* arr;
};



void enqueueRe(struct DEqueue* q){

    if(q->r == q->size - 1){
        printf("Enqueue Operation not possible from rear.\n");
    }
    else{
        q->r ++;
        printf("Enter Data: ");
        scanf("%d", &q->arr[q->r]);
    }   
}

void dequeueFr(struct DEqueue* q){
    
    if(q->f == q->r){
        printf("Queue Empty.\n");
    }
    else{
        q->f++;
        printf("Element: %d dequeued from Front\n", q->arr[q->f]);
    }
}

void enqueueFr(struct DEqueue* q){
    if(q->f == -1){
        printf("Enqueue Operation not possible from front.\n");
    }
    else{
        printf("Enter Data: ");
        scanf("%d", &q->arr[q->f]);
        q->f--;
    }
}

void dequeueRe(struct DEqueue* q){
    if(q->r == q->f){
        printf("Queue Empty.\n");
    }
    else{
        printf("Element: %d dequeued from Rear.\n", q->arr[q->r]);
        q->r--;
    }
}

void display(struct DEqueue* q){
    if(q->r == q->f){
        printf("Nothing to Display.\n");
    }
    else{
        for(int i = q->f + 1; i<= q->r; i++){
            printf("%d\t", q->arr[i]);
        }
        printf("\n");
    }
}

int main(){
    
    struct DEqueue dq;

    dq.size = 6;
    dq.f =-1;
    dq.r =-1;

    dq.arr = (int *) malloc(dq.size * sizeof(int));

    int ch;

    while(1){

        printf("\nEnter\n1. Enqueue from Rear\n2. Enqueue from Front\n");
        printf("3. Dequeue from Front\n4. Dequeue from Rear\n5. Display\n6. Exit\nEnter here: ");
        scanf("%d", &ch);

        switch(ch){
            
            case 1: enqueueRe(&dq);
                    break;

            case 2: enqueueFr(&dq);
                    break;

            case 3: dequeueFr(&dq);
                    break;

            case 4: dequeueRe(&dq);
                    break;

            case 5: display(&dq);
                    break;

            case 6: exit(0);
                    break;

            default: printf("Check your inputs.\n");
        }
    }

    return 0;
}