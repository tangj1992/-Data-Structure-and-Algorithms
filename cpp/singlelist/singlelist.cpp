#include <iostream>
#include "singlelist.h"

using namespace std;
/**
 * 链表实现
 */

SingleList::SingleList() {
    head = NULL;
}
/**
 * 复制构造
 * @param source
 */
SingleList::SingleList(const SingleList& source){
    if(this != &source){
        Node* p = source.head;
        /**
         * 对象已经生成，所以需要清空
         */
        this->head = NULL;
        while (p != NULL){
            this->insert(new Node(p->value));
            p = p->next;
        }
    }

}
SingleList::~SingleList() {

    if (NULL != head){
        delete head;
        head = NULL;
    }
}
/**
 * 赋值运算，实现深拷贝
 * @param source
 * @return
 */
SingleList& SingleList::operator= (const SingleList& source){
    if(this != &source){
        Node* p = source.head;
        /**
         * 此步骤非必须，因为在这之前会首先执行对应构造函数
         */
        this->head = NULL;
        while (p != NULL){
            this->insert(new Node(p->value));
            p = p->next;
        }
    }
    return *this;
}
/**
 * 插入元素到末尾
 * @param node
 * @return
 */
Node* SingleList::insert(Node* node) {
    if (head == NULL){
        head = node;
    }else{
        Node* p = head;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = node;
    }

    return head;
}
/**
 * 插入元素到指定位置
 * 超出链表长度则插入到末尾
 * @param node
 * @return
 */
Node* SingleList::insert(Node* node, unsigned int targetIndex) {
    if (targetIndex == 0){
        node->next = head;
        head = node;
        return head;
    }
    if (head == NULL){
        head = node;
        return head;
    }
    unsigned int index = 0;
    Node* p = head;
    Node* prev = NULL;
    while ( (p != NULL) && (index != targetIndex) ){
        prev = p;
        p = p->next;
        ++index;
    }

    node->next = prev->next;
    prev->next = node;


    return head;
}
/**
 * 链表翻转
 */
void SingleList::reverse(){
    if (head == NULL){
        return;
    }
    Node* prev = NULL;
    Node* p = head;

    while (p != NULL){
        //先将当前元素的下一个元素保存下来
        Node* next = p->next;
        //将当前元素的下一个元素设为前一个元素
        p->next = prev;
        //将前一个元素设置未当前元素
        prev = p;
        //当前元素移动到下一个元素
        p = next;
    }

    head = prev;
}

void SingleList::display() {
    if (head == NULL){
        cout << "list is empty" << endl;
        return;
    }
    Node* p = head;
    cout << "list:[" ;
    do{
        cout << p->value;
        p = p->next;
        if (p != NULL){
            cout << ", ";
        }
    }while (p != NULL);

    cout << "]" << endl;
}


Node::Node(int v) {
    value = v;
    next = NULL;
}