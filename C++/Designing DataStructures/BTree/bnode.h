/***********************************************************************
 * Header:
 *    BINARY NODE
 * Summary:
 *    One node in a binary tree (and the functions to support them).
 *      __      __     _______        __
 *     /  |    /  |   |  _____|   _  / /
 *     `| |    `| |   | |____    (_)/ /
 *      | |     | |   '_.____''.   / / _
 *     _| |_   _| |_  | \____) |  / / (_)
 *    |_____| |_____|  \______.' /_/
 *
 *    This will contain the class definition of:
 *        BNode         : A class representing a BNode
 *    Additionally, it will contain a few functions working on Node
 * Author
 *    Martin Nkala and Amber Robbins
 ************************************************************************/

#pragma once

#include <iostream>  // for OFSTREAM
#include <cassert>

using namespace std;

/*****************************************************************
 * BNODE
 * A single node in a binary tree.  Note that the node does not know
 * anything about the properties of the tree so no validation can be done.
 *****************************************************************/
template <class T>
class BNode
{
public:
    //
    // Construct
    //
    BNode() : pParent(nullptr), pLeft(nullptr), pRight(nullptr), data(T()) {}

    BNode(const T &  t) : pParent(nullptr), pLeft(nullptr), pRight(nullptr), data(t) {}

    BNode(T&& t) : pParent(nullptr), pLeft(nullptr), pRight(nullptr), data(std::move(t)) {}

    //
    // Data
    //
    BNode <T> * pLeft;
    BNode <T> * pRight;
    BNode <T> * pParent;
    T data;
};

/*******************************************************************
 * SIZE BTREE
 * Return the size of a b-tree under the current node
 *******************************************************************/
template <class T>
inline size_t size(const BNode <T> * p)
{
   // Recursive call
   if (nullptr == p) // Base case
      return 0;
   else
      return size(p->pLeft) + 1 + size(p->pRight); // "+1" because we are adding the root
}


/******************************************************
 * ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
template <class T>
inline void addLeft(BNode <T> * pNode, BNode <T> * pAdd)
{
   // If the node is not null, set the parent of the node to the current node
   if (pAdd)
      pAdd->pParent = pNode;

   // Set the left node to the node to be added
   pNode->pLeft = pAdd;
}

/******************************************************
 * ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
template <class T>
inline void addRight (BNode <T> * pNode, BNode <T> * pAdd)
{
   // If the node is not null, set the parent of the node to the current node
   if (pAdd)
      pAdd->pParent = pNode;

   // Set the right node to the node to be added
   pNode->pRight = pAdd;
}

/******************************************************
 * ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
template <class T>
inline void addLeft (BNode <T> * pNode, const T & t)
{
   // Create a new node with the data
   BNode<T> * pAdd = new BNode<T>(t);

   // Set the parent of the node to the current node
   pAdd->pParent = pNode;

   // Set the left node to the node to be added
   pNode->pLeft = pAdd;
}

template <class T>
inline void addLeft(BNode <T>* pNode, T && t)
{
   // Create a new node with the data
   BNode<T> * pAdd = new BNode<T>(std::move(t));

   // Set the parent of the node to the current node
   pAdd->pParent = pNode;

   // Set the left node to the node to be added
   pNode->pLeft = pAdd;
}

/******************************************************
 * ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
template <class T>
void addRight (BNode <T> * pNode, const T & t)
{
   // Create a new node with the data
   BNode<T> * pAdd = new BNode<T>(t);

   // Set the parent of the node to the current node
   pAdd->pParent = pNode;

   // Set the right node to the node to be added
   pNode->pRight = pAdd;
}

template <class T>
void addRight(BNode <T>* pNode, T && t)
{
   // Create a new node with the data
   BNode<T> * pAdd = new BNode<T>(std::move(t));

   // Set the parent of the node to the current node
   pAdd->pParent = pNode;

   // Set the right node to the node to be added
   pNode->pRight = pAdd;
}

/*****************************************************
 * DELETE BINARY TREE
 * Delete all the nodes below pThis including pThis
 * using postfix traverse: LRV
 ****************************************************/
template <class T>
void clear(BNode <T> * & pThis)
{
   // If the node is null, return
   if (nullptr == pThis)
      return;

   // If the node is not null, delete the left and right nodes
   clear(pThis->pLeft);
   clear(pThis->pRight);

   // Delete the current node and set it to null
   delete pThis;
   pThis = nullptr;
}

/***********************************************
 * SWAP
 * Swap the list from LHS to RHS
 *   COST   : O(1)
 **********************************************/
template <class T>
inline void swap(BNode <T>*& pLHS, BNode <T>*& pRHS)
{
   // Create a temporary node and swap the nodes
   BNode<T>* pTemp = pLHS;
   pLHS = pRHS;
   pRHS = pTemp;
}

/**********************************************
 * COPY BINARY TREE
 * Copy pSrc->pRight to pDest->pRight and
 * pSrc->pLeft onto pDest->pLeft
 *********************************************/
template <class T>
BNode <T> * copy(const BNode <T> * pSrc)
{
   // If the source is null, return null
   if (nullptr == pSrc)
      return nullptr;

   try
   {
      // Create a new node with the data
      auto * pDest = new BNode<T>(pSrc->data);

      // Copy the left and right nodes recursively and set the parent of the nodes
      pDest->pLeft = copy(pSrc->pLeft);
      if (pDest->pLeft)
         pDest->pLeft->pParent = pDest;

      pDest->pRight = copy(pSrc->pRight);
      if (pDest->pRight)
         pDest->pRight->pParent = pDest;

      // Return the new node
      return pDest;
   }
   catch (bad_alloc)
   {
      throw "ERROR: Unable to allocate a new node for a tree";
   }
}

/**********************************************
 * assign
 * copy the values from pSrc onto pDest preserving
 * as many of the nodes as possible.
 *********************************************/
template <class T>
void assign(BNode <T> * & pDest, const BNode <T>* pSrc)
{
   if (pDest && pSrc)
   {
      // Copy the data
      pDest->data = pSrc->data;

      // Copy the left nodes recursively and set the parent of the nodes
      assign(pDest->pLeft, pSrc->pLeft);
      if (pDest->pLeft)
         pDest->pLeft->pParent = pDest;

      // Copy the right nodes recursively and set the parent of the nodes
      assign(pDest->pRight, pSrc->pRight);
      if (pDest->pRight)
         pDest->pRight->pParent = pDest;
   }
   else if (pDest && pSrc == nullptr)
      clear(pDest);

   else if (nullptr == pDest && pSrc)
      pDest = copy(pSrc);
}
