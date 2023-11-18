/***********************************************************************
 * Header:
 *    PRIORITY QUEUE
 * Summary:
 *    Our custom implementation of std::priority_queue
 *      __      __     _______        __
 *     /  |    /  |   |  _____|   _  / /
 *     `| |    `| |   | |____    (_)/ /
 *      | |     | |   '_.____''.   / / _
 *     _| |_   _| |_  | \____) |  / / (_)
 *    |_____| |_____|  \______.' /_/
 *
 *
 *    This will contain the class definition of:
 *        priority_queue          : A class that represents a Priority Queue
 * Author
 *       Martin Nkala and Amber Robbins
 ************************************************************************/

#pragma once

#include <cassert>
#include "vector.h" // for default underlying container

class TestPQueue;    // forward declaration for unit test class

namespace custom
{

/*************************************************
 * P QUEUE
 * Create a priority queue.
 *************************************************/
template<class T, class Container = custom::vector<T>, class Compare = std::less<T>>
class priority_queue
{
   friend class ::TestPQueue; // give the unit test class access to the privates
   template <class TT, class CContainer, class CCompare>
   friend void swap(priority_queue<TT, CContainer, CCompare>& lhs, priority_queue<TT, CContainer, CCompare>& rhs);

public:

   //
   // construct
   //
   priority_queue(const Compare & c = Compare()) : compare(c), container()
   {
   }
   priority_queue(const priority_queue &  rhs, const Compare & c = Compare()): compare(c), container(rhs.container)
   {
   }
   priority_queue(priority_queue && rhs, const Compare & c = Compare()) : compare(c), container(std::move(rhs.container))
   {
   }
   template <class Iterator>
   priority_queue(Iterator first, Iterator last, const Compare & c = Compare())
   {
      // reserve enough space for the container
      container.reserve(last - first);
      // copy the items using the push function
      for (auto it = first; it != last; ++it)
         push(*it);
   }
   explicit priority_queue (const Compare& c, Container && rhs)
   {
      // percolate down from the top
      container.reserve(rhs.size());
      for (auto it = rhs.begin(); it != rhs.end(); ++it)
         push(std::move(*it));
   }
   explicit priority_queue (const Compare& c, Container & rhs)
   {
      // percolate down from the top
      container.reserve(rhs.size());
      for (auto it = rhs.begin(); it != rhs.end(); ++it)
         push(*it);
   }
  ~priority_queue()
   {
      // remove all items from the container using pop
      while (!empty())
         pop();
   }

   //
   // Access
   //
   const T & top() const;

   //
   // Insert
   //
   void  push(const T& t);
   void  push(T&& t);

   //
   // Remove
   //
   void  pop();

   //
   // Status
   //
   size_t size()  const
   {
      return container.size();
   }
   bool empty() const
   {
      return container.empty();
   }
   
private:

   bool percolateDown(size_t indexHeap);      // fix heap from index down. This is a heap index!

   Container container;       // underlying container (probably a vector)
   Compare   compare;         // comparision operator

};

/************************************************
 * P QUEUE :: TOP
 * Get the maximum item from the heap: the top item.
 ***********************************************/
template <class T, class Container, class Compare>
const T & priority_queue <T, Container, Compare> :: top() const
{
   // use try/catch to throw an error if the container is empty
   try
   {
      if (empty())
         throw std::out_of_range("std:out_of_range");

      // return the first item in the container
      return container.front();
   }
   catch (const std::out_of_range & error)
   {
      // throw the error
      throw;
   }
}

/**********************************************
 * P QUEUE :: POP
 * Delete the top item from the heap.
 **********************************************/
template <class T, class Container, class Compare>
void priority_queue <T, Container, Compare> :: pop()
{
   // if the heap is empty, return
   if (empty())
      return;

   // swap the first and last items
   swap(container.front(), container.back());

   // remove the last item
   container.pop_back();

   // percolate down from the top
   percolateDown(1);
}

/*****************************************
 * P QUEUE :: PUSH
 * Add a new element to the heap, reallocating as necessary
 ****************************************/
template <class T, class Container, class Compare>
void priority_queue <T, Container, Compare> :: push(const T & t)
{
   // push the item onto the back of the container
   container.push_back(t);

   // get the index of the parent of the new item
   size_t indexParent = size() / 2;

   // keep calling percolate function while indexParent
   // is greater than 0 and percolateDown returns true
   while (indexParent > 0 && percolateDown(indexParent))
      indexParent /= 2;
}
template <class T, class Container, class Compare>
void priority_queue <T, Container, Compare> :: push(T && t)
{
   // push the item onto the back of the container
   container.push_back(std::move(t));

   // get the index of the parent of the new item
   size_t indexParent = size() / 2;

   // keep calling percolate function while indexParent
   // is greater than 0 and percolateDown returns true
   while (indexParent > 0 && percolateDown(indexParent))
      indexParent /= 2;
}

/************************************************
 * P QUEUE :: PERCOLATE DOWN
 * The item at the passed index may be out of heap
 * order. Take care of that little detail!
 * Return TRUE if anything changed.
 ************************************************/
template <class T, class Container, class Compare>
bool priority_queue <T, Container, Compare> :: percolateDown(size_t indexHeap)
{
   // if the index is not within range, return false
   if (indexHeap > size())
      return false;

   // find the child with whom to swap
   size_t indexLeft = indexHeap * 2;
   size_t indexRight = indexLeft + 1;

   // if the left child is not within range, return false
   if (indexLeft > size())
      return false;

   // find the bigger child and store its index in indexLarge
   size_t indexLarge = indexLeft;
   if (indexRight <= size() && compare(container[indexLeft-1], container[indexRight-1]))
      indexLarge = indexRight;

   // if the larger child is larger than the parent, swap and call percolateDown again on the new index
   if (compare(container[indexHeap-1], container[indexLarge-1]))
   {
      swap(container[indexHeap-1], container[indexLarge-1]);
      percolateDown(indexLarge);
      return true;
   }

   return false;
}

/************************************************
 * SWAP
 * Swap the contents of two priority queues
 ************************************************/
template <class T, class Container, class Compare>
inline void swap(custom::priority_queue <T, Container, Compare> & lhs,
                 custom::priority_queue <T, Container, Compare> & rhs)
{
   // swap the underlying containers and the comparison operator
   std::swap(lhs.container, rhs.container);
   std::swap(lhs.compare, rhs.compare);
}

}; 
