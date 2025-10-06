
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
//#define SIZE 6

void swapNumbers(int* num1, int* num2){

    int temp = *num1;
    *num1 = *num2;
    *num2 = temp; 
}

void sort(int array[],int sizeofArray){

    int i,j;

    for(i = 0; i < sizeofArray - 1;i++){
        for(j = 0; j < sizeofArray - i - 1; j++){
            if(array[j] > array[j+1]){
            swapNumbers(&array[j],&array[j+1]);
            }
         }
    }
 }

int leftArray[SIZE];
int rightArray[SIZE];

int main(int argc, char** argv)
{

    FILE* fptr = fopen("/Users/bhavana/Desktop/Intro/data.txt","r");
    int j = 0;
    int list[SIZE];
    int value = 0;
    int count = 0;
    int finalValue = 0;

    if(fptr == NULL){
        printf("%p The file cannot be opened\n",fptr);
        return 1;
    }

while(fscanf(fptr,"%d   %d",&leftArray[j],&rightArray[j]) == 2){
    j++;
    if (j >= SIZE) break;
}
    fclose(fptr);

    
    sort(leftArray,j);
    sort(rightArray,j);


// Here, we are checking how many times the element from leftarray appears in the right array
    for(int i = 0; i < SIZE; i++){
        count = 0;
        value = leftArray[i];
        for(int j = 0; j < SIZE; j++){
        if(value == rightArray[j])count++;
        }
    list[i] = count * value;
    printf("%d is the value \n",list[i]);

    }

       for(int i = 0;i < SIZE; i++){
        finalValue = finalValue + list[i];
    }

    printf("%d: this is the sum",finalValue);


    return 0;
}