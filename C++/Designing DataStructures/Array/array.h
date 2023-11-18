/***********************************************************************
 * Header:
 *    Array
 * Summary:
 *    Our custom implementation of std::array
 *      __       ____       ____         __
 *     /  |    .'    '.   .'    '.   _  / /
 *     `| |   |  .--.  | |  .--.  | (_)/ /
 *      | |   | |    | | | |    | |   / / _
 *     _| |_  |  `--'  | |  `--'  |  / / (_)
 *    |_____|  '.____.'   '.____.'  /_/
 *
 *    This will contain the class definition of:
 *       array             : similar to std::array
 *       array :: iterator : an iterator through the array
 * Author
 *    <your names here>
 ************************************************************************/

#pragma once

#include <stdexcept>

class TestArray;

namespace custom
{

/************************************************
 * ARRAY
 * A class that holds stuff
 ***********************************************/
    template <int N>
    struct array
    {
    public:
        //
        // Construct
        //

        // No constructors or destructors needed here

        //
        // Assign
        //

        // No assignment operators needed here

        //
        // Iterator
        //

        // Forward declaration for the iterator class
        class iterator;

        // Begin and end methods
        iterator begin() { return iterator(__elems_); }
        iterator end()   { return iterator(__elems_ + size()); }

        //
        // Access
        //

        // Subscript
        int& operator [] (size_t index)
        {
            /*your code goes here; it should return the i-th element in the array */
            return __elems_[index];
        }
        const int& operator [] (size_t index) const
        {
            /*your code goes here; it should return the i-th element in the array */
            return __elems_[index];
        }

        // At
        int& at(size_t index)
        {
            /*your code goes here; it should return the i-th element in the array */
            if (index < 0 || index >= N)
                throw std::out_of_range("Invalid index");
            return __elems_[index];
        }
        const int& at(size_t index) const
        {
            /*your code goes here; it should return the i-th element in the array */
            if (index < 0 || index >= N)
                throw std::out_of_range("Invalid index");
            return __elems_[index];
        }

        // Front and Back
        int& front()
        {
            /* your code goes here; it should return the first element in the array */
            return __elems_[0];
        }
        int& back()
        {
            /* your code goes here; it should return the last element in the array */
            return __elems_[size() - 1];
        }
        const int& front() const
        {
            /* your code goes here; it should return the first element in the array */
            return __elems_[0];
        }
        const int& back()  const
        {
            /* your code goes here; it should return the last element in the array */
            return __elems_[size() - 1];
        }

        //
        // Remove

        // No clear or erase here

        //
        // Status
        //

        // number of elements in the array
        size_t size()  const
        {
            /* your code goes here, this should not always return 999 */
            return N >= 0 ? N : 999;
        }
        bool empty() const
        {
            /* your code goes here; this should not always return TRUE */
            if (size() >= 1)
                return false;
            return true;
        }

        //
        // Member Variable
        //

        // statically allocated array of T
        int __elems_[N >= 0 ? N : 999];       /* your code goes here */
    };


/**************************************************
 * ARRAY ITERATOR
 * An iterator through array
 *************************************************/
    template <int N>
    class array <N> :: iterator
    {
        friend class ::TestArray;
    public:
        // constructors, destructors, and assignment operator
        iterator() : p(nullptr) {}

        iterator(int * p) { this->p = p; }

        iterator(const iterator & rhs) { *this = rhs; }

        iterator & operator = (const iterator & rhs)
        {
            /* your code goes here; it should copy an iterator */
            this->p = rhs.p;
            return *this;
        }

        // equals, not equals operator
        bool operator != (const iterator & rhs) const
        {
            /* your code goes here; it should not always return TRUE */
            return this->p != rhs.p;
        }

        bool operator == (const iterator & rhs) const
        {
            /* your code goes here; it should not always return TRUE */
            return this->p == rhs.p;
        }

        // dereference operator
        int & operator * ()
        {
            /* your code goes here; it should fetch the element referred to by p */
            return *p;
        }

        const int & operator * () const
        {
            /* your code goes here; it should fetch the element referred to by p */
            return *p;
        }

        // prefix increment
        iterator & operator ++ ()
        {
            /* your code goes here; it should advance the iterator by one */
            p++;
            return *this;
        }

        // postfix increment
        iterator operator ++ (int postfix)
        {
            /* your code goes here; it should advance the iterator by one */
            iterator temp = *this;
            p++;
            return temp;
        }

    private:
        int * p;
    };



}; // namespace custom
