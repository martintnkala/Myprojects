/***********************************************************************
 * Header:
 *    LIST
 * Summary:
 *    Our custom implementation of std::list
 *      __      __     _______        __
 *     /  |    /  |   |  _____|   _  / /
 *     `| |    `| |   | |____    (_)/ /
 *      | |     | |   '_.____''.   / / _
 *     _| |_   _| |_  | \____) |  / / (_)
 *    |_____| |_____|  \______.' /_/
 *
 *    This will contain the class definition of:
 *        List         : A class that represents a List
 *        ListIterator : An iterator through List
 * Author
 *       Martin Nkala and Amber Robbins
 ************************************************************************/

#pragma once
#include <cassert>     // for ASSERT
#include <iostream>    // for nullptr
#include <new>         // std::bad_alloc
#include <memory>      // for std::allocator

class TestList; // forward declaration for unit tests
class TestHash; // forward declaration for hash used later

namespace custom
{

   /**************************************************
    * LIST
    * Just like std::list
    **************************************************/
   template <typename T, typename A = std::allocator<T>>
   class list
   {
      friend class ::TestList; // give unit tests access to the privates
      friend class ::TestHash;
      friend void swap(list& lhs, list& rhs);
   public:

      //
      // Construct
      //

      list(const A& a = A()) : pHead(nullptr), pTail(nullptr), numElements(0) {}

      list(list <T, A>& rhs, const A& a = A())
      {
         // If the source is empty
         if (rhs.empty())
         {
            pHead = pTail = nullptr;
            numElements = 0;
         }
         // Create a copy of the RHS list
         else
         {
            pHead = pTail = new Node(rhs.pHead->data);
            pHead->pNext = pTail->pNext = pHead->pPrev = pTail->pPrev = nullptr;
            Node* p = pHead;
            for (Node* pRhs = rhs.pHead->pNext; pRhs; pRhs = pRhs->pNext)
            {
               p->pNext = new Node(pRhs->data);
               p->pNext->pPrev = p;
               p = p->pNext;
            }
            // Declare the tail
            pTail = p;
            pTail->pNext = nullptr;
         }
         numElements = rhs.numElements;
      }

      list(list <T, A>&& rhs, const A& a = A());
      list(size_t num, const T& t, const A& a = A());
      list(size_t num, const A& a = A());

      // Constructor that takes an initializer list and an allocator
      list(const std::initializer_list<T>& il, const A& a = A())
      {
         if (il.size() == 0)
         {
            pHead = pTail = nullptr;
            numElements = 0;
         }

         // Initialize the list with elements from the initializer list
         else
         {
            pHead = pTail = new Node(*il.begin());
            pHead->pNext = pTail->pNext = pHead->pPrev = pTail->pPrev = nullptr;
            Node* p = pHead;
            for (auto it = il.begin() + 1; it != il.end(); it++)
            {
               p->pNext = new Node(*it);
               p->pNext->pPrev = p;
               p = p->pNext;
            }
            pTail = p;
            pTail->pNext = nullptr;
         }
         numElements = il.size();
      }

      template <class Iterator>
      list(Iterator first, Iterator last, const A& a = A())
      {
         // Check if the range [first, last) is empty
         if (first == last)
         {
            pHead = pTail = nullptr;
            numElements = 0;
         }

         // Initialize head and tail with a new Node using data from 'first'
         else
         {
            pHead = pTail = new Node(*first);
            pHead->pNext = pTail->pNext = pHead->pPrev = pTail->pPrev = nullptr;
            Node* p = pHead;
            for (auto it = first + 1; it != last; it++)
            {
               p->pNext = new Node(*it);
               p->pNext->pPrev = p;
               p = p->pNext;
            }
            pTail = p;
            pTail->pNext = nullptr;
         }
         numElements = last - first;
      }

      // Destructor
      ~list()
      {
         if (!empty())
            clear();
      }

      //
      // Assign
      //

      list <T, A>& operator = (list <T, A>& rhs);
      list <T, A>& operator = (list <T, A>&& rhs);
      list <T, A>& operator = (const std::initializer_list<T>& il);

      void swap(list <T, A>& rhs)
      {
         std::swap(pHead, rhs.pHead);
         std::swap(pTail, rhs.pTail);
         std::swap(numElements, rhs.numElements);
      }

      //
      // Iterator
      //

      class iterator;
      iterator begin() { return iterator(pHead); }
      iterator rbegin() { return iterator(pTail); }
      iterator end() { return iterator(nullptr); }

      //
      // Access
      //

      T& front();
      T& back();

      //
      // Insert
      //

      void push_front(const T& data);
      void push_front(T&& data);
      void push_back(const T& data);
      void push_back(T&& data);
      iterator insert(iterator it, const T& data);
      iterator insert(iterator it, T&& data);

      //
      // Remove
      //

      void pop_back();
      void pop_front();
      void clear();
      iterator erase(const iterator& it);


      //
      // Status
      //
      bool empty()  const { return pHead == nullptr; }
      size_t size() const { return numElements; }

   private:
      // nested linked list class
      class Node;

      // member variables
      A    alloc;         // use alloacator for memory allocation
      size_t numElements; // though we could count, it is faster to keep a variable
      Node* pHead;       // pointer to the beginning of the list
      Node* pTail;       // pointer to the ending of the list
   };

   /*************************************************
    * NODE
    * the node class.  Since we do not validate any
    * of the setters, there is no point in making them
    * private.  This is the case because only the
    * List class can make validation decisions
    *************************************************/
   template <typename T, typename A>
   class list <T, A> ::Node
   {
   public:
      //
      // Construct
      //
      Node() : data(T()), pNext(nullptr), pPrev(nullptr) {}

      Node(const T& data) : data(data), pNext(nullptr), pPrev(nullptr) {}

      Node(T&& data) : data(std::move(data)), pNext(nullptr), pPrev(nullptr) {}


      //
      // Member Variables
      //

      T data;             // user data
      Node* pNext;       // pointer to next node
      Node* pPrev;       // pointer to previous node
   };

   /*************************************************
    * LIST ITERATOR
    * Iterate through a List, non-constant version
    ************************************************/
   template <typename T, typename A>
   class list <T, A> ::iterator
   {
      friend class ::TestList; // give unit tests access to the privates
      friend class ::TestHash;
      template <typename TT, typename AA>
      friend class custom::list;

   public:
      // constructors, destructors, and assignment operator
      iterator() : p(nullptr) {}

      iterator(Node* pRHS) : p(pRHS) {}

      iterator(const iterator& rhs) : p(rhs.p) {}

      iterator& operator = (const iterator& rhs)
      {
         this->p = rhs.p;
         return *this;
      }

      // equals, not equals operator
      bool operator == (const iterator& rhs) const { return rhs.p == p; }
      bool operator != (const iterator& rhs) const { return rhs.p != p; }

      // dereference operator, fetch a node
      T& operator * ()
      {
         return p->data;
      }

      // postfix increment
      iterator operator ++ (int postfix)
      {
         iterator tmp(*this);
         p = p->pNext;
         return tmp;
      }

      // prefix increment
      iterator& operator ++ ()
      {
         p = p->pNext;
         return *this;
      }

      // postfix decrement
      iterator operator -- (int postfix)
      {
         iterator tmp(*this);
         p = p->pPrev;
         return tmp;
      }

      // prefix decrement
      iterator& operator -- ()
      {
         p = p->pPrev;
         return *this;
      }

      // two friends who need to access p directly
      friend iterator list <T, A> ::insert(iterator it, const T& data);
      friend iterator list <T, A> ::insert(iterator it, T&& data);
      friend iterator list <T, A> ::erase(const iterator& it);

   private:

      typename list <T, A> ::Node* p;
   };

   /*****************************************
    * LIST :: NON-DEFAULT constructors
    * Create a list initialized to a value
    ****************************************/
   template <typename T, typename A>
   list <T, A> ::list(size_t num, const T& t, const A& a)
   {
      if (num == 0) {
         pHead = pTail = nullptr;
         numElements = 0;
      }
      else
      {
         pHead = pTail = new Node(t);
         pHead->pNext = pTail->pNext = pHead->pPrev = pTail->pPrev = nullptr;
         Node* p = pHead;
         for (int i = 1; i < num; i++)
         {
            p->pNext = new Node(t);
            p->pNext->pPrev = p;
            p = p->pNext;
         }
         pTail = p;
         pTail->pNext = nullptr;
      }
      numElements = num;
   }

   /*****************************************
    * LIST :: NON-DEFAULT constructors
    * Create a list initialized to a value
    ****************************************/
   template <typename T, typename A>
   list <T, A> ::list(size_t num, const A& a)
   {
      if (num == 0) {
         pHead = pTail = nullptr;
         numElements = 0;
      }
      else
      {
         pHead = pTail = new Node();
         pHead->pNext = pTail->pNext = pHead->pPrev = pTail->pPrev = nullptr;
         Node* p = pHead;
         for (int i = 1; i < num; i++)
         {
            p->pNext = new Node();
            p->pNext->pPrev = p;
            p = p->pNext;
         }
         pTail = p;
         pTail->pNext = nullptr;
      }
      numElements = num;
   }

   /*****************************************
    * LIST :: MOVE constructors
    * Steal the values from the RHS
    ****************************************/
   template <typename T, typename A>
   list <T, A> ::list(list <T, A>&& rhs, const A& a) :
      numElements(rhs.numElements), pHead(rhs.pHead), pTail(rhs.pTail), alloc(a)
   {
      rhs.pHead = rhs.pTail = nullptr;
      rhs.numElements = 0;
   }

   /**********************************************
    * LIST :: assignment operator - MOVE
    * Copy one list onto another
    *     INPUT  : a list to be moved
    *     OUTPUT :
    *     COST   : O(n) with respect to the size of the LHS
    *********************************************/
   template <typename T, typename A>
   list <T, A>& list <T, A> :: operator = (list <T, A>&& rhs)
   {
      if (empty() && rhs.empty())
         return *this;

      // if the RHS is empty, then we can just clear the LHS
      if (rhs.empty())
         clear();
      else
         swap(rhs);

      rhs.clear();
      return *this;
   }

   /**********************************************
    * LIST :: assignment operator
    * Copy one list onto another
    *     INPUT  : a list to be copied
    *     OUTPUT :
    *     COST   : O(n) with respect to the number of nodes
    *********************************************/
   template <typename T, typename A>
   list <T, A>& list <T, A> :: operator = (list <T, A>& rhs)
   {
      // If RHS is empty, clear left.
      if (rhs.empty())
         clear();

      // Going from standard to empty
      if(empty() && rhs.size() > 0)
      {
         for (auto& i : rhs)
            push_back(i);
      }

      // If the LHS bigger than the RHS
      if (rhs.size() < size())
      {
         Node* pSrc = rhs.pHead;
         Node* pDes = pHead;

         while (pSrc != nullptr)
         {
            pDes->data = pSrc->data;
            pSrc = pSrc->pNext;
            pDes = pDes->pNext;
         }
         pop_back();
         
      }

      // If the RHS bigger than the LHS
      if (size() < rhs.size())
      {
         Node* pSrc = rhs.pHead;
         Node* pDes = pHead;

         // If pSrc and pSrc->pNext not nullptr
         while (pSrc != nullptr && pSrc->pNext != nullptr)
         {
            pDes->data = pSrc->data;
            pSrc = pSrc->pNext;
            pDes = pDes->pNext;
            
            // If pNext is nullptr
            if (pDes == nullptr)
               push_back(pSrc->data);
         }
      }
      return *this;
   }

   /**********************************************
    * LIST :: assignment operator
    * Copy one list onto another
    *     INPUT  : a list to be copied
    *     OUTPUT :
    *     COST   : O(n) with respect to the number of nodes
    *********************************************/
   template <typename T, typename A>
   list <T, A>& list <T, A> :: operator = (const std::initializer_list<T>& rhs)
   {
      Node* pDes = pHead;

      // If the list are the same size
      if (size() == rhs.size())
      {
         for (auto it = rhs.begin(); it != rhs.end(); ++it)
         {
            pDes->data = *it;
            pDes = pDes->pNext;
         }
      }

      // If the RHS is bigger than the LHS
      else if (size() < rhs.size())
      {
         for (auto it = rhs.begin(); it != rhs.end(); ++it)
         {
            pDes->data = *it;

            if (pDes->pNext == nullptr)
            {
               for (++it; it != rhs.end(); ++it)
                  push_back(*it);
               pDes = pDes->pNext;
            }
            break; // exits loop
         }
      }

      // If the LHS is bigger than the RHS
      else if (size() > rhs.size())
      {
         while (size() > rhs.size())
            pop_back();

         for (auto it = rhs.begin(); it != rhs.end(); ++it)
         {
            pDes->data = *it;
            pDes = pDes->pNext;
         }
      }
      return *this;
   }

   /**********************************************
    * LIST :: CLEAR
    * Remove all the items currently in the linked list
    *     INPUT  :
    *     OUTPUT :
    *     COST   : O(n) with respect to the number of nodes
    *********************************************/
   template <typename T, typename A>
   void list <T, A> ::clear()
   {
      Node* pNext;
      for (Node* p = pHead; p; p = pNext)
      {
         pNext = p->pNext;
         delete p;
      }
      pHead = nullptr;
      pTail = nullptr;
      numElements = 0;
   }

   /*********************************************
    * LIST :: PUSH BACK
    * add an item to the end of the list
    *    INPUT  : data to be added to the list
    *    OUTPUT :
    *    COST   : O(1)
    *********************************************/
   template <typename T, typename A>
   void list <T, A> ::push_back(const T& data)
   {
      if (!pHead)
      {
         pHead = pTail = new Node(data);
         pHead->pNext = pTail->pNext = pHead->pPrev = pTail->pPrev = nullptr;
      }
      else
      {
         pTail->pNext = new Node(data);
         pTail->pNext->pPrev = pTail;
         pTail = pTail->pNext;
      }
      numElements++;
   }

   template <typename T, typename A>
   void list <T, A> ::push_back(T&& data)
   {
      if (!pHead)
      {
         pHead = pTail = new Node(std::move(data));
         pHead->pNext = pTail->pNext = pHead->pPrev = pTail->pPrev = nullptr;
      }
      else
      {
         pTail->pNext = new Node(std::move(data));
         pTail->pNext->pPrev = pTail;
         pTail = pTail->pNext;
      }
      numElements++;
   }

   /*********************************************
    * LIST :: PUSH FRONT
    * add an item to the head of the list
    *     INPUT  : data to be added to the list
    *     OUTPUT :
    *     COST   : O(1)
    *********************************************/
   template <typename T, typename A>
   void list <T, A> ::push_front(const T& data)
   {
      if (!pHead)
      {
         pHead = pTail = new Node(data);
         pHead->pNext = pTail->pNext = pHead->pPrev = pTail->pPrev = nullptr;
      }
      else
      {
         pHead->pPrev = new Node(data);
         pHead->pPrev->pNext = pHead;
         pHead = pHead->pPrev;
      }
      numElements++;
   }

   template <typename T, typename A>
   void list <T, A> ::push_front(T&& data)
   {
      if (!pHead)
      {
         pHead = pTail = new Node(std::move(data));
         pHead->pNext = pTail->pNext = pHead->pPrev = pTail->pPrev = nullptr;
      }
      else
      {
         pHead->pPrev = new Node(std::move(data));
         pHead->pPrev->pNext = pHead;
         pHead = pHead->pPrev;
      }
      numElements++;
   }


   /*********************************************
    * LIST :: POP BACK
    * remove an item from the end of the list
    *    INPUT  :
    *    OUTPUT :
    *    COST   : O(1)
    *********************************************/
   template <typename T, typename A>
   void list <T, A> ::pop_back()
   {
      if (!pTail)
         return;

      Node* pDel = pTail;
      pTail = pTail->pPrev;

      if (pTail)
         pTail->pNext = nullptr;
      else
         pHead = nullptr;

      delete pDel;
      numElements--;
   }

   /*********************************************
    * LIST :: POP FRONT
    * remove an item from the front of the list
    *    INPUT  :
    *    OUTPUT :
    *    COST   : O(1)
    *********************************************/
   template <typename T, typename A>
   void list <T, A> ::pop_front()
   {
      if (!pHead)
         return;

      Node* pDel = pHead;
      pHead = pHead->pNext;

      // this takes care of single element in the list as well as multiple elements
      if (pHead)
         pHead->pPrev = nullptr;
      else
         pTail = nullptr;

      delete pDel;
      numElements--;
   }

   /*********************************************
    * LIST :: FRONT
    * retrieves the first element in the list
    *     INPUT  :
    *     OUTPUT : data to be displayed
    *     COST   : O(1)
    *********************************************/
   template <typename T, typename A>
   T& list <T, A> ::front()
   {
      if (pHead)
         return pHead->data;
      else
         return *(new T);
   }

   /*********************************************
    * LIST :: BACK
    * retrieves the last element in the list
    *     INPUT  :
    *     OUTPUT : data to be displayed
    *     COST   : O(1)
    *********************************************/
   template <typename T, typename A>
   T& list <T, A> ::back()
   {
      if (pTail)
         return pTail->data;
      else
         return *(new T);
   }


   /******************************************
    * LIST :: REMOVE
    * remove an item from the middle of the list
    *     INPUT  : an iterator to the item being removed
    *     OUTPUT : iterator to the new location
    *     COST   : O(1)
    ******************************************/
   template <typename T, typename A>
   typename list <T, A> ::iterator  list <T, A> ::erase(const list <T, A> ::iterator& it)
   {
      if (it.p == nullptr)
         return end();

      iterator itNext = end();
      if (it.p->pNext)
      {
         it.p->pNext->pPrev = it.p->pPrev;
         itNext = it.p->pNext;
      }
      else
         pTail = pTail->pPrev;

      if (it.p->pPrev)
         it.p->pPrev->pNext = it.p->pNext;
      else
         pHead = pHead->pNext;

      delete it.p;
      numElements--;
      return itNext;
   }

   /******************************************
    * LIST :: INSERT
    * add an item to the middle of the list
    *     INPUT  : data to be added to the list
    *              an iterator to the location where it is to be inserted
    *     OUTPUT : iterator to the new item
    *     COST   : O(1)
    ******************************************/
   template <typename T, typename A>
   typename list <T, A> ::iterator list <T, A> ::insert(list <T, A> ::iterator it,
      const T& data)
   {
      try
      {
         if (it.p == nullptr)
         {
            push_back(data);
            return iterator(pTail);
         }
         else if (it.p->pPrev == nullptr)
         {
            push_front(data);
            return iterator(pHead);
         }
         else
         {
            Node* pNew = new Node(data);
            pNew->pNext = it.p;
            pNew->pPrev = it.p->pPrev;
            it.p->pPrev->pNext = pNew;
            it.p->pPrev = pNew;
            numElements++;
            return iterator(pNew);
         }
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new node for a list";
      }
   }

   /******************************************
    * LIST :: INSERT
    * add several items into the middle of the list
    *     INPUT  : data to be added to the list
    *              an iterator to the location where it is to be inserted
    *     OUTPUT : iterator to the new item
    *     COST   : O(1)
    ******************************************/
   template <typename T, typename A>
   typename list <T, A> ::iterator list <T, A> ::insert(list <T, A> ::iterator it,
      T&& data)
   {
      try
      {
         if (it.p == nullptr)
         {
            push_back(std::move(data));
            return iterator(pTail);
         }
         else if (it.p->pPrev == nullptr)
         {
            push_front(std::move(data));
            return iterator(pHead);
         }
         else
         {
            Node* pNew = new Node(std::move(data));
            pNew->pNext = it.p;
            pNew->pPrev = it.p->pPrev;
            it.p->pPrev->pNext = pNew;
            it.p->pPrev = pNew;
            numElements++;
            return iterator(pNew);
         }
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new node for a list";
      }
   }

   /**********************************************
    * LIST :: assignment operator - MOVE
    * Copy one list onto another
    *     INPUT  : a list to be moved
    *     OUTPUT :
    *     COST   : O(n) with respect to the size of the LHS
    *********************************************/
   template <typename T, typename A>
   void swap(list <T, A>& lhs, list <T, A>& rhs)
   {
      lhs.numElements = 99;
   }

}; // namespace custom


