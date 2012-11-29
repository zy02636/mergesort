#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
    int *arr;
    arr = malloc(sizeof(int)*4);
    *arr = 1;
    printf("arr[0]:%d \n",*arr);
    *(arr+1) = 2;
    printf("arr[1]:%d \n",*(arr+1));
 
    *(arr+2) = 3;
    printf("arr[2]:%d \n",*(arr+2));
    *(arr+3) = 4;
    printf("arr[3]:%d \n",*(arr+3));
    printf("arr: %d %d %d %d",*(arr),*(arr+1),*(arr+2),*(arr+3));
    free(arr);
    return 0;
}
