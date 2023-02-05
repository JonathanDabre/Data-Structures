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
int isBST(struct node* root,  struct node* min, struct node* max);
struct node* search(struct node* root, int key);
struct node* insert(struct node* root, int key);

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
    printf("\n%d", isBST(p1));

    struct node* q = search(p1, 4);

    if(q == NULL){
        printf("\nElement not found");
    }
    else{
        printf("\nFound: %d", q->data);
    }

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

// int isBST(struct node* root){

//     if(root != NULL){

//         static struct node* prev = NULL; //
//         if(!isBST(root->left)){
//             return 0; //if left subtree is bst, this step won't be performed
//         }
//         if(prev != NULL && root->data <= prev->data){
//             return 0;
//         }
//         prev = root;

//         return isBST(root->right);
//     }
//     else{
//         //that means if root is null
//         return 1; //yes its bst // On 1st entry condition
//     }
// }

int isBST(struct node* root, struct node* min, struct node* max){
    if(root == NULL){
        return 1;
    }
    if(min != NULL && root->data <= min->data){
        return 0;
    }
    if(max != NULL && root->data >= max->data){
        return 0;
    }

    int leftValid = isBST(root->left, min, root)
}

struct node* search(struct node* root, int key){

    if(root == NULL){
        return NULL;
    }

    if(key == root->data){
        return root;
    }
    else if( key <= root->data){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

struct node* insert(struct node* root, int key){
    struct node* prev;
    struct node* ptr;

    while(root != NULL){

        prev = root;
        if(key == root->data){
            return root;;
        }
        else if( key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }

    ptr = createNode(key);

    if(key<prev->data){
        prev->left= ptr;
    }
    else{
        prev->right = ptr;
    }
    
}