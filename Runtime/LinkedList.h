#ifndef P3_H
#define P3_H
#include <iostream>
#include <stdexcept>
#include "../Source/ilist.h"
using namespace std;

template <typename T>
struct Item
{
  T value;
  Item<T> *prev, *next;
};

template <typename T>
class LinkedList : public IList<T>
{
  public:
    LinkedList ();   // constructor

    LinkedList (const LinkedList<T> & newList); // A copy constructor which performs a deep copy.

    ~LinkedList ();  // destructor

    LinkedList<T> & operator= (const LinkedList<T> & newList);

    int size () const;  // returns the number of elements in the list 

    void insert (int position, const T & val);
     
    void print();

    void remove (int position);

    void set (int position, const T & val);

    T& get (int position);
 
    T const & get (int position) const;


    private:
      Item<T> *head, *tail;

};



template <typename T>
LinkedList<T>::LinkedList() //Constructor
{
  head = NULL;
  tail = NULL;
}

template <typename T>
LinkedList<T>::LinkedList (const LinkedList<T> & newList) //Copy constructor
{
  head = NULL;
  tail = NULL;
  for (int i=0; i< newList.size(); i++)
    insert(i, newList.get(i)); 
}

template <typename T>
LinkedList<T>::~LinkedList() //Destructor
{
  while (head!=NULL)
    remove(0);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator= (const LinkedList<T> & newList) //Overload =
{
  if (this == &newList) //Self assignment check
    return *this;

  if (head!=NULL) //Previous assignment check
  {
    while (head!=NULL)
      remove(0);
  }

  for (int i=0; i< newList.size(); i++)
    insert(i, newList.get(i)); 

  return *this;
}

template <typename T>
int LinkedList<T>::size() const 
{
  int count = 0;
  Item<T>* temp = head;
  while (temp != NULL)
  {
    count++;
    temp = temp->next;
  }
  return count;
}

template <typename T>
void LinkedList<T>::insert(int position, const T & val)
{
  if (position > size() || position < 0)
    throw out_of_range("Out of range");

  if (head == NULL) //Create new item if no other items
  {
    Item<T>* nI = new Item<T>;
    nI->next = NULL;
    nI->prev = NULL;
    nI->value = val;
    head = nI;
    tail = nI;
    return;
  }    

  if (position == size()) //Add to end of list
  {
    Item<T>* nI = new Item<T>;
    Item<T>* temp = tail;
    nI->next = NULL;
    nI->prev = tail;
    nI->value = val;
    tail = nI;
    temp->next = nI;
    return;
  }

  if (position == 0) //Add to front with existing list
  {
    Item<T>* nI = new Item<T>;
    Item<T>* temp = head;
    temp->prev = nI;
    nI->prev = NULL;
    nI->next = head;
    nI->value = val;
    head = nI;
    return;
  }

  Item<T>* temp = head; //Add to the middle
  for (int i=0; i<position; i++)
    temp = temp->next;
  Item<T>* nI = new Item<T>;
  nI->next = temp;
  nI->prev = temp->prev;
  nI->value = val;
  
  Item<T>* temp2 = temp->prev;
  temp->prev = nI;
  temp2->next = nI;
}

template <typename T>
void LinkedList<T>::print()
{
  Item<T>* item = head;

  while (item != NULL)
  {
    cout << item->value << endl;
    item = item->next;
  }
  cout << endl;
}

template <typename T>
void LinkedList<T>::remove(int position)
{
  if (position >= size() || position < 0)
    throw out_of_range("Out of range, remove");

  if (position == 0) //Remove front object
  {
    Item<T>* deleted = head;
    if (deleted->next == NULL) //If only one object left
    {
      delete deleted;
      head = NULL;
      return;
    }
    head = deleted->next;
    Item<T>* temp = head;
    temp->prev = NULL;
    delete deleted;
    return;
  } 

  if (position == (size()-1)) //Remove last object
  {
    Item<T>* deleted = tail; 
    tail = deleted->prev;
    Item<T>* temp = tail;
    temp->next = NULL;
    delete deleted;
    return;
  }

  Item<T>* deleted = head; //Remove middle object
  for (int i=0; i<position; i++)
    deleted = deleted->next;

  Item<T>* prevO = deleted->prev;
  Item<T>* nextO = deleted->next;
  prevO->next = nextO;
  nextO->prev = prevO;
  delete deleted;
}

template <typename T>
void LinkedList<T>::set(int position, const T & val)
{
  if (position >= size() || position < 0)
    throw out_of_range("Out of range, set");

  Item<T>* setObj = head; //Replace given position with given value
  for (int i=0; i<position; i++)
    setObj = setObj->next;

  setObj->value = val;
}

template <typename T>
T& LinkedList<T>::get (int position)
{
  if (position >= size() || position <0)
    throw out_of_range("Out of range, position");

  Item<T>* retrieve = head;
  for (int i=0; i<position; i++)
    retrieve = retrieve->next;

  return retrieve->value;
}

template <typename T>
T const & LinkedList<T>::get (int position) const
{
  if (position >= size() || position <0)
    throw out_of_range("Out of range, position");

  Item<T>* retrieve = head;
  for (int i=0; i<position; i++)
    retrieve = retrieve->next;

  return retrieve->value;
}

#endif
