#include "SkipList.h"
#include <iostream>
#include <random>
#include <ctime>

using  namespace std;

/**
 * SkipListNode实现
 */
SkipListNode::SkipListNode() {
    m_data = -1;
    m_iMaxLevel = 0;

    for (int i = 0; i < MAX_LEVEL; ++i) {
        m_lpForwards[i] = nullptr;
    }
}
SkipListNode::~SkipListNode() {

}
SkipListNode** SkipListNode::getIdxList() {
    return m_lpForwards;
}
void SkipListNode::setData(int v) {
    m_data = v;
}
int SkipListNode::getData() {
    return m_data;
}
void SkipListNode::setLevel(int l) {
    m_iMaxLevel = l;
}
string SkipListNode::toString() {
    char tmp[32];
    std::string ret;

    ret.append("{ data: ");
    sprintf(tmp, "%d", m_data);
    ret.append(tmp);
    ret.append("; level: ");
    sprintf(tmp, "%d", m_iMaxLevel);
    ret.append(tmp);
    ret.append(" }");
    return ret;
}
/**
* SkipList实现
*/
SkipList::SkipList() {
    levelCount = 1;
    m_lpHead = new SkipListNode();
}
SkipList::~SkipList() {

}
SkipListNode* SkipList::find(int v) {
    SkipListNode* lpNode = m_lpHead;
    /**
     * 从最大级索引链表开始查找
     * k -> k-1 -> k-2 -> ... ->0
     */
    for (int i = levelCount - 1; i > 0 ; --i) {
        /**
         * 查找小于v的节点
         */
         while (nullptr != lpNode->getIdxList()[i] && (lpNode->getIdxList()[i]->getData() < v)){
            lpNode = lpNode->getIdxList()[i];
         }
    }
    /**
     * lpNode 是小于v的节点，lpNode的下一个节点就是大于等于v的节点
     */
    if (nullptr != lpNode->getIdxList()[0] && (lpNode->getIdxList()[0]->getData() == v)){
        return lpNode->getIdxList()[0];
    }

    return nullptr;
}
void SkipList::insert(int v){
    //新节点
    SkipListNode* lpNewNode = new SkipListNode();

    /**
     * 新节点最大分布在的索引链表上限
     * 如果返回3，则新节点会在索引1、2、3上的链表都存在
     */
     int level = randomLevel();
     lpNewNode->setData(v);
     lpNewNode->setLevel(level);
     /**
      * 临时索引链表
      * 主要是得到新的节点在每个索引链表上的位置
      */
    SkipListNode *lpUpdateNode[level];
    for (int i = 0; i < level; ++i) {
        //每个索引链表的头节点
        lpUpdateNode[i] = m_lpHead;
    }
    SkipListNode* lpFind = m_lpHead;
    for (int j = level - 1; j >= 0; --j) {
        /**
         * 查找位置
         * eg. 第1级 1  7  10
         * 如果插入的是6
         * lpFind->getIdxList()[j]->getData():表示节点lpFind在第1级索引的下一个节点的数据
         * 当“lpFind->getIdxList()[j]->getData() < v”不成立的时候
         * 新节点就要插入到lpFind节点的后面，lpFind->getIdxList()[i]节点的前面
         * 即在这里lpFind就是1 lpFindGetIdxList()[i]就是7
         */
         while (nullptr != lpFind->getIdxList()[j] && (lpFind->getIdxList()[j]->getData() < v)){
             lpFind = lpFind->getIdxList()[j];
         }
         //lpFind是新节点在第j级索引链表的前一个节点
        lpUpdateNode[j] = lpFind;
    }
    for (int k = 0; k < level; ++k) {
        /**
         * 重新设置链表指针的位置
         * eg 第1级索引 1  7  10
         * 插入6
         * lpUpdateNode[k]节点是1，lpUpdateNode[k]->getIdxList()[k]节点是7
         *
         * 这两句代码就是把6放在1和7之间
         */
         lpNewNode->getIdxList()[k] = lpUpdateNode[k]->getIdxList()[k];
         lpUpdateNode[k]->getIdxList()[k] = lpNewNode;
    }
    if (levelCount < level){
        levelCount = level;
    }
}
int SkipList::deleteNode(int v){
    int ret = -1;
    SkipListNode *lpUpdateNode[levelCount];
    SkipListNode *lpFind = m_lpHead;
    for (int i = levelCount - 1; i >= 0 ; --i) {
        /**
         * 查找小于v的节点(lpFind)
         */
        while ((nullptr != lpFind->getIdxList()[i]) && (lpFind->getIdxList()[i]->getData() < v)){
            lpFind = lpFind->getIdxList()[i];
        }
        lpUpdateNode[i] = lpFind;
    }
    /**
     * lpFind是小于v的节点，lpFind的下一个节点就是大于等于v的节点
     */
     if ((nullptr != lpFind->getIdxList()[0]) && (lpFind->getIdxList()[0]->getData() == v)){
         for (int i = levelCount - 1; i >= 0; --i){
             if ((nullptr != lpUpdateNode[i]->getIdxList()[i]) && (v == lpUpdateNode[i]->getIdxList()[i]->getData())){
                 lpUpdateNode[i]->getIdxList()[i] = lpUpdateNode[i]->getIdxList()[i]->getIdxList()[i];
                 ret = 0;
             }
         }
     }
    return ret;

}
void SkipList::printAll(){
    SkipListNode* lpNode = m_lpHead;
    while(NULL != lpNode->getIdxList()[0]){
        cout<< lpNode->getIdxList()[0]->toString().data() <<endl;
        lpNode = lpNode->getIdxList()[0];
    }
}
void SkipList::printAll(int l){
    for(int i=MAX_LEVEL-1; i>=0;--i){
        SkipListNode* lpNode = m_lpHead;
        cout<<"level:"<<i<<endl;
        if((l < 0) || ((l >= 0) && (l == i))){
            while(nullptr != lpNode->getIdxList()[i]){
                cout<<lpNode->getIdxList()[i]->getData()<<" ";
                lpNode = lpNode->getIdxList()[i];
            }
            cout<<endl;
            if(l >= 0){
                break;
            }
        }
    }
}
int getRandom(){
    static int _count = 1;
    default_random_engine generator(time(0) + _count);
    uniform_int_distribution<int> distribution(1,99999);
    int dice_roll = distribution(generator);

    _count += 100;

    return dice_roll;
}
int SkipList::randomLevel(){
    int level = 1;
    for (int i = 1; i < MAX_LEVEL; ++i) {
        if (1 == (getRandom() % 3)){
            ++level;
        }
    }

    return level;
}

/**
* testSkipList实现
*/
void testSkipList(){
    SkipList skipList;
    int size = 50;
    /// 插入原始值
    for(int i=1; i< size; i++){
        if((i%3) == 0){
            skipList.insert(i);
        }
    }
    for(int i=1; i< size; i++){
        if((i%3) == 1){
            skipList.insert(i);
        }
    }
    skipList.printAll();
    cout<<endl;

    /// 打印所有等级结构
    skipList.printAll(-1);

    /// 查找
    cout<<endl;
    SkipListNode* lpNode = skipList.find(27);
    if(NULL != lpNode){
        cout<<"data 27 found, node value:"<<lpNode->getData()<<endl;
    }else{
        cout<<"data 27 not found"<<endl;
    }

    /// 删除
    std::cout<<std::endl;
    int ret = skipList.deleteNode(46);
    if(0 == ret){
        std::cout<<"data 46 found, delete success"<<std::endl;
    }else{
        std::cout<<"delete fail"<<std::endl;
    }
    cout<<endl;
    //打印所有等级结构
    skipList.printAll(-1);


}