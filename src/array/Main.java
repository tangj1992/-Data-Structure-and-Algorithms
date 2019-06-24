package array;

public class Main{
    public static void main(String[] args){
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
}