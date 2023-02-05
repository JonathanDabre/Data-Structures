/*
Title: Queue using linked list
Roll No.: 9529
*/
#include <stdio.h>
#include <stdlib.h>

//Node of linked list
struct node {
    int data;
    struct node* next;
};

//queue data structure. 2 pointers: front & rear
struct queue{
    struct node* front;
    struct node* rear;
};

void enqueue(struct queue* q);
void dequeue(struct queue* q);
void frontEl(struct queue* q);
void display(struct queue* q);
int totalEl(struct queue* q);

//main function
int main(){

    struct queue q;
    q.front = NULL;
    q.rear = NULL;

    int ch;

    while(1){

        printf("Enter\n1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n5. Total elements\n6. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);

        switch(ch){

            case 1: enqueue(&q);
                    break;

            case 2: dequeue(&q);
                    break;

            case 3: frontEl(&q);
                    break;

            case 4: display(&q);
                    break;

            case 5: printf("Total elements in queue: %d\n", totalEl(&q));
                    break;

            case 6: printf("\nJonathan Dabre 9529 signing off");
                    exit(0);
                    break;

            default: printf("Invalid inputs");
        }
    }






    return 0;
}

void enqueue(struct queue* q){

    struct node* temp;
    temp =(struct node*)malloc(sizeof(struct node));
    temp->next = NULL;

    printf("Enter data:");
    scanf("%d", &temp->data);
    if(q->front == NULL){
        q->front = temp;
        q->rear = temp;
    }
    else{
        q->rear->next = temp;
        q->rear = temp;
    }

}

void dequeue(struct queue* q){

    if(q->front == NULL){
        printf("Queue is empty\n");
    }
    else{
        struct node* p; //temporary pointer
        p = q->front;
        printf("Dequeued element: %d\n", p->data);
        q->front = p->next;
        free(p);
    }
}

void frontEl(struct queue* q){
    if(q->front == NULL){
        printf("Queue is empty\n");
    }
    else{
        printf("The front element: %d\n", q->front->data);
    }
}

void display(struct queue* q){
    struct node* p;  //temporary pointer
    p = q->front;

    while(p != NULL){
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

int totalEl(struct queue* q){
    struct node* p;
    p = q->front;
    int count =0;

    while( p != NULL){
        count ++;
        p = p->next;
    }

    return count;
}

/* 

Enter
1. Enqueue
2. Dequeue
3. Front
4. Display
5. Total elements
6. Exit
Enter your choice:5
Total elements in queue: 0
Enter
1. Enqueue
2. Dequeue
3. Front
4. Display
5. Total elements
6. Exit
Enter your choice:1
Enter data:10
Enter
1. Enqueue
2. Dequeue
3. Front
4. Display
5. Total elements
6. Exit
Enter your choice:1
Enter data:20
Enter
1. Enqueue
2. Dequeue
3. Front
4. Display
5. Total elements
6. Exit
Enter your choice:1
Enter data:30
Enter
1. Enqueue
2. Dequeue
3. Front
4. Display
5. Total elements
6. Exit
Enter your choice:1
Enter data:40
Enter
1. Enqueue
2. Dequeue
3. Front
4. Display
5. Total elements
6. Exit
Enter your choice:4
10      20      30      40
Enter
1. Enqueue
2. Dequeue
3. Front
4. Display
5. Total elements
6. Exit
Enter your choice:3
The front element: 10
Enter
1. Enqueue
2. Dequeue
3. Front
4. Display
5. Total elements
6. Exit
Enter your choice:2
Dequeued element: 10
Enter
1. Enqueue
2. Dequeue
3. Front
4. Display
5. Total elements
6. Exit
Enter your choice:4
20      30      40
Enter
1. Enqueue
2. Dequeue
3. Front
4. Display
5. Total elements
6. Exit
Enter your choice:5
Total elements in queue: 3
Enter
1. Enqueue
2. Dequeue
3. Front
4. Display
5. Total elements
6. Exit
Enter your choice:6

Jonathan Dabre 9529 signing off

*/