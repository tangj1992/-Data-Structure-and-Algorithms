package array;

/**
 * 大小固定的有序数组
 * @author tangjun
 * @date 2019/6/24 10:56
 */
public class OrderedArray<T extends Comparable>{
    private static final int DEFAULT_CAPACITY = 10;
    public static final int ASC = 1;
    public static final int DESC = 2;

    private Object[] data;
    private int size;
    private int orderBy;

    public OrderedArray(int capacity){
        this.data = new Object[capacity];
        this.size = 0;
        this.orderBy = ASC;
    }
    public OrderedArray(int capacity, int orderBy){
        this.data = new Object[capacity];
        this.size = 0;
        this.orderBy = orderBy;
    }
    public OrderedArray(){
        this(DEFAULT_CAPACITY);
    }

    /**
     * 获取数组容量
     * @return
     */
    public int getCapacity(){
        return data.length;
    }

    /**
     * 获取数组当前元素个数
     * @return
     */
    public int getSize(){
        return this.size;
    }

    /**
     * 数组是否为空
     * @return
     */
    public boolean isEmpty(){
        return this.size == 0;
    }

    /**
     * 插入元素，并返回位置
     * @param e
     * @return
     */
    public int insert(T e){
        if (size == data.length){
            throw new IllegalArgumentException("Array is full");
        }
        /**
         * 找到插入位置
         */
        int index = 0;
        for (; index < size; index ++){
            if (data[index] == null) {
                break;
            }
            if (orderBy == ASC && ((T)data[index]).compareTo(e) >= 0){
                break;
            }
            if (orderBy == DESC && ((T)data[index]).compareTo(e) <= 0){
                break;
            }
        }

        /**
         * 挪动原有元素
         */
        for (int i = size - 1; i >= index; i--){
            data[i + 1] = data[i];
        }

        data[index] = e;
        size++;

        return index;
    }

    @Override
    public String toString(){
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(String.format("Array capacity=%d, size=%d\n", data.length, size));
        stringBuilder.append("[");
        for (int i = 0; i < size; i++){
            stringBuilder.append(data[i]);
            if (i != size -1){
                stringBuilder.append(",");
            }
        }
        stringBuilder.append("]");

        return stringBuilder.toString();
    }
}
