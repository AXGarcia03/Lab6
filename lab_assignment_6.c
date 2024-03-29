#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) {
    if (low > high) {
        // Base case: value not found
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (numbers[mid] == value) {
        // Value found at index mid
        return mid;
    } else if (numbers[mid] < value) {
        // Search the right half
        return search(numbers, mid + 1, high, value);
    } else {
        // Search the left half
        return search(numbers, low, mid - 1, value);
    }
}

void printArray(int numbers[], int sz) {
    int i;
    printf("Number array : ");
    for (i = 0; i < sz; ++i) {11
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main(void) {
    int i, numInputs;
    int value;
    int index;
    int* numArray = NULL;
    int countOfNums;
    FILE* inFile = fopen("input.txt", "r");

    fscanf(inFile, " %d\n", &numInputs);

    while (numInputs-- > 0) {
        fscanf(inFile, " %d\n", &countOfNums);
        numArray = (int*)malloc(countOfNums * sizeof(int));
        for (i = 0; i < countOfNums; i++) {
            fscanf(inFile, " %d", &value);
            numArray[i] = value;
        }

        printArray(numArray, countOfNums);
        value = (numArray[0] + numArray[countOfNums - 1]) / 2;
        index = search(numArray, 0, countOfNums - 1, value);
        if (index >= 0) {
            printf("Item %d exists in the number array at index %d!\n", value, index);
        } else {
            printf("Item %d does not exist in the number array!\n", value);
        }

        free(numArray);
    }

    fclose(inFile);
    return 0;
}
