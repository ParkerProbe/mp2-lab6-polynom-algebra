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
	  void RotateLeft(NodeTree* t);
	  void RotateRight(NodeTree* t);
	  void RotateBigLeft(NodeTree* t);
	  void RotateBigRight(NodeTree* t);
	  void ChangeBalance(NodeTree* t);
  	void Balance();
  NodeTree* pFirst;

public:
    RedBlackTree() : Table()
	  {}
	  void Insert(const TableString& d);
	  TableString* Find(const string& key);
	  void Delete(const string& key);
	  void Print();
	  
	  ~RedBlackTree();


};

#endif // _RED_BLACK_TREE_H_