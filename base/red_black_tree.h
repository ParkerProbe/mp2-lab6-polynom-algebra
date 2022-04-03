#ifndef _RED_BLACK_TREE_H_
#define _RED_BLACK_TREE_H_


#include "table.h"
#include <iterator>
#include <ostream>
#include "stack.h"
#include "table_string.h"

         


class RedBlackTree : public Table
{
private:
    enum RBTColor { Black, Red };

    struct  RBTNode
    {
      TableString* data;
      RBTColor color;
      RBTNode * left;
      RBTNode* right;
      RBTNode * parent;
      RBTNode(TableString* data_, RBTColor c, RBTNode* p, RBTNode*l, RBTNode*r) :
        data(data_), color(c), parent(p), left(l), right(r) { };
    };
   
    void leftRotate(RBTNode* &root, RBTNode* x);
    void rightRotate(RBTNode* &root, RBTNode* y);

    void insert(RBTNode* &root, RBTNode* node);
    void insert_fix_up(RBTNode* &root, RBTNode* node);
    void destory(RBTNode* &node);

    void remove(RBTNode*& root, RBTNode*node);
    void remove_fix_up(RBTNode* &root, RBTNode* node, RBTNode*parent);

    RBTNode* search(RBTNode*node, TableString* data_) const;
    void print(RBTNode* node)const;
    void preOrder(RBTNode* tree)const;
    void inOrder(RBTNode* tree)const;
    void postOrder(RBTNode* tree)const;




    int curr_pos;

    	RBTNode *root;

public:
    
    RedBlackTree(): curr_pos(0)
      {}

	  ~RedBlackTree();


    TableString* find_str(const std::string& key);
    void insert(const TableString& data);
    void erase(const std::string& key);
    bool is_full() const;
    bool reset();
    bool is_tab_ended() const;
    bool go_next();
    bool set_current_pos(int pos);
    int get_current_pos() const;
    TableString* get_value();

};

#endif // _RED_BLACK_TREE_H_