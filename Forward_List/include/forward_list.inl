
#include "forward_list.hpp"

typedef size_t size_type;

template <typename T>
Forward_list<T>::Forward_list(){
    m_head = new Node;
    m_tail = new Node;
    m_size = 0;
    m_head->next = m_tail;
}

template <typename T>
Forward_list<T>::Forward_list(const Forward_list<T> &fList) {
    m_head = new Node;
    m_tail = new Node;
    m_head->next = m_tail;
    m_size = 0;
    for (auto it = fList.begin(); it != fList.end(); it++)
        push_back(*it);
}

template <typename T>
Forward_list<T>::Forward_list(Forward_list<T> && fList) {
    m_head = new Node;
    m_tail = fList.m_tail;
    m_head->next = fList.m_head->next;
    m_size = fList.m_size;
    fList.m_tail = new Node;
    fList.m_head->next = fList.m_tail;
    fList.m_size = 0;
}

// Destructor
template <typename T>
Forward_list<T>::~Forward_list() {
    clear();
    delete m_head;
    delete m_tail;
}

template <typename T>
size_type Forward_list<T>::size() const {
    return m_size;
}

template <typename T>
bool Forward_list<T>::empty() const {
    return m_size == 0;
}

template <typename T>
void Forward_list<T>::clear() {
    Node *cp1 = m_head->next;
    while (cp1 != m_tail) {
        Node *cp2 = cp1;
        cp1 = cp1->next;
        delete cp2;
    }
    m_size = 0;
    m_head->next = m_tail;
}

template <typename T>
const T &Forward_list<T>::front() const{
    return m_head->next->data;
}

template <typename T>
const T & Forward_list<T>::back() const{
    Node *work = m_head;
    while (work->next != m_tail)
        work = work->next;
    return work->data;
}

template <typename T>
void Forward_list<T>::push_front(const T & x) {
    Node *_new = new Node( x, m_head->next);
    m_head->next = _new;
    m_size++;
}


template <typename T>
void Forward_list<T>::pop_front() {
    if (m_size > 0) {
        Node *work = m_head->next;
        m_head->next = work->next;
        m_size--;
        delete work;
    }
}

//Search the last element and creates another in next to it and adds 1 to the size of the list
template <typename T>
void Forward_list<T>::push_back( const T & x ){
    Node *work = m_head;
    while (work->next != m_tail)
        work = work->next;
    Node *_new = new Node(x, work->next);
    work->next = _new;
    m_size++;
}

template <typename T>
void Forward_list<T>::pop_back() {
    if (m_size > 0) {
        Node *work = m_head;
        while (work->next->next != m_tail)
            work = work->next;
        Node *work1 = work->next;
        work->next = work1->next;
        m_size--;
        delete work1;
    }
}

template <typename T>
void Forward_list<T>::assign(const T &val) {
    Node *work = m_head;
    while (work->next != m_tail) {
        work = work->next;
        work->data = val;
    }
}

template <typename T>
void Forward_list<T>::assign(std::initializer_list<T> il){
    clear();
    for (auto i = il.begin(); i != il.end(); i++)
        push_back(*i);
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::begin() {
    return typename Forward_list<T>::iterator(m_head->next);
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::before_begin() {
    return typename Forward_list<T>::iterator(m_head);
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::end() {
    return typename Forward_list<T>::iterator(m_tail);
}

template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::begin() const {
    return typename Forward_list<T>::const_iterator(m_head->next);
}

template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::before_begin() const {
    return typename Forward_list<T>::const_iterator(m_head);
}

template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::end() const {
    return typename Forward_list<T>::const_iterator(m_tail);
}