package linkedlist;

/**
 * 单链表
 * 支持插入、删除、查找操作
 *
 * @author tangjun
 * @date 2019/6/24 14:37
 */
public class SinglyLinkedList<T> {
    private SinglyNode<T> head = null;

    /**
     * 头部插入
     * @param data
     */
    public void insertHead(T data){
        SinglyNode<T> node = new SinglyNode<>(data);
        insertHead(node);
    }
    /**
     * 头部插入
     * @param node
     */
    public void insertHead(SinglyNode<T> node){
        if (head == null){
            head = node;
        }else{
            node.next = head;
            head = node;
        }
    }

    /**
     * 尾部插入
     * @param data
     */
    public void insertTail(T data){
       SinglyNode<T> node = new SinglyNode<>(data);
       insertTail(node);
    }
    /**
     * 尾部插入
     * @param node
     */
    public void insertTail(SinglyNode<T> node){
        if (head == null){
            head = node;
        }else{
            SinglyNode<T> p = head;
            while (p.next != null){
                p = p.next;
            }
            p.next = node;
        }
    }

    /**
     * 删除指定值
     * @param value
     * @param all
     */
    public void deleteByValue(T value, boolean all){
        if (head == null){
            return;
        }

        if (head.getData() == value){
            head = head.next;
            if (!all){
                return;
            }
        }
        SinglyNode<T> p2 = head;

        while (p2 != null){
            if (p2.next != null && p2.next.getData() == value){
                p2.next = p2.next.next;
                if (all) {
                    continue;
                }else{
                    return;
                }
            }
            p2 = p2.next;
        }

        if (head != null && head.getData() == value) {
            head = head.next;
        }
    }

    /**
     * 删除指定值
     * @param data
     */
    public void deleteByValue(T data){
        this.deleteByValue(data, false);
    }

    /**
     * 删除指定节点
     * @param node
     */
    public void deleteByNode(SinglyNode<T> node){
        if (node == null || head == null){
            return;
        }
        if (node == head){
            head = head.next;
            return;
        }
        SinglyNode<T> p = head;
        while (p != null && p.next != node){
            p = p.next;
        }
        if (p == null){
            return;
        }
        p.next = p.next.next;
    }

    /**
     * 链表翻转
     * @return
     */
    public SinglyLinkedList<T> inverseLinkedList(){
        SinglyNode<T> pre = null;
        while (head != null){
            SinglyNode<T> next = head.next;
            head.next = pre;
            pre = head;
            head = next;
        }

        head = pre;

        return this;
    }

    /**
     * 通过值查找节点
     * @param value
     * @return
     */
    public SinglyNode<T> findByValue(T value){
        SinglyNode<T> p = head;
        while (p != null && p.getData() != value){
            p = p.next;
        }

        return p;
    }

    /**
     * 通过索引查找节点
     * @param index
     * @return
     */
    public SinglyNode<T> findByIndex(int index){
        SinglyNode<T> p = head;
        int i = 0;
        while (p != null && i < index){
            p = p.next;
            i++;
        }
        return p;
    }

    /**
     * 查找中间节点
     * @return
     */
    public SinglyNode<T> findMiddleNode(){
        if (head == null){
            return null;
        }
        SinglyNode<T> p = head, q = head;
        if (p.next == null){
            return p;
        }
        while (q.next != null && q.next.next != null){
            p = p.next;
            q = q.next.next;
        }

        return p;
    }
    /**
     * 打印数据
     */
    public void printAll(){
        SinglyNode<T> p = head;
        while (p != null){
            System.out.print(p.getData() + " ");
            p = p.next;
        }
        System.out.println();
    }

}
