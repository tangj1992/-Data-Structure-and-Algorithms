#include "BinarySearch.h"
#include <iostream>
using namespace std;
/**
 * 首个等于给定值的位置
 * @param arr
 * @param size
 * @param target
 * @return
 */
int BinarySearch::firstEqual(int arr[], int size, int target){
    int low = 0, high = size - 1;
    int mid;
    while (low <= high){
        mid = low + ((high - low) >> 1);
        if (arr[mid] > target){
            high = mid - 1;
        }else if(arr[mid] < target) {
            low = mid + 1;
        }else{
            if ((mid == 0) || (arr[mid - 1] != target)){
                return mid;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}
/**
 * 最后一个等于给定值的位置
 * @param arr
 * @param size
 * @param target
 * @return
 */
int BinarySearch::lastEqual(int arr[], int size, int target){
    int low = 0, high = size - 1;
    int mid;
    while (low <= high){
        mid = low + ((high - low) >> 1);
        if (arr[mid] > target){
            high = mid - 1;
        }else if(arr[mid] < target) {
            low = mid + 1;
        }else{
            if ((mid == size - 1) || (arr[mid + 1] != target)){
                return mid;
            } else {
                low = mid + 1;
            }
        }
    }

    return -1;
}

/**
 * 第一个大于等于给定值的位置
 * @param arr
 * @param size
 * @param target
 * @return
 */
int BinarySearch::firstEqualOrGreater(int arr[], int size, int target){
    int low = 0, high = size - 1;
    int mid;
    while (low <= high){
        mid = low + ((high - low) >> 1);
        if (arr[mid] >= target){
            if ((mid == 0) || (arr[mid - 1] < target)){
                return mid;
            } else {
                high = mid - 1;
            }
        }else if(arr[mid] < target) {
            low = mid + 1;
        }
    }

    return -1;
}
/**
 * 最后一个小于等于给定值的位置
 * @param arr
 * @param size
 * @param target
 * @return
 */
int BinarySearch::lastEqualOrSmaller(int arr[], int size, int target){
    int low = 0, high = size - 1;
    int mid;
    while (low <= high){
        mid = low + ((high - low) >> 1);
        if (arr[mid] > target){
            high = mid - 1;
        }else if(arr[mid] <= target) {
            if ((mid == size - 1) || (arr[mid + 1] > target)){
                return mid;
            } else {
                low = mid + 1;
            }
        }
    }

    return -1;
}

void testBinarySearch(){
    unsigned  int size = 10;
    int arr[] = {1,2,3,3,3,3,7,8,9,10};

    for (int j = 0; j < size; ++j) {
        cout << arr[j] << ",";
    }
    cout << endl;

    cout << BinarySearch::firstEqual(arr, size, 3) << endl;
    cout << BinarySearch::lastEqual(arr, size, 3) << endl;
    cout << BinarySearch::firstEqualOrGreater(arr, size, 4) << endl;
    cout << BinarySearch::lastEqualOrSmaller(arr, size, 4) << endl;
}