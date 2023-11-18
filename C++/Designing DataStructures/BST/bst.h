/***********************************************************************
 * Header:
 *    BST
 * Summary:
 *    Our custom implementation of a BST for set and for map
 *      __       ____       ____         __
 *     /  |    .'    '.   .'    '.   _  / /
 *     `| |   |  .--.  | |  .--.  | (_)/ /
 *      | |   | |    | | | |    | |   / / _
 *     _| |_  |  `--'  | |  `--'  |  / / (_)
 *    |_____|  '.____.'   '.____.'  /_/
 *
 *    This will contain the class definition of:
 *        BST                 : A class that represents a binary search tree
 *        BST::iterator       : An iterator through BST
 * Author
 *    Martin Nkala and Amber Robbins
 ************************************************************************/

#pragma once

#ifdef DEBUG
#define debug(x) x
#else // !DEBUG
#define debug(x)
#endif // !DEBUG

#include <cassert>
#include <utility>
#include <memory>     // for std::allocator
#include <functional> // for std::less
#include <utility>    // for std::pair

class TestBST; // forward declaration for unit tests
class TestMap;
class TestSet;

namespace custom
{

   template <class TT>
   class set;
   template <class KK, class VV>
   class map;

/*****************************************************************
 * BINARY SEARCH TREE
 * Create a Binary Search Tree
 *****************************************************************/
template <typename T>
class BST
{
   friend class ::TestBST; // give unit tests access to the privates
   friend class ::TestMap;
   friend class ::TestSet;

   template <class KK, class VV>
   friend class map;

   template <class TT>
   friend class set;

   template <class KK, class VV>
   friend void swap(map<KK, VV>& lhs, map<KK, VV>& rhs);
public:
   //
   // Construct
   //

   BST();
   BST(const BST &  rhs);
   BST(      BST && rhs);
   BST(const std::initializer_list<T>& il);
   ~BST();

   //
   // Assign
   //

   BST & operator = (const BST &  rhs);
   BST & operator = (      BST && rhs);
   BST & operator = (const std::initializer_list<T>& il);
   void swap(BST & rhs);

   //
   // Iterator
   //

   class iterator;
   iterator   begin() const noexcept;
   iterator   end()   const noexcept { return iterator(nullptr); }

   //
   // Access
   //

   iterator find(const T& t);

   //
   // Insert
   //

   std::pair<iterator, bool> insert(const T&  t, bool keepUnique = false);
   std::pair<iterator, bool> insert(      T&& t, bool keepUnique = false);

   //
   // Remove
   //

   iterator erase(iterator& it);
   void   clear() noexcept;

   //
   // Status
   //

   bool   empty() const noexcept { return numElements == 0; }
   size_t size()  const noexcept { return numElements;   }


private:

   class BNode;
   BNode * root;              // root node of the binary search tree
   size_t numElements;        // number of elements currently in the tree
};


/*****************************************************************
 * BINARY NODE
 * A single node in a binary tree. Note that the node does not know
 * anything about the properties of the tree so no validation can be done.
 *****************************************************************/
template <typename T>
class BST <T> :: BNode
{
public:
   //
   // Construct
   //
   BNode() : pParent(nullptr), pLeft(nullptr), pRight(nullptr), data(T()), isRed(true) {}

   BNode(const T &  t) : pParent(nullptr), pLeft(nullptr), pRight(nullptr), data(t), isRed(true) {}

   BNode(T&& t) : pParent(nullptr), pLeft(nullptr), pRight(nullptr), data(std::move(t)), isRed(true) {}

   //
   // Insert
   //
   void addLeft (BNode * pNode);
   void addRight(BNode * pNode);
   void addLeft (const T &  t);
   void addRight(const T &  t);
   void addLeft(       T && t);
   void addRight(      T && t);

   void clear(BNode * & pThis)
   {
      if (!pThis)
         return;

      clear(pThis->pLeft);
      clear(pThis->pRight);

      delete pThis;
      pThis = nullptr;
   }

   BNode * copy(const BNode * pSrc)
   {
      if (!pSrc)
         return nullptr;

      try
      {
         BNode * pDest = new BNode(pSrc->data);
         pDest->pLeft = copy(pSrc->pLeft);
         if (pDest->pLeft)
            pDest->pLeft->pParent = pDest;

         pDest->pRight = copy(pSrc->pRight);
         if (pDest->pRight)
            pDest->pRight->pParent = pDest;

         return pDest;
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a node";
      }
   }

   void assign(BNode * & pDest, const BNode * pSrc)
   {
      if (pDest && pSrc)
      {
         pDest->data = pSrc->data;

         assign(pDest->pLeft, pSrc->pLeft);
         if (pDest->pLeft)
            pDest->pLeft->pParent = pDest;

         assign(pDest->pRight, pSrc->pRight);
         if (pDest->pRight)
            pDest->pRight->pParent = pDest;
      }
      else if (pDest && !pSrc)
         clear(pDest);

      else if (!pDest && pSrc)
         pDest = copy(pSrc);
   }


   //
   // Status
   //
   bool isRightChild(BNode * pNode) const { return pNode->data < this->data; }
   bool isLeftChild( BNode * pNode) const { return pNode->data < this->data; }


   //
   // Data
   //
   T data;                  // Actual data stored in the BNode
   BNode* pLeft;          // Left child - smaller
   BNode* pRight;         // Right child - larger
   BNode* pParent;        // Parent
   bool isRed;              // Red-black balancing stuff
};

/**********************************************************
 * BINARY SEARCH TREE ITERATOR
 * Forward and reverse iterator through a BST
 *********************************************************/
template <typename T>
class BST <T> :: iterator
{
   friend class ::TestBST; // give unit tests access to the privates
   friend class ::TestMap;
   friend class ::TestSet;

   template <class KK, class VV>
   friend class map;

   template <class TT>
   friend class set;
public:
   // constructors and assignment
   iterator(BNode * p = nullptr) : pNode(p) { }
   iterator(const iterator & rhs) { *this = rhs; }
   iterator & operator = (const iterator & rhs)
   {
      this->pNode = rhs.pNode;
      return *this;
   }

   // compare
   bool operator == (const iterator & rhs) const { return rhs.pNode == this->pNode; }
   bool operator != (const iterator & rhs) const { return rhs.pNode != this->pNode; }

   // de-reference. Cannot change because it will invalidate the BST
   const T & operator * () const { return pNode->data; }

   // increment and decrement
   iterator & operator ++ ();
   iterator   operator ++ (int postfix)
   {
      auto it = *this;
      for (int i = 0; i < postfix; i++)
         ++(*this);

      return it;
   }

   iterator & operator -- ();
   iterator   operator -- (int postfix)
   {
      auto it = *this;
      for (int i = 0; i < postfix; i++)
         --(*this);

      return it;
   }

   // must give friend status to remove so it can call getNode() from it
   friend BST <T> :: iterator BST <T> :: erase(iterator & it);

private:

    // the node
    BNode * pNode;
};


/*********************************************
 *********************************************
 *********************************************
 ******************** BST ********************
 *********************************************
 *********************************************
 *********************************************/


 /*********************************************
  * BST :: DEFAULT CONSTRUCTOR
  ********************************************/
template <typename T>
BST <T> ::BST() : numElements(0), root(nullptr) { }

/*********************************************
 * BST :: COPY CONSTRUCTOR
 * Copy one tree to another
 ********************************************/
template <typename T>
BST <T> :: BST ( const BST<T>& rhs) : BST() {*this = rhs; }

/*********************************************
 * BST :: MOVE CONSTRUCTOR
 * Move one tree to another
 ********************************************/
template <typename T>
BST <T> :: BST(BST <T> && rhs) : root(nullptr), numElements(0) {  swap(rhs); }

/*********************************************
 * BST :: INITIALIZER LIST CONSTRUCTOR
 * Create a BST from an initializer list
 ********************************************/
template <typename T>
BST <T> ::BST(const std::initializer_list<T>& il) : BST()
{
   for (auto it = il.begin(); it != il.end(); it++)
   {
       insert(*it);
   }
}

/*********************************************
 * BST :: DESTRUCTOR
 ********************************************/
template <typename T>
BST <T> :: ~BST() { clear(); }


/*********************************************
 * BST :: ASSIGNMENT OPERATOR
 * Copy one tree to another
 ********************************************/
template <typename T>
BST <T> & BST <T> :: operator = (const BST <T> & rhs)
{
   root->assign(root, rhs.root);
   numElements = rhs.numElements;
   return *this;
}

/*********************************************
 * BST :: ASSIGNMENT OPERATOR with INITIALIZATION LIST
 * Copy nodes onto a BTree
 ********************************************/
template <typename T>
BST <T> & BST <T> :: operator = (const std::initializer_list<T>& il)
{
   clear();
   numElements = 0;

   for (auto it = il.begin(); it != il.end(); it++)
      insert(*it);

   return *this;
}

/*********************************************
 * BST :: ASSIGN-MOVE OPERATOR
 * Move one tree to another
 ********************************************/
template <typename T>
BST <T> & BST <T> :: operator = (BST <T> && rhs)
{
   clear();
   swap(rhs);
   return *this;
}

/*********************************************
 * BST :: SWAP
 * Swap two trees
 ********************************************/
template <typename T>
void BST <T> :: swap (BST <T>& rhs)
{
   auto temp = rhs.root;
   rhs.root = this->root;
   this->root = temp;

   auto temp2 = rhs.numElements;
   rhs.numElements = this->numElements;
   this->numElements = temp2;
}

/*****************************************************
 * BST :: INSERT
 * Insert a node at a given location in the tree
 ****************************************************/
template <typename T>
std::pair<typename BST <T> :: iterator, bool> BST <T> :: insert(const T & t, bool keepUnique)
{
   // add a node to the tree using pair return
   std::pair<iterator, bool> pairReturn(end(), false);

   // if the tree is empty, create a new node and make it the root
   if (root == nullptr)
   {
      root = new BNode(t);
      numElements++;
      pairReturn.first = iterator(root);
      pairReturn.second = true;
      return pairReturn;
   }

   // if the tree is not empty, find the location to insert the node
   auto p = root;

   while (p)
   {
      // no duplicates
      if (keepUnique)
      {
         if (p->data == t)
         {
            pairReturn.first = iterator(p);
            return pairReturn;
         }
      }

      // if the node is smaller than the current node, go left
      if (t < p->data)
      {
         if (p->pLeft == nullptr)
         {
            p->addLeft(t);
            numElements++;
            pairReturn.first = iterator(p->pLeft);
            pairReturn.second = true;
            return pairReturn;
         }
         else
            p = p->pLeft;
      }

      // if the node is larger than the current node, go right
      else
      {
         if (p->pRight == nullptr)
         {
            p->addRight(t);
            numElements++;
            pairReturn.first = iterator(p->pRight);
            pairReturn.second = true;
            return pairReturn;
         }
         else
            p = p->pRight;
      }
   }
    return pairReturn;
}

template <typename T>
std::pair<typename BST <T> ::iterator, bool> BST <T> ::insert(T && t, bool keepUnique)
{
   // add a node to the tree using pair return
   std::pair<iterator, bool> pairReturn(end(), false);

   // if the tree is empty, create a new node and make it the root
   if (root == nullptr)
   {
      root = new BNode(std::move(t));
      numElements++;
      pairReturn.first = iterator(root);
      pairReturn.second = true;
      return pairReturn;
   }

   // if the tree is not empty, find the location to insert the node
   auto p = root;

   while (p)
   {
      // no duplicates
      if (keepUnique)
      {
         if (p->data == t)
         {
            pairReturn.first = iterator(p);
            return pairReturn;
         }
      }

      // if the node is smaller than the current node, go left
      if (t < p->data)
      {
         if (p->pLeft == nullptr)
         {
            p->addLeft(std::move(t));
            numElements++;
            pairReturn.first = iterator(p->pLeft);
            pairReturn.second = true;
            return pairReturn;
         }
         else
            p = p->pLeft;
      }

      // if the node is larger than the current node, go right
      else
      {
         if (p->pRight == nullptr)
         {
            p->addRight(std::move(t));
            numElements++;
            pairReturn.first = iterator(p->pRight);
            pairReturn.second = true;
            return pairReturn;
         }
         else
            p = p->pRight;
      }
   }
    return pairReturn;
}

/*************************************************
 * BST :: ERASE
 * Remove a given node as specified by the iterator
 ************************************************/
template <typename T>
typename BST <T> ::iterator BST <T> :: erase(iterator & it)
{
   // you want to return the parent of the erased node.
   if (it.pNode)
   {
      auto returnNode = it.pNode->pParent;

      // if the node has no children, just delete it
      if (it.pNode->pLeft == nullptr && it.pNode->pRight == nullptr)
      {
         if (it.pNode->pParent && it.pNode->pParent->pLeft == it.pNode)
         {
            it.pNode->pParent->pLeft = nullptr;
            returnNode = it.pNode->pParent;
         }
         else if (it.pNode->pParent && it.pNode->pParent->pRight == it.pNode)
         {
            it.pNode->pParent->pRight = nullptr;
            returnNode = it.pNode->pParent;
         }

         delete it.pNode;
         numElements--;
         return iterator(returnNode);
      }

      // if the node has left child and no right child,
      // replace it with its left child and delete it
      if (it.pNode->pLeft && it.pNode->pRight == nullptr)
      {
         it.pNode->pLeft->pParent = it.pNode->pParent;
         if (it.pNode->pParent && it.pNode->pParent->pRight == it.pNode)
         {
            it.pNode->pParent->pRight = it.pNode->pLeft;
         }
         else if (it.pNode->pParent && it.pNode->pParent->pLeft == it.pNode)
         {
            it.pNode->pParent->pLeft = it.pNode->pLeft;
         }

         delete it.pNode;
         numElements--;
         return iterator(begin());
      }

      // if the node has right child and no left child,
      // replace it with its right child and delete it
      if (it.pNode->pRight && it.pNode->pLeft == nullptr)
      {
         it.pNode->pRight->pParent = it.pNode->pParent;
         if (it.pNode->pParent && it.pNode->pParent->pRight == it.pNode)
         {
            it.pNode->pParent->pRight = it.pNode->pRight;
         }
         else if (it.pNode->pParent && it.pNode->pParent->pLeft == it.pNode)
         {
            it.pNode->pParent->pLeft = it.pNode->pRight;
         }


         delete it.pNode;
         numElements--;
         return iterator(begin());
      }

      // if the node has both left and right children,
      // replace it with its right child and delete it
      if (it.pNode->pLeft && it.pNode->pRight)
      {
         if (it.pNode->pRight->pLeft == nullptr && it.pNode->pRight->pRight == nullptr)
         {
            it.pNode->pRight->pParent = it.pNode->pParent;
            it.pNode->pRight->pLeft = it.pNode->pLeft;
            it.pNode->pLeft->pParent = it.pNode->pRight;
            if (it.pNode->pParent && it.pNode->pParent->pRight == it.pNode)
            {
               it.pNode->pParent->pRight = it.pNode->pRight;
               returnNode = it.pNode->pRight;
            }
            else if (it.pNode->pParent && it.pNode->pParent->pLeft == it.pNode)
            {
               it.pNode->pParent->pLeft = it.pNode->pRight;
               returnNode = it.pNode->pRight;
            }

            delete it.pNode;
            numElements--;
            return iterator(returnNode);
         }

         if (it.pNode->pRight->pLeft == nullptr && it.pNode->pRight->pRight)
         {
            it.pNode->pRight->pParent = it.pNode->pParent;
            it.pNode->pRight->pLeft = it.pNode->pLeft;
            it.pNode->pLeft->pParent = it.pNode->pRight;
            if (it.pNode->pParent && it.pNode->pParent->pRight == it.pNode)
            {
               it.pNode->pParent->pRight = it.pNode->pRight;
               returnNode = it.pNode->pRight;
            }
            else if (it.pNode->pParent && it.pNode->pParent->pLeft == it.pNode)
            {
               it.pNode->pParent->pLeft = it.pNode->pRight;
               returnNode = it.pNode->pRight;
            }

            delete it.pNode;
            numElements--;
            return iterator(returnNode);
         }

         auto temp = it.pNode->pRight;
         while(temp->pLeft)
         {
            temp = temp->pLeft;
         }

         // assign the right child of temp to the left child of "F"
         it.pNode->pRight->pLeft = temp->pRight;
         temp->pParent = it.pNode->pParent;
         temp->pRight->pParent = it.pNode->pRight;
         temp->pLeft = it.pNode->pLeft;
         temp->pRight = it.pNode->pRight;
         it.pNode->pLeft->pParent = temp;
         it.pNode->pRight->pParent = temp;
         if (it.pNode->pParent && it.pNode->pParent->pRight == it.pNode)
         {
            it.pNode->pParent->pRight = temp;
            returnNode = temp;
         }
         else if (it.pNode->pParent && it.pNode->pParent->pLeft == it.pNode)
         {
            it.pNode->pParent->pLeft = temp;
            returnNode = temp;
         }

         delete it.pNode;
         numElements--;
         return iterator(returnNode);
      }
   }

   return end();
}

/*****************************************************
 * BST :: CLEAR
 * Removes all the BNodes from a tree
 ****************************************************/
template <typename T>
void BST <T> ::clear() noexcept
{
   root->clear(root);
   numElements = 0;
}

/*****************************************************
 * BST :: BEGIN
 * Return the first node (left-most) in a binary search tree
 ****************************************************/
template <typename T>
typename BST <T> :: iterator custom :: BST <T> :: begin() const noexcept
{
   if (root == nullptr)
      return end();

   auto p = root;
      while(p->pLeft)
         p = p->pLeft;

   return iterator(p);
}


/****************************************************
 * BST :: FIND
 * Return the node corresponding to a given value
 ****************************************************/
template <typename T>
typename BST <T> :: iterator BST<T> :: find(const T & t)
{
   auto p = root;

   while (p)
   {
      if (p->data == t)
         return iterator(p);

      if (t < p->data)
         p = p->pLeft;

      else
         p = p->pRight;
   }

   return end();
}

/******************************************************
 ******************************************************
 ******************************************************
 *********************** B NODE ***********************
 ******************************************************
 ******************************************************
 ******************************************************/


/******************************************************
 * BINARY NODE :: ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
template <typename T>
void BST <T> :: BNode :: addLeft (BNode * pNode)
{
   if (pNode)
      pNode->pParent = this;
   pLeft = pNode;
}

/******************************************************
 * BINARY NODE :: ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
template <typename T>
void BST <T> :: BNode :: addRight (BNode * pNode)
{
   if (pNode)
      pNode->pParent = this;
   pRight = pNode;
}

/******************************************************
 * BINARY NODE :: ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
template <typename T>
void BST<T> :: BNode :: addLeft (const T & t)
{
   BNode * pNode = new BNode(t);
   addLeft(pNode);
}

/******************************************************
 * BINARY NODE :: ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
template <typename T>
void BST<T> ::BNode::addLeft(T && t)
{
   BNode * pNode = new BNode(std::move(t));
   addLeft(pNode);
}

/******************************************************
 * BINARY NODE :: ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
template <typename T>
void BST <T> :: BNode :: addRight (const T & t)
{
   BNode * pNode = new BNode(t);
   addRight(pNode);
}

/******************************************************
 * BINARY NODE :: ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
template <typename T>
void BST <T> ::BNode::addRight(T && t)
{
   BNode * pNode = new BNode(std::move(t));
   addRight(pNode);
}



/*************************************************
 *************************************************
 *************************************************
 ****************** ITERATOR *********************
 *************************************************
 *************************************************
 *************************************************/

/**************************************************
 * BST ITERATOR :: INCREMENT PREFIX
 * advance by one
 *************************************************/
template <typename T>
typename BST <T> :: iterator & BST <T> :: iterator :: operator ++ ()
{
   if (pNode)
   {
       if (pNode->pRight)
       {
          pNode = pNode->pRight;
          while (pNode->pLeft)
             pNode = pNode->pLeft;

          return *this;
       }

       if (pNode->pRight == nullptr && pNode->pParent->pLeft == pNode)
       {
          pNode = pNode->pParent;
          return *this;
       }

       if (pNode->pRight == nullptr && pNode->pParent->pRight == pNode)
       {
          while ( pNode->pParent && pNode->pParent->pRight == pNode)
             pNode = pNode->pParent;

          pNode = pNode->pParent;
          return *this;
       }
   }

    return *this;
}

/**************************************************
 * BST ITERATOR :: DECREMENT PREFIX
 * advance by one
 *************************************************/
template <typename T>
typename BST <T> :: iterator & BST <T> :: iterator :: operator -- ()
{
   if (pNode)
   {
   if (pNode->pLeft)
       {
          pNode = pNode->pLeft;
          while (pNode->pRight)
             pNode = pNode->pRight;

          return *this;
       }

       if (pNode->pLeft == nullptr && pNode->pParent->pRight == pNode)
       {
          pNode = pNode->pParent;
          return *this;
       }

       if (pNode->pLeft == nullptr && pNode->pParent->pLeft == pNode)
       {
          while (pNode->pParent && pNode->pParent->pLeft == pNode)
             pNode = pNode->pParent;

          pNode = pNode->pParent;

          return *this;
       }
   }

    return *this;
}

} // namespace custom


