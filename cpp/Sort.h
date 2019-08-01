#ifndef SINGLELIST_SORT_H
#define SINGLELIST_SORT_H
/**
 * 各种排序算法
 */
class Sort{
public:
    static void bubbleSort(int arr[], int size);
    static void insertionSort(int arr[], int size);
    static void selectionSort(int arr[], int size);
    static void mergeSort(int arr[], int size);
    static void quickSort(int arr[], int size);
    static int  topk(int arr[], int size, unsigned int k);
    static void countingSort(int arr[], int size);

private:
    static void merge(int arr[], int start, int p, int end);
    static void mergeSort(int arr[], int start, int end);
    static int  partition(int arr[], int start, int end);
    static void quickSort(int arr[], int start, int end);
};

void testSort();

#endif //SINGLELIST_SORT_H
