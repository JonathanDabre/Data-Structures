#include<stdio.h>

int arr_sum(int arr[10][10], int r, int c);

int main(){
    int r,c;
    printf("\n Enter number of rows and column:");
    scanf("%d %d", &r, &c);

    int arr[10][10];

    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("\n Enter element:");
            scanf("%d", &arr[i][j]);
        }
    }
    int result= arr_sum(arr, r, c);
    printf("\n The sum of elements is %d", result);

    return 0;
}

int arr_sum(int arr[10][10], int r, int c){
    int sum=0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            sum= sum + arr[i][j];   
        }
    }
    return sum;    
}