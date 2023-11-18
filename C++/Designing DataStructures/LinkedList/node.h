/***********************************************************************
 * Header:
 *    NODE
 * Summary:
 *    One node in a linked list (and the functions to support them).
 *      __      __     _______        __
 *     /  |    /  |   |  _____|   _  / /
 *     `| |    `| |   | |____    (_)/ /
 *      | |     | |   '_.____''.   / / _
 *     _| |_   _| |_  | \____) |  / / (_)
 *    |_____| |_____|  \______.' /_/
 *
 *    This will contain the class definition of:
 *        Node         : A class representing a Node
 *    Additionally, it will contain a few functions working on Node
 * Author
 *    Martin Nkala and Amber Robbins
 ************************************************************************/

#pragma once

#include <cassert>     // for ASSERT
#include <iostream>    // for NULL

/*************************************************
 * NODE
 * the node class.  Since we do not validate any
 * of the setters, there is no point in making them
 * private.  This is the case because only the
 * List class can make validation decisions
 *************************************************/
template <class T>
class Node
{
public:
    //
    // Construct
    //
    //
    // Construct
    //

    Node() : data(T()), pNext(nullptr), pPrev(nullptr)                      {}

    Node(const T& data) : data(data), pNext(nullptr), pPrev(nullptr)        {}

    Node(T&& data) : data(std::move(data)), pNext(nullptr), pPrev(nullptr)  {}

    //
    // Member variables
    //

    T data;                 // user data
    Node <T> * pNext;       // pointer to next node
    Node <T> * pPrev;       // pointer to previous node
};

/***********************************************
 * COPY
 * Copy the list from the pSource and return
 * the new list
 *   INPUT  : the list to be copied
 *   OUTPUT : return the new list
 *   COST   : O(n)
 **********************************************/
template <class T>
inline Node <T> * copy(const Node <T> * pSource)
{
   if (pSource == nullptr)
      return nullptr;

   Node<T>* pDestination = new Node<T>(pSource->data);
   Node<T>* pDestinationHead = pDestination;

   while (pSource->pNext)
   {
      pDestination->pNext = new Node<T>(pSource->pNext->data);
      pDestination->pNext->pPrev = pDestination;
      pDestination = pDestination->pNext;
      pSource = pSource->pNext;
   }

   return pDestinationHead;
}

/***********************************************
 * Assign
 * Copy the values from pSource into pDestination
 * reusing the nodes already created in pDestination if possible.
 *   INPUT  : the list to be copied
 *   OUTPUT : return the new list
 *   COST   : O(n)
 **********************************************/
template <class T>
inline void assign(Node<T>*& pDestination, const Node<T>* pSource)
{
   // if both lists are empty, then return
   if (pSource == nullptr && pDestination == nullptr)
      return;

   // if destination is empty, then copy source
   if (pDestination == nullptr && pSource != nullptr)
   {
      pDestination = copy(pSource);
      return;
   }

   // create a pointer to the head of the destination list
   Node<T>* pDestinationHead = nullptr;
   Node<T>* pPrevious = nullptr;

   if (pDestination != nullptr)
      pDestinationHead = pDestination;

   // copies as many values from pSource to pDestination
   // as space allows
   while (pDestination && pSource)
   {
      // copy data into pDestination node
      pDestination->data = pSource->data;

      // current pDestination will be linked
      // to next node by pPrev
      pPrevious = pDestination;

      // move forward one node
      pDestination = pDestination->pNext;

      // give pPrev a memory address if
      // curren't node isn't null
      if (pDestination != nullptr)
         pDestination->pPrev = pPrevious;

      // move pSource forward one node
      pSource = pSource->pNext;
   }

   // append new nodes onto pDestination
   // when pSource is longer
   if (pDestination == nullptr)
   {
      // move back one node so pDes isn't null
      if (pPrevious != nullptr)
         pDestination = pPrevious;

      while (pSource != nullptr)
      {
         Node<T>* pDestEnd = pDestination;

         // creates a node using a value from pSource
         pDestEnd = insert(pDestEnd, pSource->data, true);


         // update original pDestination pointer with
         // the new node if it is currently empty
         if (pDestination == nullptr)
         {
            pDestination = pDestEnd;
         }

         // move onto next pSource node
         pSource = pSource->pNext;
      }
      pDestination = pDestinationHead;
      return;
   }

   // check if pSource has reached its end
   if (pSource == nullptr)
   {
      Node<T>* pDestinationTemp = nullptr;

      // While pDestination has more nodes, then remove
      // each of its extra nodes
      while (pDestination != nullptr)
      {
         bool setToNull = false;

         // if there is a previous node, set its
         // pNext link to null
         if (pDestination->pPrev != nullptr)
         {
            pDestination->pPrev->pNext = nullptr;
         }
         else
         {
            setToNull = true;
         }

         // placeholder for node to be removed
         pDestinationTemp = pDestination;


         // if another node comes after the node
         // to be removed, then move forward
         if (pDestination->pNext != nullptr)
         {
            pDestination = pDestination->pNext;

            // remove previous node
            clear(pDestinationTemp);
            pDestinationTemp = nullptr;
         }
            // end of list is reached
         else
         {
            // move back to the head of the list
            pDestination = pDestinationHead;

            // remove final node and return
            clear(pDestinationTemp);
            pDestinationTemp = nullptr;
            return;
         }

         if (setToNull)
            pDestination = nullptr;
      }


   }
      // when both lists are the same size
   else
      pDestination = pDestinationHead;
}


/***********************************************
 * SWAP
 * Swap the list from LHS to RHS
 *   COST   : O(1)
 **********************************************/
template <class T>
inline void swap(Node<T>*& pLHS, Node<T>*& pRHS)
{
   Node<T>* pTemp = pLHS;
   pLHS = pRHS;
   pRHS = pTemp;
}

/***********************************************
 * REMOVE
 * Remove the node pSource in the linked list
 *   INPUT  : the node to be removed
 *   OUTPUT : the pointer to the parent node
 *   COST   : O(1)
 **********************************************/
template <class T>
inline Node <T> * remove(const Node <T> * pRemove)
{
   Node<T>* pReturn;

   if (pRemove == nullptr)
      return nullptr;

   if (pRemove->pPrev != nullptr)
      pRemove->pPrev->pNext = pRemove->pNext;

   if (pRemove->pNext != nullptr)
      pRemove->pNext->pPrev = pRemove->pPrev;

   if (pRemove->pPrev != nullptr)
      pReturn = pRemove->pPrev;
   else
      pReturn = pRemove->pNext;

   delete pRemove;

   return pReturn;
}


/**********************************************
 * INSERT
 * Insert a new node the the value in "t" into a linked
 * list immediately before the current position.
 *   INPUT   : t - the value to be used for the new node
 *             pCurrent - a pointer to the node before which
 *                we will be inserting the new node
 *             after - whether we will be inserting after
 *   OUTPUT  : return the newly inserted item
 *   COST    : O(1)
 **********************************************/
template <class T>
inline Node <T> * insert(Node <T> * pCurrent,
                         const T & t,
                         bool after = false)
{
   // Created a new node with pointer pNew
   Node<T>* pNew = new Node<T>(t);

   // Before pCurrent
   if (pCurrent != nullptr && after == false)
   {
      pNew->pNext = pCurrent;
      pNew->pPrev = pCurrent->pPrev;
      pCurrent->pPrev = pNew;

      if (pNew->pPrev != nullptr)
         pNew->pPrev->pNext = pNew;

   }
      // After pCurrent
   else if (pCurrent != nullptr && after == true)
   {
      pNew->pNext = pCurrent->pNext;
      pNew->pPrev = pCurrent;

      if (pCurrent->pNext != nullptr)
         pCurrent->pNext->pPrev = pNew;

      pCurrent->pNext = pNew;
   }

   return pNew;
}

/******************************************************
 * SIZE
 * Find the size an unsorted linked list.
 *  INPUT   : a pointer to the head of the linked list
 *            the value to be found
 *  OUTPUT  : number of nodes
 *  COST    : O(n)
 ********************************************************/
template <class T>
inline size_t size(const Node <T> * pHead)
{
   size_t size = 0;

   while (pHead != nullptr)
   {
      size++;
      pHead = pHead->pNext;
   }

   return size;
}

/***********************************************
 * DISPLAY
 * Display all the items in the linked list from here on back
 *    INPUT  : the output stream
 *             pointer to the linked list
 *    OUTPUT : the data from the linked list on the screen
 *    COST   : O(n)
 **********************************************/
template <class T>
inline std::ostream & operator << (std::ostream & out, const Node <T> * pHead)
{
   return out;
}

/*****************************************************
 * FREE DATA
 * Free all the data currently in the linked list
 *   INPUT   : pointer to the head of the linked list
 *   OUTPUT  : pHead set to NULL
 *   COST    : O(n)
 ****************************************************/
template <class T>
inline void clear(Node <T> * & pHead) {
   while (pHead != nullptr) {
      Node<T> *pDelete;

      pDelete = pHead;
      pHead = pHead->pNext;
      delete pDelete;
   }
}
