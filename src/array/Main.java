package array;

public class Main{
    public static void main(String[] args){
        mergeSort();
    }

    private static void genericArrayTest(){
        GenericArray<Integer> array = new GenericArray<>(3);
        array.add(1);
        array.add(2);
        array.add(3);
        array.add(4);
        System.out.println(array.remove(1));
        System.out.println(array.remove(1));
        System.out.println(array.remove(5));
        System.out.println(array.getCapacity());
        System.out.println(array.getSize());
        System.out.println(array);
    }

    private static void orderedArrayTest(){
        OrderedArray<Integer> arr = new OrderedArray<>(3, OrderedArray.ASC);
        arr.insert(3);
        arr.insert(1);
        arr.insert(2);
        System.out.println(arr);

        OrderedArray<Integer> arr2 = new OrderedArray<>(3, OrderedArray.ASC);
        arr2.insert(3);
        arr2.insert(2);
        arr2.insert(5);
        System.out.println(arr2);

    }

    private static void mergeSort(){
        int[] arr1 = new int[]{1,2,3};
        int[] arr2 = new int[]{3,4,5};
        int[] newArr = new int[arr1.length + arr2.length];

        int index1 = 0, index2 = 0, index = 0;

        while (index1 < arr1.length && index2 < arr2.length){
            if (arr1[index1] > arr2[index2]){
                newArr[index] = arr2[index2];
                index2++;
            }else{
                newArr[index] = arr1[index1];
                index1++;
            }
            index++;
        }
        while (index1 < arr1.length){
            newArr[index] = arr1[index1];
            index++;
            index1++;
        }

        while (index2 < arr2.length){
            newArr[index] = arr2[index2];
            index++;
            index2++;
        }

        for (int i : newArr) {
            System.out.println(i);
        }

    }

}