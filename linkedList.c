#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link; //Address of next
};

struct node* root = NULL; //Global variable for access to all functions


void append(); //Add at end
int length();
void addAtbeg();
void insertAf();
void display();
void delete();

int main(){

    int ch;

    while(1){
        printf("\nEnter\n1. Append\n2. Add at start\n3. InsertAfter\n4. Display\n5. Delete\n6. Exit\n");
        printf("Enter your choice here:");
        scanf("%d", &ch);

        switch(ch){

            case 1: append(); //Add at end
                    break;
            
            case 2: addAtbeg();
                    break;

            case 3: insertAf();
                    break;

            case 4: display();
                    break;
            
            case 5: delete();
                    break;

            case 6: printf("You opted for exit function");
                    exit(0);
                    break; //not needed

            default: printf("Invalid input");
        }
    }    

    return 0;
}

void append(){
    struct node* temp;
    temp =(struct node*) malloc(sizeof(struct node));

    printf("\nEnter data here:");
    scanf("%d", &temp->data);

    temp->link = NULL; //NULL indicating that this node will be at end of linked list.

    if(root == NULL){
        root = temp;
    }
    else{
        struct node* p;
        p = root;
        while(p->link != NULL){
            p= p->link;
        }
        p->link = temp;
    }
}


int length(){
    struct node* p;
    int count = 0;

    p = root; //Now p points to first node

    while(p != NULL){
        count++;
        p= p->link;
    }
    //loop terminates means now p points to NULL

    return count;
}


void addAtbeg(){
    struct node* temp;
    temp = (struct node*) malloc(sizeof(struct node));
    printf("Enter data here:");
    scanf("%d", &temp->data);
    temp->link = root;
    root = temp;
}


void insertAf(){
    int n;
    printf("Enter after which position you want to insert:");
    scanf("%d", &n);
    
    int len = length();

    if(n>len){
        //Cannot enter after a node which doesn't exist
        printf("Invalid Position\n");
    }
    else{
        struct node* temp;
        struct node* p;

        temp = (struct node*) malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &temp->data);
        
        n--; //to reach the node we need 1 less step than the node number

        p=root;
        while(n--){
            p= p->link;
        }
        temp->link = p->link;
        p->link = temp;
    }   
}


void display(){
    struct node* p;
    p = root;

    if(p == NULL){
        printf("No nodes in the list\n");
    }
    else{
        while(p != NULL){
            printf("%d\t", p->data);
            p = p->link;
        }
        printf("\n");
    }

}




void delete(){
    int loc;
    printf("Enter the location:");
    scanf("%d", &loc);

    struct node* p;

    if(loc > length()){
        printf("Invalid location\n");
    }
    else if(loc == 1){ 
        p = root;
        root = p->link;
        p->link = NULL; //should not be connected to any node
        free(p);// freeing the deleted node
    }
    else{
        int i =1;
        struct node* q;
        p = root;
        while(i< loc-1){
            p = p->link;
            i++;
        }

        q= p->link;
        p->link = q->link;
        q->link = NULL; //should not point to any location.

        free(q);

    }
}