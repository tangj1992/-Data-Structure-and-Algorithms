package linkedlist;

/**
 * @author tangjun
 * @date 2019/6/24 14:48
 */
public class Main {
    public static void main(String[] args){
        SinglyLinkedList<Integer> linkedList = new SinglyLinkedList<>();
        int[] data = new int[]{1,2,3,4,5,6,7};
        for (int i : data){
//            linkedList.insertHead(i);
            linkedList.insertTail(i);
        }
        System.out.println("原始数据:");
        linkedList.printAll();


        linkedList.deleteByValue(1);
        System.out.println("删除数据后:");
        linkedList.printAll();

        SinglyNode<Integer> node = new SinglyNode<>(1);
        linkedList.insertTail(node);
        System.out.println("添加节点后:");
        linkedList.printAll();

        linkedList.deleteByNode(node);
        System.out.println("删节点后:");
        linkedList.printAll();

        System.out.println("链表翻转后:");
        linkedList.inverseLinkedList().printAll();

        System.out.println("通过值查找节点:");
        System.out.println(linkedList.findByValue(10));

        System.out.println("通过索引查找节点:");
        System.out.println(linkedList.findByIndex(1).getData());

        System.out.println("查找中间节点:");
        System.out.println(linkedList.findMiddleNode().getData());
    }
}
