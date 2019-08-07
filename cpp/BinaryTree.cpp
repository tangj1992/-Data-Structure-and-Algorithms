#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTreeNode::BinaryTreeNode(int v) {
    this->value = v;
    this->left  = nullptr;
    this->right = nullptr;
}

BinaryTree::BinaryTree() {
    this->root = nullptr;
}
BinaryTree::~BinaryTree() {
    destroy();
}
BinaryTreeNode* BinaryTree::insert(int v) {
    BinaryTreeNode* node = new BinaryTreeNode(v);
    if (this->root == nullptr){
        this->root = node;
        return this->root;
    }

    BinaryTreeNode* p = this->root;
    BinaryTreeNode* pre = nullptr;
    while (p != nullptr){
        pre = p;
        if (v > p->value){
            p = p->right;
        }else{
            p = p->left;
        }
    }
    if (v > pre->value){
        pre->right = node;
    } else{
        pre->left = node;
    }


    return this->root;
}
//前序遍历
void BinaryTree::preOrder() {
    this->preOrder(this->root);
    cout << endl;
}
void BinaryTree::preOrder(BinaryTreeNode* node) {
    if (node == nullptr){
        return;
    }
    cout << node->value << ",";
    preOrder(node->left);
    preOrder(node->right);
}

//中序遍历
void BinaryTree::inOrder() {
    this->inOrder(this->root);
    cout << endl;
}
void BinaryTree::inOrder(BinaryTreeNode* node) {
    if (node == nullptr){
        return;
    }
    preOrder(node->left);
    cout << node->value << ",";
    preOrder(node->right);
}
//后序遍历
void BinaryTree::postOrder() {
    this->postOrder(this->root);
    cout << endl;
}
void BinaryTree::postOrder(BinaryTreeNode* node) {
    if (node == nullptr){
        return;
    }
    preOrder(node->left);
    preOrder(node->right);
    cout << node->value << ",";
}
void BinaryTree::destroy() {
    this->destroy(this->root);
    this->root = nullptr;
}
void BinaryTree::destroy(BinaryTreeNode* &node) {
    if (node == nullptr){
        return;
    }
    destroy(node->left);
    destroy(node->right);
    delete node;
}
//测试
void testBinaryTree(){
    int arr[] = {6,7,8,9,10,1,2,3,4,5};
    BinaryTree binaryTree;
    for (int v : arr) {
        binaryTree.insert(v);
    }
    binaryTree.preOrder();
    binaryTree.inOrder();
    binaryTree.postOrder();
    binaryTree.destroy();
}

