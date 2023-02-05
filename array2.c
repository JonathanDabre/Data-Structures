#include<stdio.h>

void display(int arr[], int size){

    //Traversals
    for(int i =0; i<size; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int insertAt(int index, int arr[], int size, int capacity, int element){
    
    if(index >= capacity){
        printf("Array index out of bounds");
        return 0;
    }
    for(int i= size-1; i>= index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
    
}


int main(){

    int arr[8]= {0, 1, 2, 4 };
    int size = 4;
    int capacity = 8; 
    display(arr, size);

    int element = 3;
    int index = 3;

    if(insertAt(index, arr, size, capacity, element )){
        size++;
    }
    display(arr, size);

    return 0;
}