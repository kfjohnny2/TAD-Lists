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
    T* data();

    class iterator;
    class const_iterator;

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

 private:
    size_type m_size = 0;         //!< The Vector size
    size_type m_capacity = 1;     //!< The Vector capacity
    std::unique_ptr<T[]> m_list;  //!< The Vector list
};

template <typename T>
class Vector<T>::const_iterator{
public:
    const_iterator(){}

    const T &operator*() const{
        return *m_ptr;
    }

    const_iterator &operator++() const{
        m_ptr++;
        return (*this);
    }

    const_iterator operator++(int) const{
        const_iterator cpy(m_ptr);
        m_ptr++;
        return cpy;
    }

    const_iterator &operator--() const{
        m_ptr--;
        return (*this);
    }

    const_iterator operator--(int) const{
        const_iterator cpy(m_ptr);
        m_ptr--;
        return cpy;
    }

    bool operator==(const const_iterator &_rhs) const {
        return (m_ptr == _rhs.m_ptr);
    }


    bool operator!=(const const_iterator &_rhs) const {
        return !(*this == _rhs);
    }
protected:
    const_iterator(T *_p) : m_ptr(_p) {}
    T *m_ptr;
    friend class Vector<T>;
};


template <typename T>
class Vector<T>::iterator : public Vector<T>::const_iterator {
public:
    iterator() : const_iterator(){}

    const T &operator*() const {
        return *(const_iterator::m_ptr);
    }

    T &operator*() {
        return *(const_iterator::m_ptr);
    }

    iterator &operator++() const{
        const_iterator::m_ptr++;
        return (*this);
    }

    iterator operator++(int) {
        iterator cpy(const_iterator::m_ptr);
        const_iterator::m_ptr++;
        return cpy;
    }

    iterator  &operator--() const{
        const_iterator::m_ptr--;
        return (*this);
    }

    iterator operator--(int) {
        const_iterator cpy(const_iterator::m_ptr);
        const_iterator::m_ptr--;
        return cpy;
    }

protected:

    iterator(T *_p) : const_iterator(_p) {}
    friend class Vector<T>;

};

#include "vector.inl"

#endif