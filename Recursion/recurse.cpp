#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;

void recurse(string, int, string[], int);

int main (int argc, char* argv[])
{
  string text = argv[1];
  string number = argv[2];
  int n = atoi(number.c_str()); //Convert into int
  int len = text.length();

  if (n == 0)
  {
    cout << "No possible permutations" << endl;
    return 0;
  }

  if (n == 1)
  {
    for (int i=0; i<len; i++) //Print out separated string
      cout << text[i] << endl;
    return 0;
  }

  int total = pow(len,n);
  string* list = new string[total]; //Total number of elements possible

  for (int i=0; i<len; i++)
  {
    list[i] = text[i];
  }
  
  recurse(text, n, list, 1);
  delete [] list;
}

void recurse(string t, int n, string list[], int count)
{
  int length = t.length();
  
  if (count == n) //Once base case is reached, print out all the elements found in array
  {
    int total = pow(length,n);
    for (int k=0; k<total; k++)
      cout << list[k] << endl;
    return;
  }

  int counter = pow(length,n+count);
  int count2 = 0;
  string templist[counter];
  counter = pow(length,count);

  for (int i=0; i<length; i++)
  {
    for (int j=0; j<counter; j++)
    {
      string temp = t[i] + list[j];
      templist[count2] = temp;
      count2++;
    }
  }
  
  count++; 
  recurse(t, n, templist, count); 

}




