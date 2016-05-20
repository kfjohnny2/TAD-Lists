
#include "list.hpp"

typedef size_t size_type;

template <typename T>
List<T>::List(){
    m_head = new Node;
    m_tail = new Node;
    m_size = 0;
    m_head->next = m_tail;
    m_tail->prev = m_head;
}

template <typename T>
List<T>::List(const List<T> &dList) {
    m_head = new Node;
    m_tail = new Node;
    m_head->next = m_tail;
    m_tail->prev = m_head;
    m_size = 0;
    for (auto it = dList.begin(); it != dList.end(); it++)
        push_back(*it);
}

template <typename T>
List<T>::List(List<T> && dList) {
    m_head = new Node;
    m_tail = dList.m_tail;
    m_head->next = dList.m_head->next;
    m_size = dList.m_size;
    dList.m_tail = new Node;
    dList.m_head->next = dList.m_tail;
    dList.m_tail->prev = dList.m_head;
    dList.m_size = 0;
}

// Destructor
template <typename T>
List<T>::~List() {
    clear();
    delete m_head;
    delete m_tail;
}

template <typename T>
size_type List<T>::size() const {
    return m_size;
}

template <typename T>
bool List<T>::empty() const {
    return m_size == 0;
}

template <typename T>
void List<T>::clear() {
    Node *cp1 = m_head->next;
    while (cp1 != m_tail) {
        Node *cp2 = cp1;
        cp1 = cp1->next;
        delete cp2;
    }
    m_size = 0;
    m_head->next = m_tail;
    m_tail->prev = m_head;
}

template <typename T>
const T &List<T>::front() const{
    return m_head->next->data;
}

template <typename T>
const T & List<T>::back() const{
    return m_tail->prev->data;
}

template <typename T>
void List<T>::push_front(const T & x) {
    Node *_new = new Node(x, m_head->next, m_head);
    m_head->next->prev = _new;
    m_head->next = _new;
    m_size++;
}


template <typename T>
void List<T>::pop_front() {
    if (m_size > 0) {
        Node *work = m_head->next;
        work->next->prev = m_head;
        m_head->next = work->next;
        m_size--;
        delete work;
    }
}

//Insert on prev node
template <typename T>
void List<T>::push_back( const T & x ){
    Node *_new = new Node( x, m_tail, m_tail->prev);
    m_tail->prev->next = _new;
    m_tail->prev = _new;
    m_size++;
}

template <typename T>
void List<T>::pop_back() {
    if (m_size > 0) {
        Node *work = m_tail->prev;
        work->prev->next = m_tail;
        m_tail->prev = work->prev;
        m_size--;
        delete work;
    }
}

template <typename T>
void List<T>::assign(const T &val) {
    Node *work = m_head;
    while (work->next != m_tail) {
        work = work->next;
        work->data = val;
    }
}

template <typename T>
void List<T>::assign(std::initializer_list<T> il){
    clear();
    for (auto i = il.begin(); i != il.end(); i++)
        push_back(*i);
}

template <typename T>
typename List<T>::iterator List<T>::begin() {
    return typename List<T>::iterator(m_head->next);
}

template <typename T>
typename List<T>::iterator List<T>::before_begin() {
    return typename List<T>::iterator(m_head);
}

template <typename T>
typename List<T>::iterator List<T>::end() {
    return typename List<T>::iterator(m_tail);
}

template <typename T>
typename List<T>::const_iterator List<T>::begin() const {
    return typename List<T>::const_iterator(m_head->next);
}

template <typename T>
typename List<T>::const_iterator List<T>::before_begin() const {
    return typename List<T>::const_iterator(m_head);
}

template <typename T>
typename List<T>::const_iterator List<T>::end() const {
    return typename List<T>::const_iterator(m_tail);
}