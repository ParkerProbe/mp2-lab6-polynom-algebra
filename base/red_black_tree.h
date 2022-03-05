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
    void balance();

    NodeTree* pFirst;

    TableString* find_str(const string& key);
public:
    RedBlackTree() : Table()
    {}
    void insert(const TableString& d);
    TableBody* find(const std::string& key) = 0;
    void erase(const string& key);
    void print();
    bool empty();
    bool full();

    ~RedBlackTree();


};

#endif // _RED_BLACK_TREE_H_