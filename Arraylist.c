#include "stdlib.h"
#include <stdio.h>


typedef struct Arraylist {
    int length;
    int size;
    int* array;
} Arraylist;

Arraylist initArray(){
    int* arr = malloc(sizeof(int));
    Arraylist array = {1, 0, arr};
    return array;
}

void addArray(Arraylist* arr, int num){
    if (arr->length == arr->size) {
        int newLength = arr->length * 2;
        int* newarr = malloc(sizeof(int) * newLength);
        for (int i = 0; i < arr->length; i++) {
            newarr[i] = arr->array[i];
        }
        arr->length = newLength;
        free(arr->array);
        arr->array = newarr;
    }
    arr->array[arr->size++] = num;
}

void printArrayList(Arraylist* arr){
    printf("[%d",arr->size);
    printf("/%d]",arr->length);
    printf("[");
    for (int i = 0; i < arr->size - 1; i++) {
        printf("%d, ", arr->array[i]);
    }
    printf("%d]\n", arr->array[arr->size - 1]);
}

//0 if true, 1 if false.
int deleteArrayAt(Arraylist* arr, int i){
    if (i < 0 || i > arr->length) {
        return 1;
    }
    for (int j = i + 1; j < arr->size; j++) {
        arr->array[j - 1] = arr->array[j];
    }
    arr->size--;
    return 0;
}

int main(){
    Arraylist arr = initArray();
    for (int i; i < 5; i++) {
        addArray(&arr, i);
    }
    addArray(&arr, 0);
    addArray(&arr, 1);
    printArrayList(&arr);
    deleteArrayAt(&arr, 2);
    printArrayList(&arr);
    return 0;
}