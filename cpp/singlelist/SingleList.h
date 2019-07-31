#ifndef SINGLELIST_SINGLELIST_H
#define SINGLELIST_SINGLELIST_H

/**
 * 链表结点
 */
class Node{
public:
    Node* next;
    int value;
    explicit Node(int v);
};
/**
 * 单链表
 */
class SingleList{
public:
    SingleList();
    SingleList(const SingleList &source);
    ~SingleList();
    Node* insert(Node* node);
    Node* insert(Node* node, unsigned int targetIndex);
    SingleList& operator= (const SingleList& source);
    void reverse();
    void display();
    void destroy();

private:
    Node* head;
};

/**
 * 单链表测试
 */
void testSingleList();

#endif //SINGLELIST_SINGLELIST_H
