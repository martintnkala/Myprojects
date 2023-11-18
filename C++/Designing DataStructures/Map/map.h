/***********************************************************************
 * Header:
 *    map
 * Summary:
 *    Our custom implementation of a std::map
 *      __       ____       ____         __
 *     /  |    .'    '.   .'    '.   _  / /
 *     `| |   |  .--.  | |  .--.  | (_)/ /
 *      | |   | |    | | | |    | |   / / _
 *     _| |_  |  `--'  | |  `--'  |  / / (_)
 *    |_____|  '.____.'   '.____.'  /_/
 *
 *    This will contain the class definition of:
 *        map                 : A class that represents a map
 *        map::iterator       : An iterator through a map
 * Author
 *    <your names here>
 ************************************************************************/

#pragma once

#include "pair.h"     // for pair
#include "bst.h"      // no nested class necessary for this assignment

#ifndef debug
#ifdef DEBUG
#define debug(x) x
#else
#define debug(x)
#endif // DEBUG
#endif // !debug

class TestMap; // forward declaration for unit tests

namespace custom
{

/*****************************************************************
 * MAP
 * Create a Map, similar to a Binary Search Tree
 *****************************************************************/
template <class K, class V>
class map
{
   friend ::TestMap; // give unit tests access to the privates
   template <class KK, class VV>
   friend void swap(map<KK, VV>& lhs, map<KK, VV>& rhs);
public:
   using Pairs = custom::pair<K, V>;

   //
   // Construct
   //
   map() : bst()
   {
   }
   map(const map &  rhs) : bst(rhs.bst)
   {
   }
   map(map && rhs) : bst(std::move(rhs.bst))
   {
   }
   template <class Iterator>
   map(Iterator first, Iterator last)
   {
      while (first != last)
      {
         bst.insert(*first, true);
         ++first;
      }
   }
   map(const std::initializer_list <Pairs>& il)  : bst(il)
   {
   }
  ~map()
   {
      clear();
   }

   //
   // Assign
   //
   map & operator = (const map & rhs)
   {
      clear();
      bst = rhs.bst;
      return *this;
   }
   map & operator = (map && rhs)
   {
      clear();
      bst.swap(rhs.bst);
      return *this;
   }
   map & operator = (const std::initializer_list <Pairs> & il)
   {
      bst = il;
      return *this;
   }

   //
   // Iterator
   //
   class iterator;
   iterator begin()
   {
      return bst.begin();
   }
   iterator end()
   {
      return bst.end();;
   }

   //
   // Access
   //
   const V & operator [] (const K & k) const;
         V & operator [] (const K & k);
   const V & at (const K& k) const;
         V & at (const K& k);
   iterator    find(const K & k)
   {
      return bst.find(k);
   }

   //
   // Insert
   //
   custom::pair<typename map::iterator, bool> insert(Pairs && rhs)
   {
      auto returnPair = bst.insert(rhs, true);
      auto itBST = returnPair.first;
      return make_pair(iterator(itBST), returnPair.second);
   }
   custom::pair<typename map::iterator, bool> insert(const Pairs & rhs)
   {
      auto returnPair = bst.insert(rhs, true);
      auto itBST = returnPair.first;
      return make_pair(iterator(itBST), returnPair.second);
   }

   template <class Iterator>
   void insert(Iterator first, Iterator last)
   {
      while (first != last)
      {
         bst.insert(*first, true);
         ++first;
      }
   }
   void insert(const std::initializer_list <Pairs>& il)
   {
      bst.insert(il);
   }

   //
   // Remove
   //
   void clear() noexcept
   {
      bst.clear();
   }
   size_t erase(const K& k);
   iterator erase(iterator it);
   iterator erase(iterator first, iterator last);

   //
   // Status
   //
   bool empty() const noexcept { return bst.empty(); }
   size_t size() const noexcept { return bst.size(); }


private:

   // the students DO NOT need to use a nested class
   BST < pair <K, V >> bst;
};


/**********************************************************
 * MAP ITERATOR
 * Forward and reverse iterator through a Map, just call
 * through to BSTIterator
 *********************************************************/
template <typename K, typename V>
class map <K, V> ::iterator
{
    friend class ::TestMap; // give unit tests access to the privates
    template <class KK, class VV>
    friend class custom::map;
public:
    //
    // Construct
    //
    iterator() : it(nullptr) {}
    iterator(const typename BST < pair <K, V> > ::iterator& rhs) : it(rhs) {}
    iterator(const iterator& rhs) { *this = rhs; }

    //
    // Assign
    //
    iterator& operator = (const iterator& rhs)
    {
       it = rhs.it;
       return *this;
    }

    //
    // Compare
    //
    bool operator == (const iterator& rhs) const { return it == rhs.it; }
    bool operator != (const iterator& rhs) const { return it != rhs.it; }

    //
    // Access
    //
    const pair <K, V>& operator * () const
    {
       return *it;
    }

    //
    // Increment
    //
    iterator& operator ++ ()
    {
       ++it;
       return *this;
    }
    iterator operator ++ (int postfix)
    {
       iterator tmp(*this);
       ++(*this);
       return tmp;
    }
    iterator& operator -- ()
    {
       --(*this);
       return *this;
    }
    iterator  operator -- (int postfix)
    {
       iterator tmp(*this);
       --it;
       return tmp;
    }

private:

    // Member variable
    typename BST < pair <K, V >>  ::iterator it;
};


   /*****************************************************
    * MAP :: SUBSCRIPT
    * Retrieve an element from the map
    ****************************************************/
   template <typename K, typename V>
   V& map <K, V> :: operator [] (const K& key)
   {
      // create a pair with the key and a default value
      custom::pair<K, V>pair(key, V());
      auto returnPair = bst.find(pair);
      // if the key is found, return the value
      if (returnPair != bst.end())
         return returnPair.pNode->data.second;
      // if the key is not found, insert the pair and return the value
      else
      {
         bst.insert(pair, true);
         return bst.find(pair).pNode->data.second;
      }
   }

/*****************************************************
 * MAP :: SUBSCRIPT
 * Retrieve an element from the map
 ****************************************************/
template <typename K, typename V>
const V& map <K, V> :: operator [] (const K& key) const
{
   custom::pair<K, V> pair(key, V());
   auto itBST = bst.find(pair);
   if (itBST != bst.end())
      return itBST.pNode->data.second;
   else
      return *(new V);
}

/*****************************************************
 * MAP :: AT
 * Retrieve an element from the map
 ****************************************************/
template <typename K, typename V>
V& map <K, V> ::at(const K& key)
{

   custom::pair<K, V> pair(key, V());
   auto itBST = bst.find(pair);
   if (itBST != bst.end())
      return itBST.pNode->data.second;
   else
      throw std::out_of_range("invalid map<K, T> key");
}

/*****************************************************
 * MAP :: AT
 * Retrieve an element from the map
 ****************************************************/
template <typename K, typename V>
const V& map <K, V> ::at(const K& key) const
{
   custom::pair<K, V> pair(key, V());
   auto itBST = bst.find(pair);
   if (itBST != bst.end())
      return itBST.pNode->data.second;
   else
      throw std::out_of_range("invalid map<K, T> key");
}

/*****************************************************
 * SWAP
 * Swap two maps
 ****************************************************/
template <typename K, typename V>
void swap(map <K, V>& lhs, map <K, V>& rhs)
{
   std::swap(lhs.bst, rhs.bst);
}

/*****************************************************
 * ERASE
 * Erase one element
 ****************************************************/
template <typename K, typename V>
size_t map<K, V>::erase(const K& k)
{
   custom::pair<K, V> pair(k, V());
   auto itBST = bst.find(pair);
   if (itBST != bst.end())
   {
      bst.erase(itBST);
      return 1;
   }
   else
      return 0;
}

/*****************************************************
 * ERASE
 * Erase several elements
 ****************************************************/
template <typename K, typename V>
typename map<K, V>::iterator map<K, V>::erase(map<K, V>::iterator first, map<K, V>::iterator last)
{
   while (first != last)
      first = erase(first);
   
   return last;
}

/*****************************************************
 * ERASE
 * Erase one element
 ****************************************************/
template <typename K, typename V>
typename map<K, V>::iterator map<K, V>::erase(map<K, V>::iterator it)
{
   return iterator(bst.erase(it.it));
}

}; //  namespace custom

