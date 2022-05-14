#include <iostream>
#include "./Source/arraylist.h"
#include "./Assortedlists/plusonearraylist.h"
#include "./Assortedlists/plustenarraylist.h"
#include "./Assortedlists/doublingarraylist.h"

using namespace std;

int main()
{
  cout << "Doubling array: " << endl;
  DoublingArrayList<int> test; //Initial size is 10
  test.insert(0, 3);
  test.insert(1, 9);
  test.insert(1, 102);
  test.insert(3,104);
  test.insert(4,105);
  test.insert(5, 55);
  test.insert(5, 55);
  test.insert(6, 92);
  test.insert(7, 94);
  test.insert(8, 96);

  test.remove(7);
  test.remove(2);
  test.remove(4);

  //test.insert(10,92); //Cannot insert, out of range
  //test.remove(9); //Cannot remove, out of range
  test.print();
  for (int i=0; i<12; i++) //Doubles size to 20
    test.insert(3, 12);
  test.print();
  for (int i=0; i<12; i++) //Doubles size to 40
    test.insert(3,14);
  test.print();

  cout << "\nPlus one array: " << endl;
  PlusOneArrayList<int> test2;
  test2.insert(0, 2);
  test2.insert(1,4);
  test2.insert(2,5);
  test2.set(1,9); //Set value
  test2.print(); 
  for (int i=0; i<9; i++)
    test2.insert(3, 14);
  test2.print();
  test2.insert(12, 15);
  test2.print(); //Incrementing by one

  cout << "\nPlus ten array: " << endl;
  PlusTenArrayList<int> test3;
  test3.insert(0, 12);
  test3.print();
  for (int i=0; i<12; i++)
    test3.insert(0, 14);
  test3.print();
  for (int i=0; i<9; i++)
    test3.insert(8, 99);
  test3.print(); //Incrementing by ten

  cout << "\nNormal arraylist using double: " << endl;
  arrayList<int> test4;
  test4.insert(0, 12);
  test4.print();
  for (int i=0; i<12; i++)
    test4.insert(0,19);
  test4.print();
  for (int i=0; i<9; i++)
    test4.insert(4,62);
  test4.print();
}
