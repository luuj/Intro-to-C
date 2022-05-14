#ifndef MAP_H
#define MAP_H
#include "../Assortedlists/LinkedList.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

template <class keyType, class valueType>
class Map
{
  public:
    Map ();  // constructor for a new empty map

    ~Map (); // destructor

    int size () const; // returns the number of key-value pairs

    void add (const keyType & key, const valueType & value); 
      /* Adds a new association between the given key and the given value.
         If the key already has an association, it should throw an exception.
      */

    void printMap();

    void remove (const keyType & key);
     /* Removes the association for the given key.
        If the key has no association, it should throw an exception. */

    valueType& get (const keyType & key);
     /* Returns the value associated with the given key.
        If the key has no association, it should throw an exception. */

  private:
    struct Pair{
      keyType k;
      valueType v; };

    LinkedList<Pair> internalStorage;
};

template <class keyType, class valueType>
Map<keyType, valueType>::Map() //Constructor
{
}

template <class keyType, class valueType>
Map<keyType, valueType>::~Map() //Destructor
{
}

template <class keyType, class valueType>
int Map<keyType, valueType>::size() const
{
  return internalStorage.size();
}

template <class keyType, class valueType>
void Map<keyType, valueType>::add (const keyType & key, const valueType & value)
{
  Pair newMap;
  newMap.k = key;
  newMap.v = value;

  for (int i=0; i<size(); i++)  //Check if a key is already assigned to another value
  {
    if (internalStorage.get(i).k == key)
      throw invalid_argument("Key already assigned. Cannot add"); 
  }

  internalStorage.insert( internalStorage.size(), newMap );
}

template <class keyType, class valueType>
void Map<keyType, valueType>::printMap()
{
  if (internalStorage.size() == 0)
    cout << "No elements in map" << endl;

  for (int i=0; i<size(); i++)
  {
    cout << left << "Key: " << setw(30) << internalStorage.get(i).k << "Value: " 
    << setw(30) << internalStorage.get(i).v << endl;
  }
}

template <class keyType, class valueType>
void Map<keyType, valueType>::remove (const keyType & key)
{
  for (int i=0; i<size(); i++)
  {
    if (internalStorage.get(i).k == key)
    {
      internalStorage.remove(i);
      return; 
    }
  }

  throw invalid_argument("No key was found when attempting to remove");  
  return;
}

template <class keyType, class valueType>
valueType& Map<keyType, valueType>::get (const keyType & key)
{
  for (int i=0; i<size(); i++)
  {
    if (internalStorage.get(i).k == key)    
      return internalStorage.get(i).v;     
  }

  throw invalid_argument("No key was found when attempting to get");  
  return internalStorage.get(0).v; //Never reaches
}


#endif
