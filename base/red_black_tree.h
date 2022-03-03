#ifndef _RED_BLACK_TREE_H_
#define _RED_BLACK_TREE_H_


#include "table.h"


struct NodeTree
{
    TableString data;
    NodeTree* pRight;
    NodeTree* pLeft;
    NodeTree* pParent;
};

template <class T>
class RedBlackTree : public Table
{
private:
    void rotate_left(NodeTree* t);
    void rotate_right(NodeTree* t);
    void rotatei_bigLeft(NodeTree* t);
    void rotate_big_right(NodeTree* t);
    void change_balance(NodeTree* t);
    void Balance();
    NodeTree* pFirst_;
public:
    RedBlackTree() : Table()
    {}
    void insert(const TableString& d);
    TableString* Find(const string& key);
    void Delete(const string& key);
    void Print();
    
    ~RedBlackTree();


};

#endif // _RED_BLACK_TREE_H_