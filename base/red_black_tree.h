#ifndef _RED_BLACK_TREE_H_
#define _RED_BLACK_TREE_H_


#include "table.h"
#include <iterator>
#include <ostream>
#include "stack.h"
#include "table_string.h"

struct NodeTree
{
    TableString data;
    NodeTree* pRight;
    NodeTree* pLeft;
};

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




    TableString* find_str(const std::string& key);
    TableBody* find(const std::string& key);
    void insert(const TableString& data);
    void erase(const std::string& key);
    void print();
    bool is_full() const;
    bool reset();
    bool is_tab_ended() const;
    bool go_next();
    bool set_current_pos(int pos);
    int get_current_pos() const;
    TableString* get_value();

};

#endif // _RED_BLACK_TREE_H_