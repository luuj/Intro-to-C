#include <iostream>
#include "P3.h"
using namespace std;

int main()
{
  List<int> test;
  test.insert(0, 5);
test.print();
  test.insert(1, 4);
test.print();
  test.insert(1, 3);
test.print();
  test.insert(1,7);
test.print();
test.insert(2, 9);
test.print();
  test.insert(0,11);
test.print();
  test.set (2, 92);
  test.set(4,91);
test.print();
 cout << test.get(0)<< test.get(1);


}
