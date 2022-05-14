#ifndef ARRAYL_H
#define ARRAYL_H
#include <iostream>
#include "ilist.h"
#include <stdexcept>
using namespace std;

template <class T>
class arrayList : public IList<T>
{
  public:
    arrayList (); //Constructor
    virtual ~arrayList (); //Destructor   

    int size () const;
    void insert (int position, const T & val);
    void remove (int position);
    void set (int position, const T & val);
    T& get (int position);
    T const & get (int position) const;
    void print();

  protected:
    virtual void resize();
    T *arrayL;
    int itemCount; //Array item counter
    int maxCount;
};

template <class T> //Constructor
arrayList<T>::arrayList() : itemCount(0), maxCount(10)
{
  arrayL = new T[maxCount];
}

template <class T> //Destructor
arrayList<T>::~arrayList()
{
  delete [] arrayL;
}

template <class T> //Returns total # of items in array
int arrayList<T>::size() const 
{
  return itemCount;
}

template <class T> 
void arrayList<T>::insert (int position, const T& val)
{
  if (itemCount >= maxCount)
    resize();

  if (position > itemCount || position < 0)
    throw out_of_range("Cannot insert. Position out of range");

  if (position == itemCount) //If at end of array, just insert
  {
    arrayL[position] = val;
    itemCount++;
    return;
  }
  else
  {
    for (int i=itemCount; i>position; i--)
      arrayL[i] = arrayL[i-1]; //Move over all elements by 1

   arrayL[position] = val;
   itemCount++;
   return;
  }
}

template <class T>
void arrayList<T>::remove (int position)
{
  if (position >= itemCount || position < 0)
    throw out_of_range("Cannot remove. Position out of range");

  if (position == itemCount-1) //If at end, just shift item count
  {
    itemCount--;
    return;
  }
  else
  {
    for (int i=position; i<itemCount-1; i++) //Shift all needed elements over to the right
    {
      arrayL[i] = arrayL[i+1];
      itemCount--;
      return;
    }
  }
}

template <class T>
void arrayList<T>::set (int position, const T & val)
{
  if (position >= itemCount || position < 0)
    throw out_of_range("Cannot set. Position out of range");
  
  arrayL[position] = val;
}

template <class T>
T& arrayList<T>::get (int position)
{
  if (position >= itemCount || position < 0)
    throw out_of_range("Cannot get item. Position out of range");

  return arrayL[position];
}

template <class T>
T const& arrayList<T>::get (int position) const
{
  if (position >= itemCount || position < 0)
    throw out_of_range("Cannot get item. Position out of range");

  return arrayL[position];
}

template <class T>
void arrayList<T>::print()
{
  for (int i=0; i<size(); i++)
    cout << arrayL[i] << endl;
cout << "Max count: " << maxCount << endl;
cout << "Current count: " << itemCount << endl;
}

template <class T>
void arrayList<T>::resize()
{
  T* newarrayL = new T[maxCount*2]; //New array
  for (int i=0; i<maxCount; i++)
    newarrayL[i] = arrayL[i]; //Copy old array into new one

  T* temp = arrayList<T>::arrayL; //Rearrange pointers so it points to new array
  arrayL = newarrayL;
  delete [] temp; //Delete old array
  maxCount*=2; //Increase max count
}


#endif
