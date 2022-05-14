#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
using namespace std;

template <class T, class Comparator>
class MaxHeap {
  public:
    MaxHeap (int d, Comparator comp);
       /* Constructor that builds a d-ary Max Heap using the given
          comparator to compare elements and decide which one is
          larger. 
          This should work for any d >= 2,
          but doesn't have to do anything for smaller d.*/

    ~MaxHeap ();

    void add (const T & item);
         /* adds the item to the heap */

    const T & peek () const;
         /* returns the element with maximum priority.
            Throws an exception if the heap is empty. */

    void remove ();
         /* removes the element with maximum priority. */

    bool isEmpty ();
         /* returns true iff there are no elements on the heap. */

    vector<T> returnHeap();

  private:
    int dHeap;
    Comparator compare;
    vector<T> heapList;
};

template <class T>
void swapItems(T& lhs, T& rhs)
{
  T temp = lhs;
  lhs = rhs;
  rhs = temp;
}

template <class T, class Comparator> //Constructor
MaxHeap<T, Comparator>::MaxHeap(int d, Comparator comp) : dHeap(d), compare(comp)
{
}

template <class T, class Comparator> //Destructor
MaxHeap<T, Comparator>::~MaxHeap()
{
}

template <class T, class Comparator>
void MaxHeap<T, Comparator>::add (const T& item)
{
  heapList.push_back(item); //Add to back of array
  int childN = heapList.size() - 1; 
  int parent = ceil((double)childN/(double)dHeap) - 1;

  while (childN != 0 && compare(heapList[parent], heapList[childN]) ) //While child > parent, keep moving up
  {
    swapItems(heapList[childN], heapList[parent]);
    childN = parent;
    parent = ceil((double)childN/(double)dHeap) - 1;
  }
}

template <class T, class Comparator>
vector<T> MaxHeap<T, Comparator>::returnHeap()
{
  return heapList;
}

template <class T, class Comparator>
const T& MaxHeap<T, Comparator>::peek () const
{
  if (heapList.size() == 0)
    throw (out_of_range("Out of Range"));
  return heapList[0]; //Returns item at top of the heap
}


template <class T, class Comparator>
void MaxHeap<T, Comparator>::remove()
{
  if (isEmpty()) //Stop if nothing in array
    throw (out_of_range("Out of Range"));
  if (heapList.size() == 1) //If only one item, remove it 
  {
    heapList.pop_back();
    return;
  }

  int index = heapList.size() - 1;
  heapList[0] = heapList[index]; //Swap top index with last index
  heapList.pop_back();

  int child, parent, gChild;
  parent = 0; //Parent starts at first spot

  while (1)
  {
    gChild = -1; //Initialize greatest child as impossible value
    for (int i=1; i<=dHeap; i++) //Compare all children to find greatest
    {
      child = (dHeap*parent) + i;
      if (child >= heapList.size()) //If no more children, stop comparing
        break;
      if (i == 1) //First time, set gChild as child
      {
        gChild = child;
        continue;
      }
      if (compare(heapList[gChild], heapList[child])) //If current child is the greatest, set as gChild
        gChild = child; //Finding greatest child's value's index    
    }

    if (gChild == -1 ) //If no children are found (leaf node), stop
      break;

    if (compare(heapList[parent], heapList[gChild])) //If parent's value <= child's value, swap
      swap(heapList[parent], heapList[gChild]);
    else
      break;

    parent = gChild;
  }
}

template <class T, class Comparator>
bool MaxHeap<T,Comparator>::isEmpty ()
{
  if (heapList.size() == 0)
    return true;
  else
    return false;
}




