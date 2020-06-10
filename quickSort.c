//
// Created by xhj on 2020/6/9.
//
#include <stdio.h>
#include <stdbool.h>


void quickSort(int *arr, int left, int right);
int partition(int *arr, int left, int right);
void quickSortAlgs4(int *arr, int left, int right);//algs4中的quick sort


int main(void ){
    int arr[]={2, 4, 1, 3, 5};
    int length = sizeof(arr) / sizeof(int);
    quickSortAlgs4(arr, 0, length - 1);
    for (int i = 0; i < length; ++i) {
        printf("    %d", arr[i]);
    }
    return 0;
}

void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void quickSortAlgs4(int *arr, int left, int right){
    if (left < right){
        int pivot = partition(arr, left, right);
        quickSortAlgs4(arr, left, pivot - 1);
        quickSortAlgs4(arr, pivot + 1, right);
    }
}

int partition(int *arr, int left, int right){
    int pivot = left;
    int i = left ,j = right + 1;
    while (true){
        while(arr[++i] < arr[pivot]){
            if (i == right) break;
        }
        while(arr[pivot] < arr[--j]){
            if (j == left) break;
        }
        if(i >= j) break;
        swap(&arr[i], &arr[j]);
    }
    swap(&arr[pivot], &arr[j]);

    return j;
}

void quickSort(int *arr, int left, int right){
    int i = left, j = right, pivot = (left + right)/2;
    while (i <= j){
        while (arr[i] < arr[pivot])
            ++i;
        while (arr[j] > arr[pivot])
            --j;
       if (i <= j){
           int temp = arr[j];
           arr[j]= arr[i];
           arr[i] = temp;
           ++i;
           --j;
       }
    }
    if(i < right) quickSort(arr, i, right);
    if(j > left) quickSort(arr, left, j);
}