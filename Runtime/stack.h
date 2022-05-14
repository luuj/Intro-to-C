#ifndef STACK_S
#define STACK_S
#include <iostream>
#include "arraylist.h"
#define AL arrayList<T>
using namespace std;

template <typename T>
class Stack : private arrayList <T>
{
 public:
  // add appropriate constructors and destructors
  Stack() : AL::arrayList() {}
  ~Stack(){}

  bool isEmpty() const;
  /* returns whether the stack contains any elements */

  void push(const T& val);
  /* adds a value to the top of the stack */

  void pop();
  /* deletes the top value from the stack */

  T const & top() const;
  /* returns the top value on the stack */

  void clearStack();

  void print();
};

template <typename T>
bool Stack<T>::isEmpty() const
{
  if (AL::size() == 0)
    return true;
  return false;
}

template <typename T>
void Stack<T>::push(const T& val)
{
  AL::insert(AL::size(), val); 
}

template <typename T>
void Stack<T>::pop()
{
  if (AL::size() == 0)
  {
    cout << "Nothing to pop" << endl;
    return;
  }

  AL::remove(AL::size()-1);
}

template <typename T>
T const & Stack<T>::top() const
{
  return AL::get(AL::size()-1);
}

template <typename T>
void Stack<T>::clearStack()
{
  while (!isEmpty())
    pop();
}

template <typename T>
void Stack<T>::print()
{
  cout << "Currently in stack: " << endl;
  for (int i=0; i<AL::size(); i++)
    cout << AL::arrayL[i] << endl;
}
#endif
