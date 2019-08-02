#ifndef CPP_SKIPLIST_H
#define CPP_SKIPLIST_H

#include <string>

using namespace std;
/**
 * 跳表的一种实现方法。
 * 跳表中存储的是正整数，并且存储的是不重复的。
 *
 *  跳表结构:
 *
 *  第K级           1           9
 *  第K-1级         1     5     9
 *  第K-2级         1  3  5  7  9
 *  ...             ....
 *  第0级(原始链表)  1  2  3  4  5  6  7  8  9
 */

const unsigned int MAX_LEVEL = 16;
/**
 * 节点
 */
class SkipListNode{
public:
    SkipListNode();
    ~SkipListNode();
    string toString();
    /**
     * 获取索引链表
     * @return
     */
    SkipListNode** getIdxList();
    /**
     * 设置数据
     */
    void setData(int v);
    /**
     * 获取数据
     * @return
     */
    int getData();
    /**
     * 设置最大索引级别
     * @param l
     */
    void setLevel(int l);

private:
    /**
     * 当前节点的值
     */
     int m_data;
    /**
     * 当前节点的每个等级的下一个节点.
     * 第2级 N1 N2
     * 第1级 N1 N2
     * 如果N1是本节点,则 m_lpForwards[x] 保存的是N2
     *
     * [0] 就是原始链表.
     */
    SkipListNode* m_lpForwards[MAX_LEVEL];
    /**
     * 当前节点的所在的最大索引级别
     */
    int m_iMaxLevel;
};
/**
 * 跳表
 */
class SkipList{
public:
    SkipList();
    ~SkipList();

    /**
     * 查找指定的值的节点
     */
     SkipListNode* find(int v);
     /**
      * 插入指定的值
      */
      void insert(int v);
      /**
       * 删除指定的值的节点
       */
       int deleteNode(int v);
       void printAll();
       void printAll(int l);
       /**
        * 插入节点时，得到插入k级的随机函数
        */
        int randomLevel();

private:
    int levelCount;
    /**
     * 链表
     */
     SkipListNode* m_lpHead;
};

void testSkipList();

#endif //CPP_SKIPLIST_H






























