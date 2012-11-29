#include <malloc.h>
#include <stdio.h>
#include <math.h>

int*
merge(int *left, int *right,int len){
  int *sorted;
  int p = 0;
  int i = 0;
  int j = 0;
  sorted = malloc(sizeof(int)*len*2);
  while(i < len && j < len ){
      if(*(left+i) < *(right+j)){
          *(sorted+p) = *(left+i);
	  i++;
      }else{
          *(sorted+p) = *(right+j);
	  j++;
      }
      p++;
  }
  //copy left elements
  while(p < len*2){
      if(i < j) {
          *(sorted+p) = *(left+i);
	  i++;
      }
      if(j < i){
          *(sorted+p) = *(right+j);
          j++;
      }
      p++;
  }
  //free sorted memory by caller
  return sorted;
}

int*
merge_sort(int *arr, int len){
    if(len == 1)
        return arr;
    int middle = len/2;
    int *left = merge_sort(arr,middle);
    int *right = merge_sort(arr+middle,middle);
    return merge(left,right,middle);
}

int main(void){
   const int LEN = 16;
   int arr[16] = {10,9,8,7,6,5,4,3,2,1,11,12,13,14,15,16};

   printf("arr[");
   int i = 0;
   for(i = 0; i < LEN; i++){
       printf("%d,",arr[i]);
   }
   printf("]\n");
  
   int *sorted = merge_sort(&arr[0],LEN);
   printf("arr[");
   for(i = 0; i < LEN; i++){
      printf("%d,",*(sorted+i));
   }
   printf("]\n");
   free(sorted);
   return 0;
}
