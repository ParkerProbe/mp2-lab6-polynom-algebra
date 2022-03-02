#ifndef LIST_H_
#define LIST_H_


#include <vector>

#include "eq_exception.h"


template <class T>
struct NodeList
{
    T key = T();
    NodeList* pNext = nullptr;
};

template <class T>
class List;

template <class T>
class ListIterator;

template <class T>
class ListIterator
{
private:
    friend class List<T>;
    NodeList<T>* pptr_;
    NodeList<T>* ptr_;

    ListIterator(NodeList<T>* ptr) : ptr_(ptr), pptr_(ptr_)
    {}
public:
    ListIterator(const ListIterator& it) : ptr_(it.ptr_), pptr_(it.pptr_)
    {}

    bool operator==(const ListIterator& it) const
    {
        return (ptr_ == it.ptr_);
    }

    bool operator!=(const ListIterator& it) const
    {
        return (ptr_ != it.ptr_);
    }

    T& operator*() const
    {
        return ptr_->key;
    }

    ListIterator& operator++()
    {
        pptr_ = ptr_;
        if (ptr_ == nullptr)
            return *this;
        ptr_ = ptr_->pNext;
        return *this;
    }
};

template <class T> 
class List
{
private:
    int size_;
    NodeList<T> *pFirst_;
    NodeList<T> *pLast_;

public:
    List() : size_(0), pFirst_(nullptr), pLast_(nullptr) {}

    using iterator = ListIterator<T>;
    iterator begin() const
    {
        return iterator{pFirst_};
    }

    iterator end() const
    {
        return iterator{nullptr};
    }

    ListIterator<T> Insert(iterator iter, const T& val)
      {
        if(iter.ptr_ == pFirst_) {
            AddNodeList(val);
            return iterator{nullptr};
        }

        NodeList<T>* tmp = new NodeList<T>();
        tmp->key = val;
        tmp->pNext = iter.ptr_;
        iter.pptr_->pNext = tmp;
        iter.ptr_ = tmp;
        return iter;
    }

    void Erase(iterator iter)
    {
        NodeList<T>* tmp = pFirst_;
        NodeList<T>* prev;
        int pos = 0;
        while (tmp != iter.ptr_) {
            prev = tmp;
            tmp = tmp -> pNext;
            pos++;
        }
        if (pos == 0) {
            pFirst_ = pFirst_->pNext;
            delete tmp;
            size_--;
        }
        else {
            prev->pNext = tmp->pNext;
            delete tmp;
            size_--;
        }
    }

    List(T* arr) : size_(0), pFirst_(nullptr), pLast_(nullptr)
    {
        if(arr == nullptr)
            throw(EqException(EqException::TEST,"Wrong length of mass"));
        for(int i = 0; i < sizeoff(arr) / sizeoff(arr[0]); i++) {
            AddNodeList(arr[i]);
        }
    }

    List(std::vector<T>& v) : size_(0), pFirst_(nullptr), pLast_(nullptr)
    {
        if(v.size_() == 0)
            throw(EqException(EqException::TEST,"Wrong length of vector"));
        for(T tmp: v) {
            AddNodeList(tmp);
        }
    }

    T& operator[](int index)
    {
        if ((index > size_ - 1) || (index < 0)) {
            throw(EqException(EqException::TEST, "Incorrect index"));
        }
        int n = 0;

        NodeList<T>* pCurrent = pFirst_;
        while(pCurrent != nullptr) {
            if (index == n) {
              return pCurrent->key;
            }
            pCurrent = pCurrent->pNext;
            n++;
        }
        throw(EqException(EqException::TEST, "Incorrect index"));
    }

    inline bool operator==(const List& other)
    {
        if(size_ != other.size_) {
            return false;
        }

        if(this == &other) {
            return true;
        }

        iterator it1 = this->begin();
        iterator it2 = other.begin();

        for(;it1 != this->end(); ++it1, ++it2) {
            if(it1.ptr_->key != it2.ptr_->key) {
              return false;
            }
        }
        return true;
    }

    inline bool operator!=(const List& other)
    {
        return !(*this == other);
    }

    List(List && list) noexcept
    {
        size_ = list.size_;
        pFirst_ = list.pFirst_;
        pLast_ = list.pLast_;

        list.pFirst_ = nullptr;
        list.pLast_ = nullptr;
        list.size_ = 0;
    }

    List& operator=(List && list) noexcept
    {
        if (this != &list) {
            while (pFirst_ != nullptr) {
                NodeList<T>* tmp = pFirst_;
                pFirst_ = pFirst_->pNext;
                delete tmp;
            }

            size_ = list.size_;
            pFirst_ = list.pFirst_;
            pLast_ = list.pLast_;

            list.size_ = 0;
            list.pFirst_ = nullptr;
            list.pLast_ = nullptr;

            //std::swap(pFirst_, list.pFirst_)
            //std::swap(pLast, list.pLast)
            //std::swap(size_, list.size_)
        }
        return *this;
    }
    
    List(const List& other)
    {
        pFirst_ = nullptr;
        pLast_ = nullptr;
        size_ = 0;

        if(other.pFirst_ == nullptr) {
          return;
        }

        pFirst_ = new NodeList<T>();
        pFirst_->key = other.pFirst_->key;
        NodeList<T>* pCurrent = pFirst_;
        size_ = 1;

        for(NodeList<T>* pTmp = other.pFirst_->pNext;
              pTmp != nullptr; pTmp = pTmp->pNext) {
            pCurrent->pNext = new NodeList<T>();
            pCurrent = pCurrent->pNext;
            pCurrent->key = pTmp->key;
            size_++;
        }
        pCurrent->pNext = nullptr;
        pLast_ = pCurrent;
    }

    void EraseList()
    {
      NodeList<T>* pCurrent = pFirst_;
      while(pCurrent != nullptr) {
          pCurrent = pCurrent->pNext;
          delete  pFirst_;
          pFirst_ = pCurrent;
      }
      size_ = 0;
    }

    ~List()
    {
      EraseList();
    }

    List& operator=(const List& other)
    {
        if(this == &other) {
            return *this;
        }

        List tmp(other);
        std::swap(tmp, *this);
        return *this;
    }

    NodeList<T>* AddNodeList(T item)
    {
        if(pLast_ == nullptr) {
            NodeList<T>* tmp = new NodeList<T>();
            pLast_ = tmp;
            pLast_->key = item;
            pFirst_ = pLast_;
        }
        else{
            NodeList<T>* tmp = new NodeList<T>();
            pLast_->pNext = tmp;
            pLast_ = tmp;
            pLast_->key = item;
        }
        pLast_->pNext = nullptr;
        size_++;
        return pLast_;
    }
    
    NodeList<T>* GeNodeList(int index) const
    {
        if((index > size_ - 1) || (index < 0) )
            throw(EqException(EqException::TEST, "Index incorrect"));
        if(index == size_ - 1) {
            return pLast_;
        }
        else if(index == 0) {
            return pFirst_;
        }
        else {
            NodeList<T>* ptr_ = pFirst_;
            while(index) {
              ptr_ = ptr_->pNext;
              index--;
            }
            return ptr_;
        }
    }

    inline int Getsize_() const
    {
        return size_;
    }

    inline bool IsEmpty() const
    {
        return (size_ == 0);
    }
};

#endif
