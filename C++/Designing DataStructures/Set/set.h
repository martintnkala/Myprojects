/***********************************************************************
* Header:
*    Set
* Summary:
*      __       ____       ____         __
*     /  |    .'    '.   .'    '.   _  / /
*     `| |   |  .--.  | |  .--.  | (_)/ /
*      | |   | |    | | | |    | |   / / _
*     _| |_  |  `--'  | |  `--'  |  / / (_)
*    |_____|  '.____.'   '.____.'  /_/
*
*    This will contain the class definition of:
*        set                 : A class that represents a Set
*        set::iterator       : An iterator through Set
* Author
*    Martin Nkala and Amber Robbins
************************************************************************/

#pragma once

#include <cassert>
#include <iostream>
#include "bst.h"
#include <memory>     // for std::allocator
#include <functional> // for std::less

class TestSet;        // forward declaration for unit tests

namespace custom
{

/************************************************
 * SET
 * A class that represents a Set
 ***********************************************/
template <typename T>
class set
{
   friend class ::TestSet; // give unit tests access to the privates
public:
   
   //
   // CONSTRUCT
   //
   set(): bst() {}
   
   // copy
   set(const set &  rhs): bst(rhs.bst) {}
  
   // move
   set(set && rhs): bst(std::move(rhs.bst)) {}
   
   // init
   set(const std::initializer_list <T> & il): bst(il) {}
   
   template <class Iterator>
   set(Iterator first, Iterator last)
   {
      while (first != last)
      {
         bst.insert(*first, true);
         ++first;
      }
   
   }
   
  ~set() { }

   //
   // ASSIGN
   //

   // copy
   set & operator = (const set & rhs)
   {
      bst = rhs.bst;
      return *this;
   }
   
   // move
   set & operator = (set && rhs)
   {
      clear();
      bst.swap(rhs.bst);
      return *this;
   }
   
   // initializer
   set & operator = (const std::initializer_list <T> & il)
   {
      clear();
      for (const auto& element : il)
         bst.insert(element);
      return *this;
   }
   
   
   void swap(set& rhs) noexcept
   {
      bst.swap(rhs.bst);
   }

   //
   // ITERATOR
   //

   class iterator;
   
   iterator begin() const noexcept
   {
      return iterator(bst.begin());
   }
   iterator end() const noexcept
   {
      return iterator(bst.end());
   }

   //
   // ACCESS - O(log n)
   //
   iterator find(const T& t)
   {
      return iterator(bst.find(t));
   }

   //
   // STATUS
   //
   bool   empty() const noexcept { return bst.numElements == 0; }
   size_t size() const noexcept  { return bst.numElements;      }
 

   //
   // INSERT
   //
   
   // copy - O(log n)
   std::pair<iterator, bool> insert(const T& t)
   {
      // bst_pair.first contains iterator to the bst
      std::pair<iterator, bool> bst_pair = bst.insert(t, true);
      
      // set_pair.first contains iterator to the set
      std::pair<iterator, bool> set_pair(iterator(bst_pair.first), bst_pair.second);
      
      return set_pair;
   }
   
   // move - O(log n)
   std::pair<iterator, bool> insert(T&& t)
   {
      std::pair<iterator, bool> bst_pair = bst.insert(std::move(t), true);
      
      std::pair<iterator, bool> set_pair(iterator(bst_pair.first), bst_pair.second);
      
      return set_pair;
   }
   
   // initializer list - O(n log n)
   void insert(const std::initializer_list <T>& il)
   {
      // inserts every unique element into bst
      for (const auto& element : il)
         bst.insert(element, true);
   }



   //
   // REMOVE
   //
   
   // invdiviually destroys every element
   void clear() noexcept
   {
      bst.clear();
   }
   
   // erases single element
   iterator erase(iterator &it)
   {
      return iterator(bst.erase(it.it));
   }
   
   // erases first element found w/data matching t
   size_t erase(const T & t)
   {
      iterator it = find(t);
      
      if (it == end())
         return 0;
      
      erase(it);
      return 1;
   }
   
   // erases elements in a range. is O(log n) + O(m)
   // in regards to size of BST + number of elements to erase
   iterator erase(iterator &itBegin, iterator &itEnd)
   {
      while (itBegin != itEnd)
      {
         itBegin = erase(itBegin);
      
      }
   
      return iterator(itBegin);
   }

private:
   
   custom::BST <T> bst;
};


/**************************************************
 * SET ITERATOR
 * An iterator through Set
 *************************************************/
template <typename T>
class set <T> :: iterator
{
   friend class ::TestSet; // give unit tests access to the privates
   friend class custom::set<T>;

public:
   // constructors, destructors, and assignment operator
   iterator(): it(nullptr) {}
   iterator(const typename custom::BST<T>::iterator& itRHS): it(itRHS) {}
   iterator(const iterator & rhs) { *this = rhs; }
   
   iterator & operator = (const iterator & rhs)
   {
      it = rhs.it;
      return *this;
   }

   // equals, not equals operator
   bool operator != (const iterator & rhs) const { return it != rhs.it; }
   bool operator == (const iterator & rhs) const { return it == rhs.it; }
 
   // dereference operator: by-reference so we can modify the Set
   const T & operator * () const
   {
      return *it;
   }

   // prefix increment
   iterator & operator ++ ()
   {
      ++it;
      return *this;
   }

   // postfix increment
   iterator operator++ (int postfix)
   {
      iterator tmp(*this);
      ++it;
      return tmp;
   }
   
   // prefix decrement
   iterator & operator -- ()
   {
      --it;
      return *this;
   }
   
   // postfix decrement
   iterator operator-- (int postfix)
   {
      iterator tmp(*this);
      --it;
      return tmp;
   }
   
private:

   typename custom::BST<T>::iterator it;
};


}; // namespace custom



