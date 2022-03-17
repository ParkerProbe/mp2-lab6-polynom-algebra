#ifndef _RED_BLACK_TREE_H_
#define _RED_BLACK_TREE_H_


#include "table.h"
#include "stack.h"
#include <iterator>
#include <ostream>

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
    int curr_pos;
    NodeTree* pRoot;
    NodeTree* pCurrent;
    NodeTree** ppRef;
    Stack<NodeTree*> st;

    void print_tree_table(std::ostream &os, NodeTree* pNode);
    void draw_tree(NodeTree* pNode, int level);
    void delete_tree(NodeTree* pNode);

public:
    RedBlackTree()
        : Table() , curr_pos(0),  pRoot(nullptr),
         pCurrent(nullptr), ppRef(nullptr)
        {}
    void insert(const TableString& d);
    TableBody* find(const std::string& key) = 0;
    void erase(const string& key);
    void print();
    bool empty();
    bool is_full();

	bool reset();
	bool is_tab_ended() const;
    bool go_next();

    // Left -> Right
    void Draw();

    //Up -> Down
    void Show();

    TableString* get_value();

	TableIterator begin() const;
	TableIterator end() const;

    ~RedBlackTree();


};

#endif // _RED_BLACK_TREE_H_