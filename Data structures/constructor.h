#ifndef P3_H
#define P3_H

template <typename T>
struct Item
{
  T value;
  Item<T> *prev, *next;
};

template <typename T>
class List
{
  public:
    List ();   // constructor

    ~List ();  // destructor

    int size () const;  // returns the number of elements in the list 

    void insert (int position, const T & val);
      /* Inserts val into the list before the given position,
         shifting all later items one position to the right.
         Inserting before 0 makes it the new first element.
         Inserting before size() makes it the new last element.
         Your function should throw an exception if position is
         outside the legal range. */
     
    void print();

    void remove (int position);
      /* Removes the item from the given position, shifting all
         later items one position to the left.
         Your function should throw an exception if position is
         outside the legal range. */

    void set (int position, const T & val);
      /* Overwrites the given position with the given value.
         Does not affect any other positions.  
         Your function should throw an exception if position is
         outside the legal range. */

    T& get (int position) const;
      /* Returns the item at the given position.
         Your function should throw an exception if position is
         outside the legal range. */

    private:
      Item<T> *head, *tail;


};

#include "P3Impl.h"
#endif
