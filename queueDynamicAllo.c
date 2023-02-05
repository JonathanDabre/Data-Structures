/*
Title: Queue
Roll No: 9529
*/
#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int r;
    int f;
    int* arr;
};

int isFull(struct queue* q);
int isEmpty(struct queue* q);
void enqueue(struct queue* q);
void dequeue(struct queue* q);
void display(struct queue* q);

int main(){

    struct queue q;
    q.size =10; //Here we can also take input from user for specific size they want.
    q.r= -1;
    q.f= -1;

    //Going for dynamic memory allocation.
    q.arr = (int*) malloc(q.size * sizeof(int));

    int ch;

    while(1){

        printf("\nEnter\n1. Enqueue\n2. Dequeue\n3. isFull\n4. isEmpty\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1: enqueue(&q);
                    break;

            case 2: dequeue(&q);
                    break;

            case 3: if(isFull(&q)){
                        printf("Yes, queue is Full\n");
                    }
                    else{
                        printf("queue not full\n");
                    }
                    break;

            case 4: if(isEmpty(&q)){
                        printf("Yes, queue is empty\n");
                    }
                    else{
                        printf("queue not empty\n");
                    }
                    break;

            case 5: display(&q);
                    break;

            case 6: printf("\nJonathan Dabre 9529 signing off.\n"); //My copyright
                    exit(0);
                    break; //not necessary

            default: printf("Invalid input\n");
        } 
    }

    return 0;
}

int isFull(struct queue* q){
    if(q->r == q->size -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct queue* q){
    if(q->r == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue* q){
    if(isFull(&q)){
        printf("queue overflow\n");
    }
    else{
        
        q->r++;
        printf("Enter data:");
        scanf("%d", &q->arr[q->r]);
    }
}

void dequeue(struct queue* q){

    if(q->r == -1){
        printf("No element in queue\n");
    }
    else{
        q->f++;
        printf("Dequed element: %d\n", q->arr[q->f] );
        for(int i =0; i<q->r; i++){
            q->arr[i] = q->arr[i+1];
        }
        q->r--;
        q->f--;
    }
}

void display(struct queue* q){
    if(!isEmpty(&q)){ //condition can be isEmpty == 0
    
        for(int i= q->f+1; i<= q->r; i++){
            printf("%d\t", q->arr[i]);
        }
        printf("\n");
    }
    else{
            printf("Nothing to display\n");
        }
}


/*
Output

Enter
1. Enqueue
2. Dequeue
3. isFull
4. isEmpty
5. Display
6. Exit
Enter your choice: 1
Enter data:10

Enter
1. Enqueue
2. Dequeue
3. isFull
4. isEmpty
5. Display
6. Exit
Enter your choice: 1
Enter data:20

Enter
1. Enqueue
2. Dequeue
3. isFull
4. isEmpty
5. Display
6. Exit
Enter your choice: 1
Enter data:30

Enter
1. Enqueue
2. Dequeue
3. isFull
4. isEmpty
5. Display
6. Exit
Enter your choice: 1
Enter data:40

Enter
1. Enqueue
2. Dequeue
3. isFull
4. isEmpty
5. Display
6. Exit
Enter your choice: 1
Enter data:50

Enter
1. Enqueue
2. Dequeue
3. isFull
4. isEmpty
5. Display
6. Exit
Enter your choice: 5
10	20	30	40	50	

Enter
1. Enqueue
2. Dequeue
3. isFull
4. isEmpty
5. Display
6. Exit
Enter your choice: 2
Dequed element: 10

Enter
1. Enqueue
2. Dequeue
3. isFull
4. isEmpty
5. Display
6. Exit
Enter your choice: 2
Dequed element: 20

Enter
1. Enqueue
2. Dequeue
3. isFull
4. isEmpty
5. Display
6. Exit
Enter your choice: 5
30	40	50	

Enter
1. Enqueue
2. Dequeue
3. isFull
4. isEmpty
5. Display
6. Exit
Enter your choice: 3
queue not full

Enter
1. Enqueue
2. Dequeue
3. isFull
4. isEmpty
5. Display
6. Exit
Enter your choice: 4
queue not empty

Enter
1. Enqueue
2. Dequeue
3. isFull
4. isEmpty
5. Display
6. Exit
Enter your choice: 2
Dequed element: 30

Enter
1. Enqueue
2. Dequeue
3. isFull
4. isEmpty
5. Display
6. Exit
Enter your choice: 2
Dequed element: 40

Enter
1. Enqueue
2. Dequeue
3. isFull
4. isEmpty
5. Display
6. Exit
Enter your choice: 2
Dequed element: 50


Enter
1. Enqueue
2. Dequeue
3. isFull
4. isEmpty
5. Display
6. Exit
Enter your choice: 6

Jonathan Dabre 9529 signing off.

*/




