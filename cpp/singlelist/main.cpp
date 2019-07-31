#include "singlelist.h"
#include <iostream>
void a(SingleList list){
    list.display();
}
int main() {

    SingleList list;
    for (int i = 0; i < 30; ++i) {
        Node* node = new Node(i);
        list.insert(node);
    }


    list.display();
    list.destroy();
    list.display();
//    SingleList list2;
//    list2 = list;
//
//    a(list2);
//
//    list2.display();

    return 0;
}