/*
Operation on Arrays
Traversal- Basically displaying elements, at least visit each element of array once
Insertion 
Deletion
Searching
*/

#include<stdio.h>
#include<stdlib.h>

//Array structure
struct myArr{
    int total_size; //capacity
    int used_size;
    int *ptr;
};

void createArray(struct myArr* a, int tSize, int uSize){

    a->ptr = (int *) malloc(tSize * sizeof(int));
    a->total_size = tSize;
    a->used_size = uSize;
    
}

void showArray(struct myArr* a){

    printf("\n");
    for(int i = 0; i< a->used_size; i++){
        printf("%d\t", (a->ptr)[i]);
    }
    printf("\n");
}

void setValue(struct myArr* a){

    printf("\nStart entering the elements\n");

    for(int i=0; i<a->used_size; i++){
        printf("Enter element at index %d: ", i);
        scanf("%d", &(a->ptr)[i]);
    }
    printf("\n");
}

void insertAt(struct myArr* a){
    if(a->used_size == a->total_size){
        printf("Oops! array already full.\n");
    }
    else{
        int n;
        printf("Enter index: ");
        scanf("%d", &n);

        if(n>= a->total_size){
            printf("Oops! array index out of bounds.\n");
        }
        else if(n>= a->used_size){
            printf("Element will be inserted at index:%d\n", a->used_size);
            printf("Enter data: ");
            scanf("%d", &a->ptr[a->used_size]);
            a->used_size ++;
        }
        else{
            for(int i = a->used_size -1; i>= n; i--){
                a->ptr[i+1] = a->ptr[i];
            }
            a->used_size++;
            printf("Enter data: ");
            scanf("%d", &a->ptr[n]);
        }
    }
}

void deleteAt(struct myArr* a){
    if(a->used_size == 0){
        printf("Oops! array empty.\n");
    }
    else{
        int n;
        printf("Enter index: ");
        scanf("%d", &n);

        if(n>= a->used_size || n>= a->total_size){
            printf("Check your index.\n ");
        }
        else{
            printf("Element: %d removed.\n", a->ptr[n]);
            for(int i =n; i< a->used_size-1; i++){
                a->ptr[i] = a->ptr[i+1];
            }
            a->used_size--;
        }
    }
}

int linearSearch(struct myArr* a){
    if(a->used_size == 0){
        printf("Array is empty.\n");
    }
    else{
        int ele;
        printf("Enter element: ");
        scanf("%d", &ele);

        for(int i =0; i<a->used_size; i++){
            if( a->ptr[i] == ele){
                printf("%d found at index: %d\n",ele, i);
                return i;
            }
        }
        printf("%d not found.\n", ele);
        return -1;
    }
}

//Binary search using loop
int binarySearch(struct myArr* a){

    int c;
    showArray(a);
    printf("Enter 1: if the above array is sorted\nEnter 2: if its not\nEnter: ");
    scanf("%d", &c);
    if(c==1){
        int ele;
        printf("Enter element: ");
        scanf("%d", &ele);

        int mid, high, low;
        low = 0;
        high = a->used_size -1;


        while(low <= high){
            mid = (low + high)/ 2;

            if(a->ptr[mid] == ele){
                printf("Element found at index: %d\n", mid);
                return mid;
            }
            else if(a->ptr[mid]< ele){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
    }
    else{
        return -1;
    }
}

//Binary search using recursion
// int binary_search(int low, int high, struct myArr* a){

//     int mid = (low + high)/ 2;
// 
//     if(a->ptr[mid] == ele){
//         printf("Element found out at index: %d\n", mid);
//         return 1;
//     }
//     else if( ele > a->ptr[mid]){
//         binary_search(mid+1, high, a, ele);
//     }
//     else if( ele < a->ptr[mid]){
//         binary_search(low, mid-1, a, ele);
//     }
//     else{
//         return -1;
//     }
// }

//Main
int main(){

    struct myArr arr;

    int ch, total, use;

    printf("Enter array details.\n");
    printf("Enter total size:");
    scanf("%d", &total);
    printf("Enter size to use for now:");
    scanf("%d", &use);

    createArray(&arr, total, use);
    setValue(&arr);



    while(1){

        printf("\nEnter\n1. Insert at index\n2. Delete element at index\n3. Display\n4. Search\n5. Exit\n");
        printf("Enter your choice here: ");
        scanf("%d", &ch);

        switch(ch){

            case 1: insertAt(&arr);
                    break;

            case 2: deleteAt(&arr);
                    break;

            case 3: showArray(&arr);
                    break;

            case 4: //binary_search(0, arr.used_size, &arr, 30);
                    binarySearch(&arr);
                    break;

            case 5: printf("\nExit option choosen\nJonathan Dabre signing off\n");
                    exit(0);
                    break;

            default: printf("Make sure your inputs are correct\n");

        }
    }

    return 0;
}