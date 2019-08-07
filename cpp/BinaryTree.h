#ifndef CPP_BINARYTREE_H
#define CPP_BINARYTREE_H

#include <iostream>

using  namespace std;

/**
 * 二叉树链式实现
 */
class BinaryTreeNode{
public:
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    int value;
    explicit BinaryTreeNode(int v);
};

class BinaryTree{
public:
    BinaryTree();
    ~BinaryTree();
    BinaryTreeNode* root;
    BinaryTreeNode* insert(int v);
    void preOrder();
    void preOrder(BinaryTreeNode* node);
    void inOrder();
    void inOrder(BinaryTreeNode* node);
    void postOrder();
    void postOrder(BinaryTreeNode* node);
    void destroy();
    void destroy(BinaryTreeNode* &node);

};

void testBinaryTree();

#endif //CPP_BINARYTREE_H
