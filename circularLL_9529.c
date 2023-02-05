/*
Title: Circular Linked List
Roll No: 9529
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* head = NULL;

void append(); 
void addAtbeg();
void display();
void delete(); //delete first occurence

int main(){

    

    int ch;

    while(1){
        printf("\nEnter\n1. Append\n2. Add at start\n3. Display\n4. Delete\n5. Exit\n");
        printf("Enter your choice here:");
        scanf("%d", &ch);

        switch(ch){

            case 1: append(); //Add at end
                    break;
            
            case 2: addAtbeg();
                    break;

            case 3: display();
                    break;
            
            case 4: delete();
                    break;

            case 5: printf("You opted for exit function");
                    exit(0);
                    break; //not needed

            default: printf("Invalid input");
        }
    }    

    return 0;
}

void display(){

    if(head == NULL){
        printf("\nLinked List empty\n");
    }
    else{
        struct node* p;
        p = head;

        do{
            printf("%d\t", p->data);
            p = p->link;
        }
        while(p != head);
        
    }
}

void addAtbeg(){

    struct node* ptr;

    ptr = (struct node*) malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &ptr->data);
    if(head == NULL){
        head = ptr;
        ptr->link = head;
    }
    else{

    struct node* p = head->link; //avoid do while loop
    
    while(p->link != head){
        p = p->link;
    }

    p->link = ptr;
    ptr->link = head;
    head = ptr;
    }
}

void append(){
    
    struct node* ptr;

    ptr = (struct node*) malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &ptr->data);

    if(head == NULL){
        head = ptr;
    }
    else{

        struct node* p = head->link; //to avoid do while, and non performance of while loop
        while(p->link != head){
            p = p->link;
        }
        p->link = ptr;
    }

    ptr->link = head;

}

void delete(){
    int x;
    printf("Enter the element:");
    scanf("%d", &x);

    struct node* p = head;
    struct node* prev = head;

    int flag = -1;
    int count =0;

    do{
        count++;
        if(p->data == x){
            flag =1;
            break;
        }
        prev = p;
        p = p->link;
    }
    while(p->link != head);

    if(count ==1){
        head = p->link;
        struct node* q = head;
        while(q->link != p){
            q = q->link;
        }
        q->link = head;
        free(p);

    }
    else if(flag ==1){
        prev->link = p->link;
        p->link = NULL;
        free(p);
    }
    else{
        printf("Element %d not in the linked list.\n", x);
    }
}


/*
Enter
1. Append
2. Add at start
3. Display
4. Delete
5. Exit
Enter your choice here:1
Enter data:10

Enter
1. Append
2. Add at start
3. Display
4. Delete
5. Exit
Enter your choice here:1
Enter data:20

Enter
1. Append
2. Add at start
3. Display
4. Delete
5. Exit
Enter your choice here:1
Enter data:30

Enter
1. Append
2. Add at start
3. Display
4. Delete
5. Exit
Enter your choice here:3
10      20      30
Enter
1. Append
2. Add at start
3. Display
4. Delete
5. Exit
Enter your choice here:2
Enter data:5

Enter
1. Append
2. Add at start
3. Display
4. Delete
5. Exit
Enter your choice here:3
5       10      20      30
Enter
1. Append
2. Add at start
3. Display
4. Delete
5. Exit
Enter your choice here:4
Enter the element:20

Enter
1. Append
2. Add at start
3. Display
4. Delete
5. Exit
Enter your choice here:3
5       10      30
Enter
1. Append
2. Add at start
3. Display
4. Delete
5. Exit
Enter your choice here:5
You opted for exit function
*/