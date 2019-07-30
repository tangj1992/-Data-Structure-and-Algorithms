package linkedlist;

/**
 * 单向节点
 *
 * @author tangjun
 * @date 2019/6/24 14:45
 */
public class SinglyNode<T>{

    private T data;
    public SinglyNode next;

    public SinglyNode(T data, SinglyNode next){
        this.data = data;
        this.next = next;
    }
    public SinglyNode(T data){
        this(data, null);
    }

    public T getData() {
        return data;
    }
}
