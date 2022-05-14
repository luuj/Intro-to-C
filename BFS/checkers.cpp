#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cmath>
using namespace std;

struct Item{
  int val;
  Item* next;
};

void append (Item*& head, int x)
{
  Item* point = new Item;
  point->val = x;
  point->next = NULL;
  
  if (head == NULL)
  {
    head = point; //Create new object at front
  }
  else
  {
    Item* temp = head;
    while (temp->next) //Iterate until NULL ptr is reached
    {
      temp = temp->next;
    }
    temp->next = point; //Adds new item to the list
  }
}

bool isEven (int n)
{
  if (!(n%2))
    return true;
  else
    return false;
}

bool isSquare (int c)
{
  double temp = c, temp2;
  temp2 = sqrt(temp);

  if (fmod(temp2, 1)) //Check if there is a decimal at the end after square rooting it
    return false;
  else
    return true;
}

bool isPrime (int y)
{
  int x = abs(y);
  for (int i=2; i< (x-1); i++)
  {
    if ( (x%i) == 0)
      return false;
  }

  if (x == 0 || x == 1)
    return false;
  else
    return true;
}

Item* filter(Item *head, bool (*f)(int), Item* nH)
{
  if (head->next == NULL)
  { 
   append (nH, 0);
   return nH;
  }
  else
  {
    if (f(head->val) == false)
      filter(head->next, f, nH);
    else
    {
      append (nH, head->val);
      filter(head->next, f, nH);
    }
  }
    
}

int main (int argc, char* argv[])
{
  ifstream input(argv[1]);
  string choice = argv[2];
  int number;

  Item* head = NULL;

  while (!input.fail())
  {
    input >> number;
    append (head, number);
  } 

  Item* newHead;
  Item* nH = NULL;

  if (choice == "A" || choice == "a")
    newHead = filter(head, isEven, nH);   
  else if (choice == "B" || choice == "b")
    newHead = filter(head, isSquare, nH);
  else if (choice == "C" || choice == "c")
    newHead = filter(head, isPrime, nH);
  else
    cout << "Please enter in A, B, or C in the command line" << endl;

  Item* temp = newHead; //Print out filtered list
  while (temp->next)
  {
    cout << temp->val << endl;
    temp = temp->next;
  }
}

