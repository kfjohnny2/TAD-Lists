#ifndef _VECTOR_H_
#define _VECTOR_H_


#include <memory>

typedef size_t size_type;

template <typename T>
class Vector{
public:

    explicit Vector(size_type _sz = 1);

    ~Vector() {}

    size_type size() const; // return the number of elements in the container.
    void clear(); //remove (either logically or physically) all elements from the container.
    bool empty(); //returns true if the container contains no elements, and false otherwise.
    void push_back( const T & x ); // adds x to the end of the list.
    void pop_back(); // removes the object at the end of the list.
    const T & back() const; //returns the object at the end of the list.
    const T & front() const; //returns the object at the beginning of the list.
    void assign( const T & x ); //replaces the content of the list with copies of value x .
    T & operator[]( size_type idx);
    size_type capacity() const;
    T & at ( size_type idx );
    void doubleCapacity(size_type newCapacity);
    size_type length() const;
    void printVector() const;
 private:
    size_type m_size = 0;         //!< The Vector size
    size_type m_capacity = 1;     //!< The Vector capacity
    std::unique_ptr<T[]> m_list;  //!< The Vector list
};

#include "vector.inl"

#endif