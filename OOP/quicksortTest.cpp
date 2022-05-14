#include "quicksort.h"
#include <ctime>
using namespace std;

int main (int argc, char* argv[])
{
  if (argc !=2)
  {
    cout << "Please enter in t-mixed value of T" << endl;
    return 0;
  }

  srand(time(0));
  vector<int> randArray;
  fillArray(randArray, 10000); //Insert 10000 elements into array
  swapContents(randArray, atoi(argv[1]));

  double time = 0.0;
  vector<int> repeatArray = randArray;
  time = clock();

  numberCompare num;
  for (int i=0; i<30; i++) //Repeat 30 times
  {
    randArray = repeatArray;
    randquickSort(randArray, 0, (unsigned)randArray.size()-1, num);
  }

  time = clock() - time;
  cout << "Average time: " << time/30 << endl;

  return 0;
}

