#include<stdio.h>
#include<stdlib.h>

struct node {

    struct node* left;
    int data;
    struct node* right;
};

struct node* createNode(int d);
void preOrder(struct node* root);
void postOrder(struct node* root);
void inOrder(struct node* root);

int main(){

    struct node* p1;
    struct node* p2;
    struct node* p3;
    struct node* p4;
    struct node* p5;

    p1 = createNode(5);
    
    p2 = createNode(3);
    p1->left = p2;

    p3 = createNode(1);
    p2->left = p3;

    p4 = createNode(4);
    p2->right = p4;

    p5 = createNode(6);
    p1->right = p5;

    preOrder(p1);
    printf("\n");

    postOrder(p1);
    printf("\n");

    inOrder(p1);

    return 0;
}

struct node* createNode(int d){

    struct node* n;

    n = (struct node*) malloc(sizeof(struct node));
    n->data = d;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void preOrder(struct node* root){
    if(root != NULL){
        printf("%d", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d", root->data);
    }
}

void inOrder(struct node* root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d", root->data);
        inOrder(root->right);
    }
}