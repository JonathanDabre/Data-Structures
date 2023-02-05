#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct queue* q){
    if((q->r +1) % (q->size) == q->f){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct queue* q){
    
    if(q->f == -1 && q->r == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue* q){
    if( isFull(q) ){
        printf("Queue is full.\n");
    }
    else{
        if(q->r == -1){
            q->f = (q->f + 1) % (q->size);  //When element inserted for 1stEver time.
        }

        q->r = (q->r + 1) % (q->size);
        printf("Enter Data: ");
        scanf("%d", &q->arr[q->r]);
    }
}

void dequeue(struct queue* q){
    if( isEmpty(q) ){
        printf("Queue is empty.\n");
    }
    else{
        printf("The dequeued element: %d", q->arr[q->f]);

        if((q->f) % (q->size) == (q->r) % (q->size)){

            q->f = -1;
            q->r = -1;
        }
        else{
            q->f = (q->f + 1) % (q->size);
        }
        
    }
}

void display(struct queue* q){
    if(q->r == q->f){
        printf("Nothing to display.\n");
    }
    else{

        int i = q->f;

        do{
            
            printf("%d\t", q->arr[i]);
            i = (i+1) % (q->size);

        }while(i != (q->r + 1) % (q->size));
    }
}

int main(){

    struct queue cq;
    cq.size = 4;
    cq.f = -1;
    cq.r =-1;

    cq.arr = (int* ) malloc(cq.size * sizeof(int));
    
    int ch;

    while(1){
        printf("\nEnter\n1. Enqueue\n2. Deqeue\n3. Disply\n4. Exit\nEnter here: ");
        scanf("%d", &ch);

        switch(ch){
            case 1: enqueue(&cq);
                    break;

            case 2: dequeue(&cq);
                    break;

            case 3: display(&cq);
                    break;

            case 4: exit(0);
                    break;

            default: printf("Check your inputs\n");
        }
    }

    return 0;
}