
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void swapNumbers(int* num1, int* num2){

    int temp = *num1;
    *num1 = *num2;
    *num2 = temp; 
}

void sort(int array[],int sizeofArray){   //bubble sort implementation                           

    int i,j;

    for(i = 0; i < sizeofArray - 1;i++){
        for(j = 0; j < sizeofArray - i - 1; j++){
            if(array[j] > array[j+1]){
            swapNumbers(&array[j],&array[j+1]);
            }
         }
    }
 }

int leftArray[1000];
int rightArray[1000];

int main(int argc, char** argv)
{

    FILE* fptr = fopen("/Users/bhavana/Desktop/Intro/data.txt","r");
    int j = 0;
    int list[1000];
    int value = 0;

    if(fptr == NULL){
        printf("%p The file cannot be opened\n",fptr);
        return 1;
    }

// Reading the each line, which has two elements, into their respective arrays
while(fscanf(fptr,"%d   %d",&leftArray[j],&rightArray[j]) == 2){
    j++;
    if (j >= 1000) break;
}
    fclose(fptr);

    
    sort(leftArray,j);
    sort(rightArray,j);

// Calculate the absolute value of the difference between the elements
    for(int i = 0;i < 1000; i++){
        list[i] = abs(leftArray[i] - rightArray[i]);
        printf("Value is: %d\n",list[i]);
        value = value + list[i];
    }

    printf("%d: this is the sum",value);


    return 0;
}