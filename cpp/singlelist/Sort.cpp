#include "Sort.h"
#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace chrono;

void display(int arr[], unsigned size);
/**
 * 冒泡排序(O(n^2))
 * @param arr
 */
void Sort::bubbleSort(int arr[], int size){
    int tmp = 0;
    for (int i = 0; i < size; ++i) {
        bool flag = false;
        for (int j = 0; j < size - i - 1; ++j) {
            if(arr[j] > arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                flag = true;
            }

            if(!flag){
                break;
            }
        }
    }
}
/**
 * 插入排序(O(n^2))
 * @param arr
 * @param size
 */
void Sort::insertionSort(int arr[], int size){
    for (int i = 1; i < size; ++i) {
        int value = arr[i];
        int j = i - 1;
        for (; j >= 0; --j) {
            if(arr[j] > value){
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1] = value;
    }
}
/**
 * 选择排序(O(n^2))
 * @param arr
 * @param size
 */
void Sort::selectionSort(int arr[], int size){
    int tmp = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (arr[i] > arr[j]){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
/**
 * 归并排序(O(nlogn))
 * @param arr
 * @param size
 */
void Sort::mergeSort(int arr[], int size){
    mergeSort(arr, 0, size - 1);
}
void Sort::mergeSort(int arr[], int start, int end){
    if (start >= end){
        return;
    }
    int p = (end + start) / 2;

    mergeSort(arr, start, p);
    mergeSort(arr, p + 1, end);

    merge(arr, start, p, end);
}
void Sort::merge(int arr[], int start, int p, int end){
    int tmp[end - start + 1];
    int i = start, j = p + 1, k = 0;
    while ((i <= p) && (j <= end)){
        if (arr[i] > arr[j] ){
            tmp[k++] = arr[j++];
        }else{
            tmp[k++] = arr[i++];
        }
    }

    int start2 = i ;
    int end2   = p + 1;
    if (j <= end){
        start2 = j;
        end2 = end;
    }

    while (start2 <= end2){
        tmp[k++] = arr[start2++];
    }

    for (int l = 0; l < (end - start + 1); ++l) {
        arr[start + l] = tmp[l];
    }

}

/**
 * 快速排序(O(nlogn))
 * @param arr
 * @param size
 */
void Sort::quickSort(int arr[], int size){
    quickSort(arr, 0,size - 1);
}
void Sort::quickSort(int arr[], int start, int end){
    if(start >= end){
        return;
    }
    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1 );
    quickSort(arr, p + 1, end);
}

int Sort::partition(int arr[], int start, int end){
    int pivot = arr[end];
    int i = start;
    int tmp = 0;
    for (int j = start; j < end; ++j) {
        if (arr[j] < pivot){
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
            i++;
        }
    }
    tmp = arr[i];
    arr[i] = arr[end];
    arr[end] = tmp;

    return i;
}


void display(int arr[], unsigned size){
    cout << "array: [";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] ;
        if (i != size - 1){
            cout << ",";
        }
    }
    cout << "]" << endl;
}
void testSort(){
    default_random_engine e;
    int size = 10000;
    int arr[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = e();
    }

    auto  start = system_clock::now();

//    Sort::bubbleSort(arr, size);
//    Sort::insertionSort(arr, size);//0.074004
//    Sort::selectionSort(arr, size);//0.257014
//    Sort::mergeSort(arr, size);
    Sort::quickSort(arr, size);
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << double(duration.count()) * microseconds::period::num / microseconds::period::den  << endl;

//    display(arr, size);
}