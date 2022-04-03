#include "red_black_tree.h"
#include "eq_exception.h"
#include "table_string.h"
#include <new>


bool RedBlackTree::is_full() const
{
    try {
        TableString* pNode = new TableString();
    }
    catch(std::bad_alloc& e) {
        return 1;
    }
    
    return 0;
}


TableString* RedBlackTree::find_str(const std::string& key)
{
    NodeTree* pNode = pRoot;
    ppRef = &pRoot;
    while (pNode != nullptr) {
        if(pNode->data.key == key) {
            break;
        }
        if(pNode->data.key < key) {
            ppRef = &pNode->pRight;
        }
        else {
            ppRef = &pNode->pLeft;
        }
        pNode = *ppRef;
    }
    if(pNode == nullptr) {
        throw(EqException(error_code::k_NOT_FOUND));
    }
    return &pNode->data;
}


void RedBlackTree::insert(const TableString& data)
{
    if(is_full()) {
        throw (EqException(error_code::k_OUT_OF_MEMORY));
    }
    // Check
    else if (find_str(data.key) != nullptr) {
        
    }
    else {
        *ppRef = new NodeTree();
        data_cnt++;
    }

}

void RedBlackTree::erase(const std::string& key)
{
    if(find_str(key) == nullptr) {
        throw EqException(error_code::k_NOT_FOUND);
    }
    else {
        NodeTree* pNode = *ppRef;
        if (pNode->pRight == nullptr) {
            *ppRef = pNode->pLeft;
        }
        else if(pNode->pLeft == nullptr) {
            *ppRef = pNode->pRight;
        }
        else {
            NodeTree* tmp = pNode->pLeft;
            NodeTree** ppR = &pNode->pLeft;
            while(tmp->pRight != nullptr) {
                ppR = &tmp->pRight;
                tmp = *ppR;
            }
            pNode->data = tmp->data;
            pNode = tmp;
            *ppR = tmp->pLeft;
        }
        delete pNode;
    }
}

bool RedBlackTree::reset()
{
    NodeTree* pNode = pCurrent = pRoot;
    while (!st.is_empty()) {
        // Clear stack
        st.pop();
    }
    curr_pos = 0;
    while(pNode != nullptr) {
        st.add(pNode);
        pCurrent = pNode;
        pNode = pNode->pLeft;
    }
    return is_tab_ended();
}

bool RedBlackTree::go_next()
{
    if (!is_tab_ended() && (pCurrent != nullptr)) {
        NodeTree* pNode = pCurrent = pCurrent->pRight;
        st.pop();
        while(pNode != nullptr) {
            st.push(pNode);
            pCurrent = pNode;
            pNode = pNode->pLeft;
        }
        if ((pCurrent == nullptr) && !st.is_empty()) {
            pCurrent = st.get_top();
        }
        curr_pos++;
    } 
}

bool RedBlackTree::is_tab_ended() const
{
    return curr_pos >= data_cnt;
}

TableString* RedBlackTree::get_value()
{
    return &pCurrent->data;
}

int RedBlackTree::get_current_pos() const
{
    return curr_pos;
}

bool RedBlackTree::set_current_pos(int pos)
{
    curr_pos = ((pos > -1) && (pos < data_cnt)) ? pos : 0;
    return is_tab_ended();
}