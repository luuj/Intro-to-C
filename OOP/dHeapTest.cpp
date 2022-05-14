#include <iostream>
#include <cstdlib>
#include <ctime>
#include "dHeap.h"
using namespace std;

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

int main(int argc, char* argv[])
{
  if (argc != 2)
    return 0;

  numberCompare numComp;
  MaxHeap<int, numberCompare> temp(atoi(argv[1]), numComp);
  clock_t stime, etime;
  stime = clock();
  for (int i=0; i<100000; i++) //Insert 10000 random numbers from 1 and 50000
  {
    int randomNum = rand() % 50000 + 1;   
    temp.add(randomNum); 
  } 
  for (int i=0; i<100000; i++)
    temp.remove();

  etime = clock();
  stime = etime - stime;
  cout << "Time: " << stime << endl;

  return 0;
}


