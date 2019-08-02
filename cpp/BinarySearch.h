#ifndef CPP_BINARYSEARCH_H
#define CPP_BINARYSEARCH_H
/**
 * 二分查找
 */
class BinarySearch{
public:
    static int firstEqual(int arr[], int size, int target);
    static int lastEqual(int arr[], int size, int target);
    static int firstEqualOrGreater(int arr[], int size, int target);
    static int lastEqualOrSmaller(int arr[], int size, int target);
};

void testBinarySearch();
#endif //CPP_BINARYSEARCH_H
