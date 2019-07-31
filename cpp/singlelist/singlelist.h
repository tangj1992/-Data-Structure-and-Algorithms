#ifndef SINGLELIST_SINGLELIST_H
#define SINGLELIST_SINGLELIST_H

class Node;
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
 * 链表结点
 */
class Node{
public:
    Node* next;
    int value;
    Node(int v);
};

#endif //SINGLELIST_SINGLELIST_H
