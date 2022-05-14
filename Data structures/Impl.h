#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
List<T>::List() //Constructor
{
  cout << "Creating new list" << endl;
  head = NULL;
  tail = NULL;
}

template <typename T>
List<T>::~List() //Destructor
{
  while (head!=NULL)
    remove(0);
}

template <typename T>
int List<T>::size() const 
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
void List<T>::insert(int position, const T & val)
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
void List<T>::print()
{
  Item<T>* item = head;

  cout << "Current members in list: ";
  while (item != NULL)
  {
    cout << item->value << " ";
    item = item->next;
  }
  cout << endl;
}

template <typename T>
void List<T>::remove(int position)
{
  if (position >= size() || position < 0)
    throw out_of_range("Out of range");

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
void List<T>::set(int position, const T & val)
{
  if (position >= size() || position < 0)
    throw out_of_range("Out of range");

  Item<T>* setObj = head; //Replace given position with given value
  for (int i=0; i<position; i++)
    setObj = setObj->next;

  setObj->value = val;
}

template <typename T>
T& List<T>::get (int position) const
{
  if (position >= size() || position <0)
    throw out_of_range("Out of range");

  Item<T>* retrieve = head;
  for (int i=0; i<position; i++)
    retrieve = retrieve->next;

  return retrieve->value;
}












