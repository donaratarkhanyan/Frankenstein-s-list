#include <iostream>
#include "frank.h"

template <typename T>
FrankList<T>::Node::Node()
    : val {0}
    , next {nullptr}
    , prev {nullptr}
    , asc {nullptr}
    , desc {nullptr}
{}

template <typename T>
FrankList<T>::Node::Node(T val)
    : val {val}
    , next {nullptr}
    , prev {nullptr}
    , asc {nullptr}
    , desc {nullptr}
{}

///base_iterator///
template <typename T>
FrankList<T>::base_iterator::~base_iterator()
{
    ptr = nullptr;
}

template <typename T>
bool FrankList<T>::base_iterator::operator== (const base_iterator& rhv) const
{ 
    return ptr == rhv.ptr;
}

template <typename T>
bool FrankList<T>::base_iterator::operator!= (const base_iterator& rhv) const
{
    return ptr != rhv.ptr;
}

template <typename T>
FrankList<T>::base_iterator::base_iterator(Node* ptr)
    : ptr {ptr}
{}

///const_iterator///
template <typename T>
FrankList<T>::const_iterator::const_iterator (const base_iterator& rhv)
    : base_iterator(rhv)
{}

template <typename T>
FrankList<T>::const_iterator::const_iterator (base_iterator&& rhv)
    : base_iterator(rhv)
{
    rhv.ptr = nullptr;
}
    
template <typename T>
const FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}


template <typename T>
FrankList<T>::const_reference FrankList<T>::const_iterator::operator* () const
{ 
    return this -> ptr -> val;
}

template <typename T>
FrankList<T>::const_pointer FrankList<T>::const_iterator::operator-> () const
{
    return &(this -> ptr -> val);
}

template <typename T>
const FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator++() 
{
    this -> ptr = this -> ptr -> next;
    return *this;
}

template <typename T>
const FrankList<T>::const_iterator FrankList<T>::const_iterator::operator++(value_type)
{
    const_iterator tmp = *this; 
    ++(*this);
    return tmp;
}

template <typename T>
const FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator--()
{
    this -> ptr = this -> ptr -> prev;
    return *this;
}

template <typename T>
const FrankList<T>::const_iterator FrankList<T>::const_iterator::operator--(value_type)
{
    const_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
FrankList<T>::const_iterator::const_iterator (Node* ptr)
    : base_iterator(ptr)
{}

///iterator///
template <typename T>
FrankList<T>::iterator::iterator(const base_iterator& rhv)
    : const_iterator (rhv)
{}

template <typename T>
FrankList<T>::iterator::iterator(base_iterator&& rhv)
    : const_iterator (rhv)
{
    rhv.ptr = nullptr;
}

template <typename T>
FrankList<T>::reference FrankList<T>::iterator::operator* ()
{
    return this -> ptr -> val;
}

template <typename T>
FrankList<T>::pointer FrankList<T>::iterator::operator-> ()
{
    return &(this -> ptr -> val);
}


template <typename T>
const FrankList<T>::iterator& FrankList<T>::iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::iterator& FrankList<T>::iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}


template <typename T>
FrankList<T>::iterator::iterator (Node* ptr)
    : const_iterator(ptr)
{}

///const_reverse_iterator///

template <typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator (const base_iterator& rhv)
    : base_iterator(rhv)
{}

template <typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator (base_iterator&& rhv)
    : base_iterator(rhv)
{
    rhv.ptr = nullptr;
}


template <typename T>
const FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}


template <typename T>
FrankList<T>::const_reference FrankList<T>::const_reverse_iterator::operator* () const
{
    return this -> ptr -> val;
}

template <typename T>
FrankList<T>::const_pointer FrankList<T>::const_reverse_iterator::operator-> () const
{
    return &(this -> ptr -> val);
}

template <typename T>
const FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator++()
{

    this -> ptr = this -> ptr -> prev;
    return *this;
}

template <typename T>
const FrankList<T>::const_reverse_iterator FrankList<T>::const_reverse_iterator::operator++(value_type)
{
    const_reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
const FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator--()
{
    this -> ptr = this -> ptr -> next;
    return *this;
}

template <typename T>
const FrankList<T>::const_reverse_iterator FrankList<T>::const_reverse_iterator::operator--(value_type)
{
    const_reverse_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator (Node* ptr)
    : const_reverse_iterator(ptr)
{}

///reverse_iterator///
template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator(const base_iterator& rhv)
    : const_reverse_iterator (rhv)
{}

template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator(base_iterator&& rhv)
    : const_reverse_iterator (rhv)
{
    rhv.ptr = nullptr;  
}

template <typename T>
FrankList<T>::reference FrankList<T>::reverse_iterator::operator* ()
{
    return this -> ptr -> val;
}

template <typename T>
FrankList<T>::pointer FrankList<T>::reverse_iterator::operator-> ()
{
    return &(this -> ptr -> val);
}


template <typename T>
const FrankList<T>::reverse_iterator& FrankList<T>::reverse_iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::reverse_iterator& FrankList<T>::reverse_iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}


template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator (Node* ptr)
    : const_reverse_iterator(ptr)
{}

///const_asc_iterator///
template <typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(const base_iterator& rhv)
    :base_iterator(rhv)
{}

template <typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(base_iterator&& rhv)
    :base_iterator(rhv)
{
    rhv.ptr = nullptr;
}


template <typename T>
const FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}


template <typename T>
FrankList<T>::const_reference FrankList<T>::const_asc_iterator::operator*() const {

    return this -> ptr -> val;
}

template <typename T> 
FrankList<T>::const_pointer FrankList<T>::const_asc_iterator::operator->() const
{

    return &(this-> ptr -> val);
}

template <typename T>
const FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator++()
{

    this -> ptr = this -> ptr -> asc;
    return *this;
}

template <typename T>
const FrankList<T>::const_asc_iterator FrankList<T>::const_asc_iterator::operator++(value_type)
{
    const_asc_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
const FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator--()
{
    this -> ptr = this -> ptr -> dasc;
    return *this;
}


template <typename T>
const FrankList<T>::const_asc_iterator FrankList<T>::const_asc_iterator::operator--(value_type)
{
    const_asc_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(Node* ptr)
    :base_iterator(ptr)
{}

///asc_iterator///
template <typename T>
FrankList<T>::asc_iterator::asc_iterator(const base_iterator& rhv)
    :const_asc_iterator(rhv)
{}

template <typename T>
FrankList<T>::asc_iterator::asc_iterator(base_iterator&& rhv)
    :const_asc_iterator(rhv)
{
    rhv.ptr = nullptr;
}

template <typename T>
FrankList<T>::reference FrankList<T>::asc_iterator::operator* ()
{
    return this -> ptr-> val;
}

template <typename T>
FrankList<T>::pointer FrankList<T>::asc_iterator::operator-> ()
{
    return &(this-> ptr -> val);
}


template <typename T>
const FrankList<T>::asc_iterator& FrankList<T>::asc_iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::asc_iterator& FrankList<T>::asc_iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}


template <typename T>
FrankList<T>::asc_iterator::asc_iterator(Node* ptr)
    :const_asc_iterator(ptr)
{}

///const_desc_iterator///
template <typename T>
FrankList<T>::const_desc_iterator::const_desc_iterator(const base_iterator& rhv)
    :base_iterator(rhv)
{}

template <typename T>
FrankList<T>::const_desc_iterator::const_desc_iterator(base_iterator&& rhv)
    :base_iterator(rhv)
{
    rhv.ptr = nullptr;
}


template <typename T>
const FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}


template <typename T>
FrankList<T>::const_reference FrankList<T>::const_desc_iterator::operator*() const 
{
    return this -> ptr -> val;
}

template <typename T>
FrankList<T>::const_pointer FrankList<T>::const_desc_iterator::operator->() const
{
    return &(this -> ptr -> val);
}


template <typename T>
const FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator++()
{
    this -> ptr = this -> ptr -> dasc;
    return *this;
}

template <typename T>
const FrankList<T>::const_desc_iterator FrankList<T>::const_desc_iterator::operator++(value_type)
{
    const_desc_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
const FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator--()
{
    this -> ptr = this -> ptr -> asc;
    return *this;
}

template <typename T>
const FrankList<T>::const_desc_iterator FrankList<T>::const_desc_iterator::operator--(value_type)
{
    const_desc_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
FrankList<T>::const_desc_iterator::const_desc_iterator(Node* ptr)
    :base_iterator(ptr)
{}

////desc_iterator///
template <typename T>
FrankList<T>::desc_iterator::desc_iterator(const base_iterator& rhv)
    :const_desc_iterator(rhv)
{}

template <typename T>
FrankList<T>::desc_iterator::desc_iterator(base_iterator&& rhv)
    :const_desc_iterator(rhv)
{
    rhv.ptr = nullptr;
}


template <typename T>
FrankList<T>::reference FrankList<T>::desc_iterator::operator*()
{
    return this -> ptr -> val;
}

template <typename T>
FrankList<T>::pointer FrankList<T>::desc_iterator::operator->()
{
    return &(this -> ptr -> val);
}


template <typename T>
const FrankList<T>::desc_iterator& FrankList<T>::desc_iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::desc_iterator& FrankList<T>::desc_iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}


template <typename T>
FrankList<T>::desc_iterator::desc_iterator(Node* ptr)
    :const_desc_iterator(ptr)
{}


///const_multi_iterator///
template <typename T>
FrankList<T>::const_multi_iterator::const_multi_iterator(const base_iterator& rhv)
    : base_iterator (rhv)
{}

template <typename T>
FrankList<T>::const_multi_iterator::const_multi_iterator(base_iterator&& rhv)
    : base_iterator (rhv)
{
    rhv.ptr = nullptr;
}

template <typename T>
FrankList<T>::const_reference FrankList<T>::const_multi_iterator::operator* () const
{
    return this -> ptr -> val;
}

template <typename T>
FrankList<T>::const_pointer FrankList<T>::const_multi_iterator::operator-> () const
{
    return &(this -> ptr -> val);
}


template <typename T>
const FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}

template <typename T>
const FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator++()
{
    if(mode) {
        this -> ptr = this -> ptr -> asc;
    } else {
        this -> ptr = this -> ptr -> next;
    }
    return *this;
}

template <typename T>
const FrankList<T>::const_multi_iterator FrankList<T>::const_multi_iterator::operator++(value_type)
{
    const_multi_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
const FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator--()
{
    if(mode) {
        this -> ptr = this -> ptr -> desc;
    } else {
        this -> ptr = this -> ptr -> prev;
    }
    return *this;
}

template <typename T>
const FrankList<T>::const_multi_iterator FrankList<T>::const_multi_iterator::operator--(value_type)
{
    const_multi_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
FrankList<T>:: const_multi_iterator::const_multi_iterator(Node* ptr)
    : base_iterator(ptr)
{}

template <typename T>
void FrankList<T>::const_multi_iterator::chmod()
{
    mode = !mode;
}


///multi_iterator///
template <typename T>
FrankList<T>::multi_iterator::multi_iterator(const base_iterator& rhv)
    : const_multi_iterator (rhv)
{}

template <typename T>
FrankList<T>::multi_iterator::multi_iterator(base_iterator&& rhv)
    : const_multi_iterator (rhv)
{
    rhv.ptr = nullptr;
}

template <typename T>
FrankList<T>::reference FrankList<T>::multi_iterator::operator* ()
{
    return this -> ptr -> val;
}

template <typename T>
FrankList<T>::pointer FrankList<T>::multi_iterator::operator-> ()
{
    return &(this -> ptr -> val);
}


template <typename T>
const FrankList<T>::multi_iterator& FrankList<T>::multi_iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::multi_iterator& FrankList<T>::multi_iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}

template <typename T>
FrankList<T>::multi_iterator::multi_iterator (Node* ptr)
    : const_multi_iterator(ptr)
{}

///const_multi_reverse_iterator///
template <typename T>
FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(const base_iterator& rhv)
    : base_iterator (rhv)
{}

template <typename T>
FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(base_iterator&& rhv)
    : base_iterator (rhv)
{
    rhv.ptr = nullptr;
}

template <typename T>
FrankList<T>::const_reference FrankList<T>::const_multi_reverse_iterator::operator* () const
{
    return this -> ptr -> val;
}

template <typename T>
FrankList<T>::const_pointer FrankList<T>::const_multi_reverse_iterator::operator-> () const
{
    return &(this -> ptr -> val);
}


template <typename T>
const FrankList<T>::const_multi_reverse_iterator& FrankList<T>::const_multi_reverse_iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::const_multi_reverse_iterator& FrankList<T>::const_multi_reverse_iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}

template <typename T>
const FrankList<T>::const_multi_reverse_iterator& FrankList<T>::const_multi_reverse_iterator::operator++()
{
    if(mode) {
        this -> ptr = this -> ptr -> desc;
    } else {
        this -> ptr = this -> ptr -> prev;
    }
    return *this;
}

template <typename T>
const FrankList<T>::const_multi_reverse_iterator FrankList<T>::const_multi_reverse_iterator::operator++(value_type)
{
    const_multi_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
const FrankList<T>::const_multi_reverse_iterator& FrankList<T>::const_multi_reverse_iterator::operator--()
{
    if(mode) {
        this -> ptr = this -> ptr -> asc;
    } else {
        this -> ptr = this -> ptr -> next;
    }
    return *this;
}

template <typename T>
const FrankList<T>::const_multi_reverse_iterator FrankList<T>::const_multi_reverse_iterator::operator--(value_type)
{
    const_multi_iterator tmp = *this;
    ++(*this);
    return tmp;
}


template <typename T>
FrankList<T>:: const_multi_reverse_iterator::const_multi_reverse_iterator(Node* ptr)
    : base_iterator(ptr)
{}

template <typename T>
void FrankList<T>::const_multi_reverse_iterator::chmod()
{   
    mode = !mode;
}

///multi_reverse_iterator///
template <typename T>
FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(const base_iterator& rhv)
    : const_multi_reverse_iterator (rhv)
{}

template <typename T>
FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(base_iterator&& rhv)
    : const_multi_reverse_iterator (rhv)
{
    rhv.ptr = nullptr;
}

template <typename T>
FrankList<T>::reference FrankList<T>::multi_reverse_iterator::operator* ()
{
    return this -> ptr -> val;
}

template <typename T>
FrankList<T>::pointer FrankList<T>::multi_reverse_iterator::operator-> ()
{
    return &(this -> ptr -> val);
}


template <typename T>
const FrankList<T>::multi_reverse_iterator& FrankList<T>::multi_reverse_iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::multi_reverse_iterator& FrankList<T>::multi_reverse_iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}

template <typename T>
FrankList<T>::multi_reverse_iterator::multi_reverse_iterator (Node* ptr)
    : const_multi_reverse_iterator(ptr)
{}


//FRANK_LIST///
template <typename T>
FrankList<T>::FrankList()
    : head {nullptr}
    , tail {nullptr}
    , ahead {nullptr}
    , atail {nullptr}
{}

template <typename T>
FrankList<T>::FrankList(size_type size) : FrankList ()
{
    for(size_type i = 0; i < size; ++i){
        this -> push_back (0);
    }
}

template<typename T>
FrankList<T>::FrankList(size_type size, const_reference init) : FrankList ()
{
    for (size_type i = 0; i < size; ++i) {
        this -> push_back (init);
    }
}

template <typename T>
FrankList<T>::FrankList(const FrankList<value_type>& rhv) : FrankList ()
{
    
    Node* ptr = rhv.head;
    Node* thisNode = nullptr;
    while (ptr) {
        Node* newNode = new Node (ptr -> val);
        if(thisNode == nullptr) {
            head = nullptr;
            ahead = newNode;
            atail = newNode;
        }
        else {
            thisNode -> next = newNode;
            newNode -> prev = thisNode;
        }
        ptr = ptr -> next;
        thisNode = newNode;
        put_in_sorted_order (newNode);
    }
    tail = thisNode;
}

template <typename T>
FrankList<T>::FrankList (FrankList<value_type>&& rhv)
    : head {rhv.head}
    , tail {rhv.tail}
    , ahead {rhv.ahead}
    , atail {rhv.atail}
{
    rhv.head = nullptr;
    rhv.tail = nullptr;
    rhv.ahead = nullptr;
    rhv.atail = nullptr;
}


template<typename T>
FrankList<T>::FrankList(std::initializer_list<value_type> init) 
        : head(nullptr)
        , tail(nullptr)
        , ahead(nullptr)
        , atail(nullptr) 
{
    for (const auto& val : init) {
        push_back(val);
    }
}

template <typename T> 
template <typename input_iterator>
FrankList<T>::FrankList(input_iterator f, input_iterator l)
    : FrankList()
{
    for (auto it = f; it != l; ++it) {
        push_back(*it); 
    }
}

template<typename T>
FrankList<T>::~FrankList()
{
    clear();
}

template <typename T>
void FrankList<T>::swap(FrankList<value_type>& rhv)
{
    std::swap(head, rhv.head);
    std::swap(tail, rhv.tail);
    std::swap(ahead, rhv.ahead);
    std::swap(atail, rhv.atail);
}

template <typename T>
FrankList<T>::size_type FrankList<T>::size() const
{
    if (!head){
        return 0;
    }
    size_type size = 0;
    Node* current = head;
    while(current != nullptr){
        current = current -> next;
        ++size;
    }
    return size;
}

template <typename T>
bool FrankList<T>::empty() const
{
    if (head){
        return false;
    }
    return true;
}

template <typename T>
void FrankList<T>::display() const
{
    Node* current = ahead;
    while(current){
        std::cout << current -> val << " ";
        current = current -> asc;
    }
    std::cout << std::endl;
}

template <typename T>
void FrankList<T>::resize(size_type s, const_reference init)
{
    for(size_type i = 0; i < s; ++i){
        push_back(init);
    }
}

template <typename T>
void FrankList<T>::clear() noexcept 
{
    while (head != nullptr) {
        Node* tmp = head;
        head = head -> next;
        delete tmp;
    }
    tail = nullptr;
    ahead = nullptr;
    atail = nullptr;
}

template <typename T>
void FrankList<T>::push_front(const_reference elem)
{
    if(head == nullptr) {
        head = new Node(elem);
        tail = head;
        ahead = head;
        atail = head;
    } else {
        Node* tmp = new Node(elem);
        head -> prev = tmp;
        tmp -> next = head;
        head = tmp;
        put_in_sorted_order(tmp);
    }

}

template <typename T>
void FrankList<T>::pop_front()
{
    remove_in_sorted_order(head);
    head = head -> next;        
    delete head -> prev;
    head -> prev = nullptr; 
}

template <typename T>
void FrankList<T>::push_back(const_reference elem)
{
    if(head == nullptr) {
        head = new Node(elem);
        tail = head;
        ahead = head;
        atail = head;
    } else {
        Node* tmp = new Node(elem);
        tmp -> prev = tail;
        tail -> next = tmp;
        tail = tmp;
        put_in_sorted_order(tmp);
    }
    
}

template <typename T>
void FrankList<T>::pop_back()
{
    remove_in_sorted_order(tail);
    tail = tail -> prev;
    delete tail -> next;
    tail -> next = nullptr;
}

template <typename T>
FrankList<T>::const_reference FrankList<T>::front() const {
    if (head == nullptr) {
        throw std::runtime_error("Empty list.");
    }
    return head->val;
}

template <typename T>
FrankList<T>::reference FrankList<T>::front() {
    if (head == nullptr) {
        throw std::runtime_error("Empty list.");
    }
    return head->val;
}

template <typename T>
FrankList<T>::const_reference FrankList<T>::back() const {
    if (tail == nullptr) {
        throw std::runtime_error("Empty list.");
    }
    return tail->val;
}

template <typename T>
FrankList<T>::reference FrankList<T>::back() {
    if (tail == nullptr) {
        throw std::runtime_error("Empty list.");
    }
    return tail->val;
}

template <typename T>
FrankList<T>::const_reference FrankList<T>::min() const {
    if (ahead == nullptr) {
        throw std::runtime_error("Empty list.");
    }
    return ahead->val;
}

template <typename T>
FrankList<T>::reference FrankList<T>::min() {
    if (ahead == nullptr) {
        throw std::runtime_error("Empty list.");
    }
    return ahead->val;
}

template <typename T>
FrankList<T>::const_reference FrankList<T>::max() const {
    if (atail == nullptr) {
        throw std::runtime_error("Empty list.");
    }
    return atail->val;
}

template <typename T>
FrankList<T>::reference FrankList<T>::max() {
    if (atail == nullptr) {
        throw std::runtime_error("Empty list.");
    }
    return atail->val;
}

template <typename T>
const FrankList<T>& FrankList<T>::operator=(const FrankList<T>& rhv) 
{
  if (this != &rhv){
    clear();
    Node* nextNode = rhv.head;
    Node* thisNode = nullptr;
     while(nextNode){
      Node* tmp = new Node(nextNode -> val);
      if (!thisNode){
        head = tmp;
        ahead = tmp;
        atail = tmp;
      } else {
        thisNode -> next = tmp;
        tmp -> prev = thisNode;
      }
      nextNode = nextNode -> next;
      thisNode = tmp;
      put_in_sorted_ordaer(tmp);
    }
    tail = thisNode;
  }
  return *this;
}

template <typename T>
const FrankList<T>& FrankList<T>::operator=(FrankList<T>&& rhv)
{
    if (this != &rhv) {
        head = rhv.head;
        tail = rhv.tail;
        ahead = rhv.ahead;
        atail = rhv.atail;
        rhv.head = nullptr;
        rhv.tail = nullptr;
        rhv.ahead = nullptr;
        rhv.atail = nullptr;
    }
    return *this;
}

template <typename T>
const FrankList<T>& FrankList<T>::operator=(std::initializer_list<T> init)
{
    if (!empty()){
        clear();
    }
    for (const auto& val : init) {
        push_back(val); 
    }
    return *this;
}


template <typename T>
bool FrankList<T>::operator==(const FrankList<T>& rhv) const
{
    if (size() != rhv.size()) {
        return false;
    }
    Node* ptr = head;
    Node* temp = rhv.head;
    while (ptr != nullptr) {
        if (ptr -> val != temp -> val) {
            return false;
        }
        ptr = ptr -> next;
        temp = temp -> next;
    }
    return true;
}

template <typename T>
bool FrankList<T>::operator!=(const FrankList<T>& rhv) const
{
    if (size() != rhv.size()) {
        return true;
    }
    Node* ptr = head;
    Node* temp = rhv.head;
    while (ptr != nullptr) {
        if (ptr -> val != temp -> val) {
            return true;
        }
        ptr = ptr -> next;
        temp = temp -> next;
    }
    return false;
}

template <typename T>
bool FrankList<T>::operator<(const FrankList<T>& rhv) const
{
    Node* current1 = head;
    Node* current2 = rhv.head;
    while (current1 && current2) {
        if (current1->val < current2->val) {
            return true;
        } else if (current2->val < current1->val) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return (current1 == nullptr && current2 != nullptr);
}

template <typename T>
bool FrankList<T>::operator<= (const FrankList<T>& rhv) const
{
   if (*this < rhv || *this == rhv) {
       return true;
   } else {
       return false;
   }
}

template <typename T>
bool FrankList<T>::operator>(const FrankList<T>& rhv) const
{
    return rhv < *this;
}

template <typename T>
bool FrankList<T>::operator>=(const FrankList<T>& rhv) const
{
    if (*this < rhv || *this == rhv){
        return true;
    } else {
        return false;
    }
}

//------------------------------------------------------//

template <typename T>
FrankList<T>::const_iterator FrankList<T>::cbegin() const
{
    return const_iterator(head);
}

template <typename T>
FrankList<T>::const_iterator FrankList<T>::cend() const
{
    return  const_iterator(nullptr);
}

template <typename T>
FrankList<T>::const_reverse_iterator FrankList<T>::crbegin() const
{
    return const_reverse_iterator(tail);
}

template <typename T>
FrankList<T>::const_reverse_iterator FrankList<T>::crend() const
{
    return const_reverse_iterator(nullptr);
}


template <typename T>
FrankList<T>::const_asc_iterator FrankList<T>::cabegin() const
{
    return const_asc_iterator(ahead);
}

template <typename T>
FrankList<T>::const_asc_iterator FrankList<T>::caend() const
{
    return const_desc_iterator(nullptr);
}

template <typename T>
FrankList<T>::const_desc_iterator FrankList<T>::cdbegin() const
{
    return const_desc_iterator(atail);
}

template <typename T>
FrankList<T>::const_desc_iterator FrankList<T>::cdend() const
{ 
    return const_desc_iterator(nullptr);
}

template <typename T>
FrankList<T>::const_multi_iterator FrankList<T>::cmbegin() const
{ 
    return const_multi_iterator(head);
}

template <typename T>
FrankList<T>::const_multi_iterator FrankList<T>::cmend() const
{
    return const_multi_iterator(nullptr);
}

template <typename T>
FrankList<T>::const_multi_iterator FrankList<T>::cmabegin() const
{
    return const_multi_iterator(ahead);
}

template <typename T>
FrankList<T>::const_multi_iterator FrankList<T>::cmaend() const
{   
    return const_multi_iterator(nullptr);
}

template <typename T>
FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrbegin() const
{
    return const_multi_reverse_iterator(tail);
}

template <typename T>
FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrend() const
{
    return const_multi_reverse_iterator(nullptr);
}

template <typename T>
FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrdbegin() const
{
    return const_multi_reverse_iterator(atail);
}

template <typename T>
FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrdend() const
{   
    return const_multi_reverse_iterator(nullptr);
}


//------------------------------------------------------//

template <typename T>
FrankList<T>::iterator FrankList<T>::begin()
{
    return iterator(head);
}

template <typename T>
FrankList<T>::iterator FrankList<T>::end()
{
    return  iterator(nullptr);
}

template <typename T>
FrankList<T>::reverse_iterator FrankList<T>::rbegin()
{
    return reverse_iterator(tail);
}

template <typename T>
FrankList<T>::reverse_iterator FrankList<T>::rend()
{
    return reverse_iterator(nullptr);
}


template <typename T>
FrankList<T>::asc_iterator FrankList<T>::abegin()
{
    return asc_iterator(ahead);
}

template <typename T>
FrankList<T>::asc_iterator FrankList<T>::aend()
{
    return asc_iterator(nullptr);
}

template <typename T>
FrankList<T>::desc_iterator FrankList<T>::dbegin()
{
    return desc_iterator(atail);
}

template <typename T>
FrankList<T>::desc_iterator FrankList<T>::dend()
{
    return desc_iterator(nullptr);
}

template <typename T>
FrankList<T>::multi_iterator FrankList<T>::mbegin()
{
    return multi_iterator(head);
}

template <typename T>
FrankList<T>::multi_iterator FrankList<T>::mend()
{
    return multi_iterator(nullptr);
}

template <typename T>
FrankList<T>::multi_iterator FrankList<T>::mabegin()
{
    return multi_iterator(ahead);
}

template <typename T>
FrankList<T>::multi_iterator FrankList<T>::maend()
{
    return multi_iterator(nullptr);
}

template <typename T>
FrankList<T>::multi_reverse_iterator FrankList<T>::mrbegin()
{
    return multi_reverse_iterator(tail);
}

template <typename T>
FrankList<T>::multi_reverse_iterator FrankList<T>::mrend()
{
    return multi_reverse_iterator(nullptr);
}

template <typename T>
FrankList<T>::multi_reverse_iterator FrankList<T>::mrdbegin()
{
    return multi_reverse_iterator(atail);
}

template <typename T>
FrankList<T>::multi_reverse_iterator FrankList<T>::mrdend()
{
    return multi_reverse_iterator(nullptr);
}

////////////////////////////////////////////////////////////////////

template <typename T>
template <typename iter>
iter FrankList<T>::insert_def(iter pos, const_reference val) {
    Node *temp = new Node(val);
    Node *current = head;
    Node *prevNode = nullptr;
    while (current != nullptr && current != pos.ptr) {
        prevNode = current;
        current = current->next;
    }
    temp->next = current;
    temp->prev = prevNode;
    if (prevNode != nullptr) {
        prevNode->next = temp;
    } else {
        head = temp;
    }
    current->prev = temp;
    put_in_sorted_order(temp);
    return iter(temp);
}

template <typename T>
template <typename iter>
iter FrankList<T>::insert(iter& pos, typename FrankList<T>::size_type count, typename FrankList<T>::const_reference val) {
    for (size_type i = 0; i < count; i++) {
        pos = insert_def(pos, val);
    }
    return pos;
}
template <typename T>
template <typename iter>
iter FrankList<T>::insert(iter pos, std::initializer_list<T> ilist) {
    for (auto it = ilist.begin(); it != ilist.end(); it++) {
        pos = insert(pos, *it);
    }
    return pos;
}
template <typename T>
template <typename iter, typename input_iterator>
iter FrankList<T>::insert(iter pos, input_iterator f, input_iterator l) {
    while (f != l) {
        pos = insert(pos, *f);
        ++f;
    }
    return pos;
}

template<typename T>
template<typename iter>
iter FrankList<T>::erase(iter& pos) {
    if (pos == end()){
        return pos;
    }
    Node* tmp = pos.ptr;
    if (tmp == nullptr){
        return pos;
    }
    if (tmp == head){
        head = head->next;
    }
    if (tmp == tail){
        tail = tail->prev;
    }
    if (tmp->prev != nullptr){
        tmp->prev->next = tmp->next;
    }
    if (tmp->next != nullptr){
        tmp->next->prev = tmp->prev;
    }
    iter nextIter(tmp->next);
    delete tmp;

    return nextIter;
}

template<typename T>
template<typename iter>
iter FrankList<T>::erase(iter f, iter l) {
    while (f != l) {
        f = erase(f);
    }
    return l;
}

template<typename T>
typename FrankList<T>::size_type FrankList<T>::remove(const_reference val) {
    size_type count = 0;
    iterator it = begin();
    while (it != end()) {
        if (*it == val) {
            it = erase(it);
            ++count;
        } else {
            ++it;
        }
    }
    return count;
}

template<typename T>
template<typename unary_predicate>
typename FrankList<T>::size_type FrankList<T>::remove_if(unary_predicate func) {
    size_type count = 0;
    iterator it = begin();
    while (it != end()) {
        if (func(*it)) {
            it = erase(it);
            ++count;
        } else {
            ++it;
        }
    }
    return count;
}

template<typename T>
typename FrankList<T>::iterator FrankList<T>::find(const_reference elem) {
    iterator it = begin();
    while (it != end()) {
        if (*it == elem) {
            return it; 
        }
        ++it;
    }
    return end();  
}

template<typename T>
typename FrankList<T>::iterator FrankList<T>::rfind(const_reference elem) {
    iterator it = end();
    while (it != begin()) {
        --it;
        if (*it == elem) {
            return it; 
        }
    }
    return begin(); 
}

template<typename T>
void FrankList<T>::reverse() {
    size_t size = this -> size();    
    if (head == nullptr || size == 1) {
         return;
    } else {
         Node* new_node = head;
         Node* node = tail;
         Node* end = nullptr;
         while (new_node != node) {
             head = head-> next;
             head -> prev = nullptr;
             new_node -> next = nullptr;
             if (tail -> next == nullptr) {
                tail -> next = new_node;
                new_node -> prev = tail;
                end = new_node;
              } else {
                tail -> next-> prev = new_node;
                new_node -> prev = tail;
                new_node -> next = tail -> next;
                tail -> next = new_node;
              }
              new_node = nullptr;
              new_node = head;
         }
         tail = end;
         end = nullptr;
         new_node = nullptr;
         node = nullptr;
    }
}

template<typename T>
void FrankList<T>::print(bool sorted, bool reversed) {
    if (sorted) {
        FrankList<T> tmp(*this);
        tmp.sort(reversed);
        tmp.print(false);
        return;
    }

    if (head == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node* current = head;

    if (!reversed) {
        while (current != nullptr) {
            std::cout << current->val << " ";
            current = current->next;
        }
    } else {
        Node* last = head;
        while (last->next != nullptr){
            last = last->next;
        }
        while (last != nullptr) {
            std::cout << last->val << " ";
            last = last->prev;
        }
    }

    std::cout << std::endl;
}

template<typename T>
void FrankList<T>::sort(bool reversed) {
    if (head == nullptr || head->next == nullptr)
        return;

    bool b;
    Node* current;
    Node* last = nullptr;

    do {
        b = false;
        current = head;

        while (current->next != last) {
            if ((!reversed && current - >val > current -> next -> val) || (reversed && current -> val < current -> next -> val)) {
                T temp = current -> val;
                current -> val = current -> next -> val;
                current -> next -> val = temp;
                b = true;
            }
            current = current -> next;
        }
        last = current;
    } while (b);
}

template <typename T>
void FrankList<T>::put_in_sorted_order (Node* ptr)
{
    if(ptr -> val <= ahead -> val) {
        ahead -> desc = ptr;
        ptr -> asc = ahead;
        ahead = ptr;
        return;
    } else if (ptr -> val >= atail -> val) {
        atail -> asc = ptr;
        ptr -> desc = atail;
        atail = ptr;
        return;
    } else {
        Node* current = ahead;
        while (current -> val <= ptr -> val)
        {
            current  = current -> asc;
        }
        ptr -> asc = current;
        ptr -> desc = current -> desc;
        ptr -> desc -> asc = ptr;
        current -> desc = ptr;
    }
}

template <typename T>
void FrankList<T>::remove_in_sorted_order(Node* ptr)
{
    if (ptr == ahead){
        ahead = ptr -> asc;
        ahead -> desc = nullptr;
    } else if (ptr == atail){
        atail = ptr -> desc;
        atail -> asc = nullptr;
    } else {
        ptr -> desc -> asc = ptr -> asc;
        ptr -> asc -> desc = ptr -> desc;
    }

}

template<typename T>
std::ostream& operator<<(std::ostream& cout, const FrankList<T>& rhv)
{
    typename FrankList<T>::template Node* tmp = rhv.m_head;
    while (tmp != nullptr) {
        cout << tmp -> val << " ";
        tmp = tmp -> next;
    }
    return cout;
}


