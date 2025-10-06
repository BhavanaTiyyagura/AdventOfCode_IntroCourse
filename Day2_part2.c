#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int NoOfSafeReports = 0;

bool checkFirstRule (int array[], int n){ 

    bool increasing_flag = false;
    bool decreasing_flag = false;
    for (int i=0;i<n-1;i++){
        if(array[i] > array [i+1])
        decreasing_flag = true;

        else if(array[i] < array[i+1])
        increasing_flag = true;

        else
        return false;
    }

    if(decreasing_flag && increasing_flag == true )
    return false;

    else
    return true;
}

bool checkSecondRule(int array[],int n){

    int res = 0;

    for (int i = 0; i < n-1; i++){

        res = abs(array[i] - array[i+1]);
        
        if(res >= 1 && res <= 3)
            continue;
        else
            return false;
    }

    return true;


}

int main(int argc, char** argv)
{


    char buffer[50];
    int count;
    FILE* fptr = fopen("/Users/bhavana/Desktop/Intro/data2.txt","r");

    if (fptr == NULL) {
        perror("Failed to open file");
        return 1;
    }

    while(fgets(buffer,sizeof(buffer),fptr)){
        count = 0;
        char *temp = strdup(buffer);

        char* token = strtok(temp," \n");
        while (token != NULL) {
            count++;
            token = strtok(NULL, " \n");
        }

        free(temp);

        int *valueBuff = malloc(count * sizeof(int));

        int index = 0;

        token = strtok(buffer, " \n");
        while (token != NULL) {
            valueBuff[index] = atoi(token);
            index++;
            token = strtok(NULL, " \n");
        }
   
    if (checkFirstRule(valueBuff, count) && checkSecondRule(valueBuff, count)) {
        NoOfSafeReports++;
    }

    else
        {
            for (int i = 0; i < count; i++) {
            int tempArray[count-1];
            int index = 0;

                for(int j = 0; j < count; j++){
                    if (j != i) {
                    tempArray[index++] = valueBuff[j];
                    }
                }
                if (checkFirstRule(tempArray, count-1) && checkSecondRule(tempArray, count-1)) {
                    NoOfSafeReports++;
                    break;
                }

        }

        free(valueBuff);

    }

    }

    printf("no of total safe repors are %d\n",NoOfSafeReports);
    return 0;
}

