#include <memory>
#include <iostream>
#include "vector.hpp"

template <typename T>
Vector<T>::Vector(size_type _sz): m_capacity(_sz), m_list(new T[_sz]) {}

template <typename T>
void Vector<T>::clear(){
    while(m_size > 0){
        (&m_list[m_size--])->~T();
    }
}

template <typename T>
bool Vector<T>::empty(){
    return m_size == 0 ? true : false;
}

template <typename T>
void Vector<T>::push_back(const T & x){
    if(m_size >= m_capacity){
        doubleCapacity(m_capacity);
    }

    m_list[m_size++] = x;
}

template <typename T>
void Vector<T>::pop_back(){
    if(m_size > 0){
        (&m_list[m_size--])->~T();
    }
}

template <typename T>
const T & Vector<T>::back() const{
    return m_list[m_size-1];
}

template <typename T>
const T & Vector<T>::front() const{
    return m_list[0];
}

template <typename T>
void Vector<T>::assign( const T & x){
    for(auto i(0u); i < m_size; i++){
        m_list[i] = x;
    }
}

template <typename T>
void Vector<T>::doubleCapacity(size_type actCapacity){
    actCapacity == 0 ? actCapacity = 1 : actCapacity *= 2;
    std::unique_ptr<T[]> cpy_list(new T[actCapacity]);

    for (auto i(0u); i < m_size; i++) {
        cpy_list[i] = m_list[i];
        (&m_list[i])->~T();
    }
    m_list = std::move(cpy_list);
    m_capacity = actCapacity;
}

template <typename T>
T & Vector<T>::operator[](size_type idx){
    return m_list[idx];
}

template <typename T>
T & Vector<T>::at ( size_type idx ){
    if( idx >= m_size || idx < 0)
        throw std::out_of_range("Array Index Out of Bounds!");
    return m_list[idx];
}

template <typename T>
size_type Vector<T>::capacity() const{
    return m_capacity;
}

template <typename T>
size_type Vector<T>::length() const{
    return m_size;
}

template <typename T>
void Vector<T>::printVector() const{
    std::cout << "[ ";
    for(auto i(0u); i < m_size; i++){
        std::cout << m_list[i] << " ";
    }
    std::cout << "]" << std::endl;
}
