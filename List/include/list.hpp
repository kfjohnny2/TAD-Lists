#ifndef _LIST_H_
#define _LIST_H_

#include <memory>

typedef size_t size_type;

template <typename T>
class List{

public:
    List();

    explicit List(const List & fList);

    explicit List(List && fList);

    ~List();

    size_type size() const; // return the number of elements in the container.
    void clear(); //remove (either logically or physically) all elements from the container.
    bool empty() const; //returns true if the container contains no elements, and false otherwise.
    void push_back( const T & x ); // adds x to the end of the list.
    void pop_back(); // removes the object at the end of the list.
    const T & back() const; //returns the object at the end of the list.
    const T & front() const; //returns the object at the beginning of the list.
    void push_front( const T & x );
    void pop_front( );
    void assign( const T & x ); //replaces the content of the list with copies of value x .
    void assign(std::initializer_list<T> _il);
    class const_iterator;

    class iterator;

    iterator begin();

    iterator before_begin();

    iterator end();

    const_iterator begin() const;

    const_iterator before_begin() const;

    const_iterator end() const;
private:
    struct Node {
        T data;
        Node *next;
        Node *prev;  //!< Pointer to the previous node in the list added to every method.
        Node(const T &_d = T(), Node *_nxt = nullptr, Node *_prv = nullptr)
            : data(_d), next(_nxt), prev(_prv) {}
    };
    Node *m_head;
    Node *m_tail;
    size_type m_size;
};

template <typename T>
class List<T>::const_iterator {
 public:
     /**
     * @brief constructor for the constant iterator
     */
    const_iterator() {}

    /**
     * @brief Overload pointer operator (*)
     * @details actual node data
     */
    const T &operator*() const {
        return m_node->data;
    }

    /**
     * @brief Overload increment (++) without parameter
     * @details incremented iterator
     */
    const_iterator &operator++() {
        m_node = m_node->next;
        return (*this);
    }

    /**
     * @brief Overload increment (++) without parameter
     * @details incremented iterator with the integer
     */
    const_iterator operator++(int) {
        const_iterator cpy(m_node);
        m_node = m_node->next;
        return cpy;
    }

    const_iterator &operator--() {
        m_node = m_node->prev;
        return (*this);
    }

    const_iterator operator--(int) {
        const_iterator cpy(m_node);
        m_node = m_node->prev;
        return cpy;
    }

    /**
     * @brief Overload equals (==) to check the equality of the nodes
     */
    bool operator==(const const_iterator &_rhs) const {
        return (m_node == _rhs.m_node);
    }

    /**
     * @brief Overload not-equal (!=) to check the equality of the nodes
     */
    bool operator!=(const const_iterator &_rhs) const {
        return !(*this == _rhs);
    }

 protected:
    const_iterator(Node *_p) : m_node(_p) {}
    Node *m_node;
    friend class List<T>; //!< Make this class a friend of ForwardList, to use the members of it.
};

template <typename T>
class List<T>::iterator : public List<T>::const_iterator {
 public:
    /**
     * @brief constructor for the iterator
     */
    iterator() : const_iterator() {}

    /**
     * @brief Overloads for the * operator. Const
     * @return value of the node
     */
    const T &operator*() const {
        return const_iterator::m_node->data;
    }

    /**
     * @brief Overloads for the * operator
     * @return value of the node
     */
    T &operator*() {
        return const_iterator::m_node->data;
    }

    /**
     * @brief Overloads increment operator (++)
     * @return Iterator after change
     */
    iterator &operator++() {
        const_iterator::m_node = const_iterator::m_node->next;
        return (*this);
    }

    /**
     * @brief Overloads increment operator receiving an integer
     * @return The actual iterator
     */
    iterator operator++(int) {
        iterator cpy(const_iterator::m_node);
        const_iterator::m_node = const_iterator::m_node->next;
        return cpy;
    }

    /**
     * @brief Overloads decrement operator
     * @return The actual iterator
     */
    iterator &operator--() {
        const_iterator::m_node = const_iterator::m_node->prev;
        return (*this);
    }

    /**
     * @brief Overloads increment operator receiving an integer
     * @return The actual iterator decrement the given value
     */
    iterator operator--(int) {
        const_iterator cpy(const_iterator::m_node);
        const_iterator::m_node = const_iterator::m_node->prev;
        return cpy;
    }

 protected:
    iterator(Node *_p) : const_iterator(_p) {}
    friend class List<T>;  //!< Make this class a friend of ForwardList, to use the members of it.
};

#include "list.inl"

#endif