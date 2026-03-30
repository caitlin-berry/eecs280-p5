#ifndef LIST_HPP
#define LIST_HPP
/* List.hpp
 *
 * doubly-linked, double-ended list with Iterator interface
 * EECS 280 List/Editor Project
 */

#include <iostream>
#include <iterator> //std::bidirectional_iterator_tag
#include <cassert>  //assert


template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:
  List() : first(nullptr), last(nullptr), size_(0) {}

  // deconstructor
  ~List() {
    // delete all nodes
    clear(); 
  }

  // copy constructor
  List(const List& other) : first(nullptr), last(nullptr), size_(0) {
    // copy nodes
    copy_all(other); 
  }

  // assignment Operator
    List& operator=(const List& other) {
      if (this != &other) { 
        // free current list
        clear();
        // copy nodes from other
        copy_all(other); 
      }
      return *this;
    }

  //EFFECTS:  returns true if the list is empty
  bool empty() const{
    return size_ == 0;
  }

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow. Instead, keep track of the size
  //         with a private member variable. That's how std::list does it.
  int size() const{
    return size_;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  T & front(){
    // first node is the front of the list; get that data
    return first->datum;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back(){
    // last node is the back of the list; get that data
    return last->datum;
  }

  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum){
    // create a new node and make it the first node
    Node* new_node =  new Node{datum, nullptr, first};
    // check where it is
    if (first) {
      // update the old first node's prev ptr
      first->prev = new_node;
    }
    // update the frist ptr to the new one
    first = new_node;
    // if the list is empty...
    if (!last) {
      // this is also the last node
      last = new_node;
    }
    // increase the size since smth was added
    ++size_;
  }

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum){
    // create a new node and make it the last node
    Node* new_node = new Node{datum, last, nullptr};
    // check where it is
    if (last) {
      // update the old last node's next ptr
      last->next = new_node;
    }
    // update the last ptr to the new node
    last = new_node;
    // if the list is impty...
    if (!first) {
      // this is also the first node
      first = new_node;
    }
    // increase the size since smth was added
    ++size_;
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front(){
    // create a temp node to store the current first node
    Node* temp = first;
    // move the first ptr to the next one
    first = first->next;
    // check where it's pointing
    if (first) {
      // update the new first node's prev ptr
      first->prev = nullptr;
    // if the list is empty...
    } else {
      // ... update the last ptr
      last = nullptr;
    }
    // free memory
    delete temp;
    // decrease the size since smth was removed
    --size_;
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back(){
    // create a temp node to store the current last node
    Node* temp = last;
    // move the last ptr to the prev one
    last = last->prev;
    // check where it's pointing
    if (last) {
      // update the new last node's next ptr
      last->next = nullptr;
    // if the list is empty...
    } else {
      // ... update the first ptr
      first = nullptr;
    }
    // free memory
    delete temp;
    // decrease the size since smth was removed
    --size_;
  }

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear(){
    // go through the whole list until it's empty
    while (!empty()){
      // remove an element from front
      pop_front();
    }
  }

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you should omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists.

private:
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;

    // constructor to initialize the node
    Node(const T& d, Node* p = nullptr, Node* n = nullptr)
                  : next(n), prev(p), datum(d) {}
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other){
    // go through all the elements in other
    for (Node* curr = other.first; curr != nullptr; curr = curr->next) {
      // add each node's data to the list
      push_back(curr->datum);
    }
  }

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty
  // # of elements
  int size_ = 0;

public:
  ////////////////////////////////////////
  class Iterator {
  public:
    //OVERVIEW: Iterator interface to List

    // Add a default constructor here. The default constructor must set both
    // pointer members to null pointers.
    Iterator() : list_ptr(nullptr), node_ptr(nullptr) {}


    // Add custom implementations of the destructor, copy constructor, and
    // overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you should omit them. A user
    // of the class must be able to copy, assign, and destroy Iterators.

    // not needed ?


    // Your iterator should implement the following public operators:
    // *, ++ (both prefix and postfix), == and !=.
    // Equality comparisons must satisfy the following rules:
    // - two default-constructed iterators must compare equal
    // - a default-constructed iterator must compare unequal to an
    //   iterator obtained from a list, even if it is the end iterator
    // - two iterators to the same location in the same list must
    //   compare equal
    // - two iterators to different locations in the same list must
    //   compare unequal
    // - comparing iterators obtained from different lists results in
    //   undefined behavior
    //   - Your implementation can handle this however you like, but
    //     don't assume any particular behavior in your test cases --
    //     comparing iterators from different lists essentially
    //     violates the REQURES clause.
    // Note: comparing both the list and node pointers should be
    // sufficient to meet these requirements.

    // dereference operator
    T& operator*() const {
      // return the data in the current node
      return node_ptr->datum;
    }

    // prefix
    Iterator& operator++() {
      // move the the next node
      node_ptr = node_ptr->next;
      return *this;
    }

    // postfix
    Iterator operator++(int) {
      // copt the curret iterator
      Iterator temp = *this;
      // increment it
      ++(*this);
      // return the original
      return temp;
    }

    bool operator==(const Iterator& other) const {
      if (list_ptr == other.list_ptr) {
        if (node_ptr == other.node_ptr) {
          return true;
        }
      }
      return false;
    }

    bool operator!=(const Iterator& other) const {
      return !(*this == other);
    }

    // Type aliases required to work with STL algorithms. Do not modify these.
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    // This operator will be used to test your code. Do not modify it.
    // REQUIRES: Iterator is decrementable. All iterators associated with a
    //           list are decrementable, including end iterators, except for
    //           begin iterators (those equal to begin() on the list)
    // EFFECTS:  moves this Iterator to point to the previous element
    //           and returns a reference to this Iterator
    Iterator& operator--() { // prefix -- (e.g. --it)
      assert(list_ptr);
      assert(*this != list_ptr->begin());
      if (node_ptr) {
        node_ptr = node_ptr->prev;
      } else { // decrementing an end Iterator moves it to the last element
        node_ptr = list_ptr->last;
      }
      return *this;
    }

    // This operator will be used to test your code. Do not modify it.
    // REQUIRES: Iterator is decrementable. All iterators associated with a
    //           list are decrementable, including end iterators, except for
    //           begin iterators (those equal to begin() on the list)
    // EFFECTS:  moves this Iterator to point to the previous element
    //           and returns a copy of the original Iterator
    Iterator operator--(int /*dummy*/) { // postfix -- (e.g. it--)
      Iterator copy = *this;
      operator--();
      return copy;
    }

    // REQUIRES: Iterator is dereferenceable
    // EFFECTS: returns the underlying element by pointer
    // NOTE: T must be a class type to use the syntax it->. If T has a
    //       member variable f, then it->f accesses f on the
    //       underlying T element.
    T* operator->() const {
      return &operator*();
    }

  private:
    const List *list_ptr; //pointer to the List associated with this Iterator
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here               

    // add any friend declarations here
    // allow access to priv members
    friend class List;

    // construct an Iterator at a specific position in the given List
    Iterator(const List *lp, Node *np) : list_ptr(lp), node_ptr(np) {}

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(this, first);
  }

  // return an Iterator pointing to "past the end"
  Iterator end() const {
    return Iterator(this, nullptr);
  }

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container.
  //         Returns An iterator pointing to the element that followed the
  //         element erased by the function call
  Iterator erase(Iterator i){
    // save the node to delete
    Node* toDelete = i.node_ptr;
    // get the position of next iterator
    Iterator next(this, toDelete->next);
    if (toDelete->prev) {
      // update prev node's next ptr
      toDelete->prev->next = toDelete->next;
    } else {
      // update first ptr
      first = toDelete->next;
    }
    if (toDelete->next) {
      // update next node's prev ptr
      toDelete->next->prev = toDelete->prev;
    } else {
      // update last ptr
      last = toDelete->prev;
    }
    // free memory
    delete toDelete;
    // decrement size of list
    --size_;
    // return the next iterator
    return next;
  }

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: Inserts datum before the element at the specified position.
  //         Returns an iterator to the the newly inserted element.
  Iterator insert(Iterator i, const T &datum){
    // if the iterator is at the end...
    if (i.node_ptr == nullptr) {
      // ... add at the back
      push_back(datum);
      return Iterator(this, last);
    }
    // create a new node
    Node* new_node = new Node(datum, i.node_ptr->prev, i.node_ptr);
    if (i.node_ptr->prev) {
      // update prev node's next ptr
      i.node_ptr->prev->next = new_node;
    } else {
      // update first ptr
      first = new_node;
    }
    // update current node's prev ptr
    i.node_ptr->prev = new_node;
    // increment size of list
    ++size_;
    // return the iterator to the new node
    return Iterator(this, new_node);
  }

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.


#endif // Do not remove this. Write all your code above this line.
