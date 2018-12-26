// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This is the file to include in your code if you want access to the
// complete LList template class

// First, get the declaration for the base list class
#include "list.h"

// This is the declaration for LList. It is split into two parts
// because it is too big to fit on one book page
// Linked list implementation

#include "book.h"
#include "SLelement.h"

using namespace bridges;

template <typename E> class LList: public List<E> {
private:
  SLelement<E>* head;       // Pointer to list header
  SLelement<E>* tail;       // Pointer to last element
  SLelement<E>* curr;       // Access to current element
  int cnt;					// Size of list

  void init() {        // Intialization helper method
    curr = tail = head = new SLelement<E>();
    cnt = 0;
  }

  void removeall() {   // Return link nodes to free store
    while(head != NULL) {
      curr = head;
      head = head->getNext();
      delete curr;
    }
  }

public:
  LList(int size=defaultSize) { init(); }    // Constructor
  ~LList() { removeall(); }                   // Destructor
  void print() const;                // Print list contents
  void clear() { removeall(); init(); }       // Clear list

  // Insert "it" at current position
  void insert(const E& it) {
    curr->setNext(new SLelement<E>(curr->getNext(), it) );  
    if (tail == curr) tail = curr->getNext();  // New tail
    cnt++;
  }

  void append(const E& it) { // Append "it" to list
	tail->setNext(new SLelement<E>(it, NULL) );
    tail = tail->getNext();
    cnt++;
  }

  // Remove and return current element
  E remove() {
    Assert(curr->getNext() != NULL, "No element");
    E it = curr->getNext()->getValue();      // Remember value
    SLelement<E>* ltemp = curr->getNext();     // Remember link node
    if (tail == curr->getNext()) tail = curr; // Reset tail
    curr->setNext(curr->getNext()->getNext());   // Remove from list
    delete ltemp;                    // Reclaim space
    cnt--;			     // Decrement the count
    return it;
  }

  void moveToStart() // Place curr at list start
    { curr = head; }

  void moveToEnd()   // Place curr at list end
    { curr = tail; }

  // Move curr one step left; no change if already at front
  void prev() {
    if (curr == head) return;       // No previous element
    SLelement<E>* temp = head;
    // March down list until we find the previous element
    while (temp->getNext() != curr) 
		temp=temp->getNext();
    curr = temp;
  }

  // Move curr one step right; no change if already at end
  void next()
    { if (curr != tail) curr = curr->getNext(); }

  int length() const  { return cnt; } // Return length

  // Return the position of the current element
  int currPos() const {
    SLelement<E>* temp = head;
    int i;
    for (i=0; curr != temp; i++)
      temp = temp->getNext();
    return i;
  }

  // Move down list to "pos" position
  void moveToPos(int pos) {
    Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
    curr = head;
    for(int i=0; i<pos; i++) 
		curr = curr->getNext();
  }

  const E getValue() const { // Return current element
    Assert(curr->getNext() != NULL, "No value");

    return curr->getNext()->getValue();
  }

  SLelement<E>* getFront() const { // return the head of the list
	return head;
  }
  SLelement<E>* getEnd() const { // return the end of the list
	return tail;
  }

  SLelement<E>* getCurrent() const { // return the end of the list
	return curr;
  }
	
};
