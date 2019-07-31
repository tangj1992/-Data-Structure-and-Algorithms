#include <iostream>
#include "SingleList.h"

using namespace std;
/**
 * 链表实现
 */

SingleList::SingleList() {
    head = nullptr;
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
        this->head = nullptr;
        while (p != nullptr){
            this->insert(new Node(p->value));
            p = p->next;
        }
    }

}
/**
 * 销毁链表
 */
SingleList::~SingleList() {
    this->destroy();
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
        this->head = nullptr;
        while (p != nullptr){
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
    if (head == nullptr){
        head = node;
    }else{
        Node* p = head;
        while(p->next != nullptr) {
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
    if (head == nullptr){
        head = node;
        return head;
    }
    unsigned int index = 0;
    Node* p = head;
    Node* prev = nullptr;
    while ( (p != nullptr) && (index != targetIndex) ){
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
    Node* prev = nullptr;
    Node* p = head;

    while (p != nullptr){
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
    if (head == nullptr){
        cout << "list is empty" << endl;
        return;
    }
    Node* p = head;
    cout << "list:[" ;
    do{
        cout << p->value;
        p = p->next;
        if (p != nullptr){
            cout << ", ";
        }
    }while (p != nullptr);

    cout << "]" << endl;
}
/**
 * 销毁链表
 */
void SingleList::destroy() {
    Node* p = nullptr;
    while (nullptr != head){
        p = head->next;
        delete head;
        head = p;
    }
}

Node::Node(int v) {
    value = v;
    next = nullptr;
}

/**
 * 复制构造函数测试
 * @param list
 */
void a(SingleList list){
    list.display();
}
/**
 * 单链表测试
 */
void testSingleList(){
    SingleList list;
    for (int i = 0; i < 30; ++i) {
        Node* node = new Node(i);
        list.insert(node);
    }
    list.display();

//    list.destroy();
//    list.display();

    SingleList list2;
    list2 = list;

    a(list2);

    list2.display();

}