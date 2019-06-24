package array;

/**
 * 支持动态扩容的数组
 * @author tangjun
 * @date 2019/6/24 10:00
 */
public class GenericArray<T>{
    /**
     * 默认数据长度
     */
    private static final int DEFAULT_CAPACITY = 10;
    /**
     * 数据
     */
    private T[] data;
    /**
     * 当前数组元素个数
     */
    private int size;

    /**
     * 根据容量构造数组
     * @param capacity
     */
    public GenericArray(int capacity){
        this.data = (T[])new Object[capacity];
        this.size = 0;
    }

    /**
     * 无参构造函数，使用默认容量构造数组
     */
    public GenericArray(){
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
     * 末尾添加元素
     * @param e
     */
    public void add(T e){
        /**
         * 数组已满，自动扩容
         */
        if (this.size == this.getCapacity()){
            resize(2 * this.getCapacity());
        }
        data[this.size] = e;
        this.size++;
    }

    /**
     * 指定位置添加元素
     * @param e
     */
    public void add(T e, int index){
        checkIndex(index);
        /**
         * 数组已满，自动扩容
         */
        if (this.size == this.getCapacity()){
            resize(2 * this.getCapacity());
        }
        for (int i = size - 1; i >= index; i--){
            data[i + 1] = data[i];
        }

        data[index] = e;
        this.size++;
    }

    /**
     * 删除指定位置的元素
     * @param index
     * @return
     */
    public T remove(int index){
        checkIndexForRemove(index);
        T res = data[index];
        for (int i = index; i < size; i++){
            data[i] = data[i+1];
        }
        size--;
        data[size] = null;
        /**
         * 缩容
         */
        if (size == data.length / 4 && data.length / 2 != 0){
            resize(data.length /2);
        }
        return res;
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

    /**
     * 修改数组长度
     * @param capacity
     */
    private void resize(int capacity){
        T[] newData = (T[])new Object[capacity];
        for (int i = 0; i < this.getSize(); i++){
            newData[i] = this.data[i];
        }
        data = newData;
    }

    /**
     * 检查索引
     * @param index
     */
    private void checkIndex(int index){
        if (index < 0 || index > this.size){
            throw new IllegalArgumentException("Add failed! Require index >=0 and index <= size.");
        }
    }

    /**
     * 检查索引
     * @param index
     */
    private void checkIndexForRemove(int index){
        if (index < 0 || index >= this.size){
            throw new IllegalArgumentException("Remove failed! Require index >=0 and index < size.");
        }
    }
}