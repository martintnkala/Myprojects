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
 *          Martin Nkala and Amber Robbins
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
      friend void swap(map<KK, VV> &lhs, map<KK, VV> &rhs);

   public:
      //
      // Construct
      //

      BST();
      BST(const BST &rhs);
      BST(BST &&rhs);
      BST(const std::initializer_list<T> &il);
      ~BST();

      //
      // Assign
      //

      BST &operator=(const BST &rhs);
      BST &operator=(BST &&rhs);
      BST &operator=(const std::initializer_list<T> &il);
      void swap(BST &rhs);

      //
      // Iterator
      //

      class iterator;
      iterator begin() const noexcept;
      iterator end() const noexcept { return iterator(nullptr); }

      //
      // Access
      //

      iterator find(const T &t);

      //
      // Insert
      //

      std::pair<iterator, bool> insert(const T &t, bool keepUnique = false);
      std::pair<iterator, bool> insert(T &&t, bool keepUnique = false);

      //
      // Remove
      //

      iterator erase(iterator &it);
      void clear() noexcept;

      //
      // Status
      //

      bool empty() const noexcept { return numElements == 0; }
      size_t size() const noexcept { return numElements; }



   private:
      class BNode;
      void deleteNode(BNode *& pDelete, bool toRight);
      BNode *root;        // root node of the binary search tree
      size_t numElements; // number of elements currently in the tree
   };

   /*****************************************************************
    * BINARY NODE
    * A single node in a binary tree. Note that the node does not know
    * anything about the properties of the tree so no validation can be done.
    *****************************************************************/
   template <typename T>
   class BST<T>::BNode
   {
   public:
      //
      // Construct
      //
      BNode() : pParent(nullptr), pLeft(nullptr), pRight(nullptr), data(T()), isRed(true) {}

      BNode(const T &t) : pParent(nullptr), pLeft(nullptr), pRight(nullptr), data(t), isRed(true) {}

      BNode(T &&t) : pParent(nullptr), pLeft(nullptr), pRight(nullptr), data(std::move(t)), isRed(true) {}

      //
      // Insert
      //
      void addLeft(BNode *pNode);
      void addRight(BNode *pNode);
      void addLeft(const T &t);
      void addRight(const T &t);
      void addLeft(T &&t);
      void addRight(T &&t);

      // Special functions
      void clear(BNode *&pThis);
      BNode * copy(const BNode *pSrc);
      void assign(BNode *&pDest, const BNode *pSrc);

      //
      // Status
      //
      bool isRightChild(BNode *pNode) const { return pNode->data < this->data; }
      bool isLeftChild(BNode *pNode) const { return pNode->data < this->data; }

      //
      // Data
      //
      T data;         // Actual data stored in the BNode
      BNode *pLeft;   // Left child - smaller
      BNode *pRight;  // Right child - larger
      BNode *pParent; // Parent
      bool isRed;     // Red-black balancing stuff
   };

   /**********************************************************
    * BINARY SEARCH TREE ITERATOR
    * Forward and reverse iterator through a BST
    *********************************************************/
   template <typename T>
   class BST<T>::iterator
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
      iterator(BNode *p = nullptr) : pNode(p) {}
      iterator(const iterator &rhs) { *this = rhs; }
      iterator &operator=(const iterator &rhs)
      {
         this->pNode = rhs.pNode;
         return *this;
      }

      // compare
      bool operator==(const iterator &rhs) const { return rhs.pNode == this->pNode; }
      bool operator!=(const iterator &rhs) const { return rhs.pNode != this->pNode; }

      // de-reference. Cannot change because it will invalidate the BST
      const T &operator*() const { return pNode->data; }

      // increment and decrement
      iterator &operator++();
      iterator operator++(int postfix)
      {
         auto it = *this;
         for (int i = 0; i < postfix; i++)
            ++(*this);

         return it;
      }

      iterator &operator--();
      iterator operator--(int postfix)
      {
         auto it = *this;
         for (int i = 0; i < postfix; i++)
            --(*this);

         return it;
      }

      // must give friend status to remove so it can call getNode() from it
      friend BST<T>::iterator BST<T>::erase(iterator &it);

   private:
      // the node
      BNode *pNode;
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
   BST<T>::BST() : numElements(0), root(nullptr) {}

   /*********************************************
    * BST :: COPY CONSTRUCTOR
    * Copy one tree to another
    ********************************************/
   template <typename T>
   BST<T>::BST(const BST<T> &rhs) : BST() { *this = rhs; }

   /*********************************************
    * BST :: MOVE CONSTRUCTOR
    * Move one tree to another
    ********************************************/
   template <typename T>
   BST<T>::BST(BST<T> &&rhs) : root(nullptr), numElements(0) { swap(rhs); }

   /*********************************************
    * BST :: INITIALIZER LIST CONSTRUCTOR
    * Create a BST from an initializer list
    ********************************************/
   template <typename T>
   BST<T>::BST(const std::initializer_list<T> &il) : BST()
   {
      for (auto it = il.begin(); it != il.end(); it++)
         insert(*it);
   }

   /*********************************************
    * BST :: DESTRUCTOR
    ********************************************/
   template <typename T>
   BST<T>::~BST() { clear(); }

   /*********************************************
    * BST :: ASSIGNMENT OPERATOR
    * Copy one tree to another
    ********************************************/
   template <typename T>
   BST<T> &BST<T>::operator=(const BST<T> &rhs)
   {
      // use the assign function from BNode to copy the tree
      root->assign(root, rhs.root);
      numElements = rhs.numElements;
      return *this;
   }

   /*********************************************
    * BST :: ASSIGNMENT OPERATOR with INITIALIZATION LIST
    * Copy nodes onto a BTree
    ********************************************/
   template <typename T>
   BST<T> &BST<T>::operator=(const std::initializer_list<T> &il)
   {
      // clear the tree and insert the nodes from the initializer list
      clear();
      for (auto it = il.begin(); it != il.end(); it++)
         insert(*it);

      return *this;
   }

   /*********************************************
    * BST :: ASSIGN-MOVE OPERATOR
    * Move one tree to another
    ********************************************/
   template <typename T>
   BST<T> &BST<T>::operator=(BST<T> &&rhs)
   {
      // clear the tree and swap the nodes
      clear();
      swap(rhs);
      return *this;
   }

   /*********************************************
    * BST :: SWAP
    * Swap two trees
    ********************************************/
   template <typename T>
   void BST<T>::swap(BST<T> &rhs)
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
   std::pair<typename BST<T>::iterator, bool> BST<T>::insert(const T &t, bool keepUnique)
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
   std::pair<typename BST<T>::iterator, bool> BST<T>::insert(T &&t, bool keepUnique)
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
   typename BST<T>::iterator BST<T>::erase(iterator &it)
   {
      // do nothing if there is nothing to do
      if (it == end())
         return end();

      // remember where we were
      iterator itNext = it;
      BNode * pDelete = it.pNode;

      // if there is only one child (right) or no children.
      if (pDelete->pLeft == nullptr)
      {
         ++itNext;
         deleteNode(pDelete, true);
      }

      else if (pDelete->pRight == nullptr)
      {
         ++itNext;
         deleteNode(pDelete, false);
      }

      else
      {
         // find the in-order successor
         BNode * pIOS = pDelete->pRight;
         while (pIOS->pLeft != nullptr)
            pIOS = pIOS->pLeft;

         pIOS->pLeft = pDelete->pLeft;
         if (pDelete->pLeft)
            pDelete->pLeft->pParent = pIOS;

         if (pDelete->pRight != pIOS)
         {
            if (pIOS->pRight)
               pIOS->pRight->pParent = pIOS->pParent;

            pIOS->pParent->pLeft = pIOS->pRight;

            pIOS->pRight = pDelete->pRight;
            pDelete->pRight->pParent = pIOS;
         }

         pIOS->pParent = pDelete->pParent;
         if (pDelete->pParent && pDelete->pParent->pLeft == pDelete)
            pDelete->pParent->pLeft = pIOS;
         if (pDelete->pParent && pDelete->pParent->pRight == pDelete)
            pDelete->pParent->pRight = pIOS;

         if (root == pDelete)
            root = pIOS;

         itNext = iterator(pIOS);
      }

      numElements--;
      delete pDelete;
      return itNext;
   }

   /*****************************************************
    * BST :: CLEAR
    * Removes all the BNodes from a tree
    ****************************************************/
   template <typename T>
   void BST<T>::clear() noexcept
   {
      root->clear(root);
      numElements = 0;
   }

    template<typename T>
    inline void BST<T>::deleteNode(BNode*& pDelete, bool toRight)
    {
       // Shift everything up
       BNode* pNext = (toRight ? pDelete->pRight : pDelete->pLeft);

       // If we are not the parent, hook ourselves into the existing tree
       if (pDelete != root)
       {
          if (pDelete->pParent->pLeft == pDelete)
          {
             pDelete->pParent->pLeft = nullptr;
             pDelete->pParent->addLeft(pNext);
          }
          else
          {
             pDelete->pParent->pRight = nullptr;
             pDelete->pParent->addRight(pNext);
          }
       }
       else
       {
          root = pNext;
          pNext->pParent = nullptr;
       }
    }

   /*****************************************************
    * BST :: BEGIN
    * Return the first node (left-most) in a binary search tree
    ****************************************************/
   template <typename T>
   typename BST<T>::iterator custom ::BST<T>::begin() const noexcept
   {
      if (root == nullptr)
         return end();

      auto p = root;
      while (p->pLeft)
         p = p->pLeft;

      return iterator(p);
   }

   /*******************************************************
    * BNODE :: CLEAR
    *
    ******************************************************/
   template <typename T>
   inline void BST<T>::BNode::clear(BNode *&pThis)
   {
      if (!pThis)
         return;

      clear(pThis->pLeft);
      clear(pThis->pRight);

      delete pThis;
      pThis = nullptr;
   }

   template <typename T>
   inline typename BST<T>::BNode* BST<T>::BNode::copy(const BNode* pSrc)
    {
       if (!pSrc)
          return nullptr;

       try
       {
          BNode *pDest = new BNode(pSrc->data);
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

    /*****************************************************************
     * BNODE :: ASSIGN
     * Assign one tree to another
     ****************************************************************/
    template <typename T>
    void BST<T>::BNode::assign(BNode *&pDest, const BNode *pSrc)
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

   /****************************************************
    * BST :: FIND
    * Return the node corresponding to a given value
    ****************************************************/
   template <typename T>
   typename BST<T>::iterator BST<T>::find(const T &t)
   {
      // loop through the tree to find the node
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
   void BST<T>::BNode ::addLeft(BNode *pNode)
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
   void BST<T>::BNode ::addRight(BNode *pNode)
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
   void BST<T>::BNode ::addLeft(const T &t)
   {
      BNode *pNode = new BNode(t);
      addLeft(pNode);
   }

   /******************************************************
    * BINARY NODE :: ADD LEFT
    * Add a node to the left of the current node
    ******************************************************/
   template <typename T>
   void BST<T>::BNode::addLeft(T &&t)
   {
      BNode *pNode = new BNode(std::move(t));
      addLeft(pNode);
   }

   /******************************************************
    * BINARY NODE :: ADD RIGHT
    * Add a node to the right of the current node
    ******************************************************/
   template <typename T>
   void BST<T>::BNode ::addRight(const T &t)
   {
      BNode *pNode = new BNode(t);
      addRight(pNode);
   }

   /******************************************************
    * BINARY NODE :: ADD RIGHT
    * Add a node to the right of the current node
    ******************************************************/
   template <typename T>
   void BST<T>::BNode::addRight(T &&t)
   {
      BNode *pNode = new BNode(std::move(t));
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
   typename BST<T>::iterator &BST<T>::iterator ::operator++()
   {
      // if we have a non empty node
      if (pNode)
      {
         // if the node has a right child, go right and then left until you can't go left anymore
         if (pNode->pRight)
         {
            pNode = pNode->pRight;
            while (pNode->pLeft)
               pNode = pNode->pLeft;

            return *this;
         }

         // if the node has no right child, but is a left child, go up
         if (pNode->pRight == nullptr && pNode->pParent->pLeft == pNode)
         {
            pNode = pNode->pParent;
            return *this;
         }

         // if the node has no right child, but is a right child, go up until you are a left child
         if (pNode->pRight == nullptr && pNode->pParent->pRight == pNode)
         {
            while (pNode->pParent && pNode->pParent->pRight == pNode)
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
   typename BST<T>::iterator &BST<T>::iterator ::operator--()
   {
      // if we have a non empty node
      if (pNode)
      {
         // if the node has a left child, go left and then right until you can't go right anymore
         if (pNode->pLeft)
         {
            pNode = pNode->pLeft;
            while (pNode->pRight)
               pNode = pNode->pRight;

            return *this;
         }

         // if the node has no left child, but is a right child, go up
         if (pNode->pLeft == nullptr && pNode->pParent->pRight == pNode)
         {
            pNode = pNode->pParent;
            return *this;
         }

         // if the node has no left child, but is a left child, go up until you are a right child
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
