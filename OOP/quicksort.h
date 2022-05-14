#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include <ctime>
using namespace std;

//Prototypes
void fillArray (vector<int>& temp, int num);
void printArray (vector<int>& temp, int size);
void swapContents (vector<int>& temp, int num);
void lastquickSort(vector<int>& tempList, int start, int end);
template <class T, class Comparator>
int partition(vector<T>& tempList, int start, int end, int randNum, Comparator comp);
template <class T>
void swapItems (T& left, T& right);
template <class T, class Comparator>
void randquickSort(vector<T>& tempList, int start, int end, Comparator comp);
//End prototypes

struct numberCompare //Comparator for ints
{
  bool operator()(const int& lhs, const int& rhs)
  {
    if (lhs <= rhs)
      return true;
    else
      return false;
  }
};

void fillArray (vector<int>& temp, int num) //Fills array with random values
{
  for (int i=0; i<num; i++) //Insert random number from 1 and 50000
  {
    temp.push_back(rand() % 50000 + 1);    
  } 
  sort(temp.begin(), temp.end());
}

void printArray (vector<int>& temp, int size) //Prints array out
{
  for (int i=0; i<(signed)temp.size(); i++)
    cout << temp[i] << endl;
}

void swapContents (vector<int>& temp, int num) //Swaps two random elements x number of times
{
  signed int size = temp.size();
  int tempVal, val1, val2;
  for (int i=0; i<num; i++) //Swap num times
  {
    val1 = rand() % size; //Pick 2 random elements in vector
    val2 = rand() % size;
    tempVal = temp[val1]; //Store first element in tempVal
    temp[val1] = temp[val2]; //Swap element with something else
    temp[val2] = tempVal;
  }
}

template <class T, class Comparator>
int partition(vector<T>& tempList, int start, int end, int randNum, Comparator comp) 
{ 
  T pivot = tempList[randNum]; //Pick a random element in tempList
  swapItems(tempList[randNum], tempList[end]); //Swap pivot element and last element

  int left = start; 
  int right = end-1; 

  while(left < right)
  { 
    while (comp(tempList[left], pivot) && (left<right) )
      left++; 

    while(comp(pivot, tempList[right]) && (left < right))
      right--; 

    if(left < right) 
      swap(tempList[left], tempList[right]);
  } 

  if (left == right && comp(tempList[right], tempList[end])) //Check if left is same as right
    return right;

  swapItems(tempList[right], tempList[end]); // Place pivot in correct place
  return right; 
} 

template <class T>
void swapItems (T& left, T& right) //Swap two values
{
  T temp1 = left;
  left = right;
  right = temp1;
}

template <class T, class Comparator>
void randquickSort(vector<T>& tempList, int start, int end, Comparator comp) //QSort with random pivot
{ 
  if(start >= end) 
    return; 

  int randNum = rand() % ((end+1)-start) + start; //Select random element within array

  int loc = partition(tempList, start, end, randNum, comp); 

  randquickSort(tempList,start,loc, comp); 
  randquickSort(tempList,loc+1,end, comp); 
}

template <class T, class Comparator>
void lastquickSort(vector<T>& tempList, int start, int end, Comparator comp) //QSort with last element as pivot
{
  if(start >= end) 
    return; 

  int loc = partition(tempList, start, end, end, comp); 

  lastquickSort(tempList,start,loc, comp); 
  lastquickSort(tempList,loc+1,end, comp); 
}




