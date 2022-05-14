// speed_test.cpp
#include <iostream>
#include <ctime>
// you may need more libraries

// list definitions
#include "./Source/ilist.h"
#include "./Assortedlists/LinkedList.h"
#include "./Source/arraylist.h"
#include "./Assortedlists/plusonearraylist.h"
#include "./Assortedlists/plustenarraylist.h"
#include "./Assortedlists/doublingarraylist.h"

using namespace std;

double MeasureFrontInsertTime(IList<int> * list, int insertCount = 50000)
{
    double time = 0.0;
    // time measurement code goes here
    time = clock();

    for(int i = 0; i < insertCount; ++i) list->insert(0, i);
    time = clock() - time;
    return time;
}

double MeasureBackInsertTime(IList<int> * list, int insertCount = 50000)
{
    double time = 0.0;
    // time measurement code goes here
    time = clock();

    for(int i = 0; i < insertCount; ++i) list->insert(i, i);
    time = clock() - time;
    return time;
}

int main()
{
    double frontTime = 0.0, backTime = 0.0;
    IList<int> ** lists = new IList<int>*[8];

    // feel free to pass some argument to your constructor or just leave it to the default constructor
    lists[0] = new LinkedList<int>;          // front insert
    lists[1] = new LinkedList<int>;          // back  insert
    lists[2] = new PlusOneArrayList<int>;    // front insert
    lists[3] = new PlusOneArrayList<int>;    // back  insert
    lists[4] = new PlusTenArrayList<int>;    // front insert
    lists[5] = new PlusTenArrayList<int>;    // back  insert
    lists[6] = new DoublingArrayList<int>;   // front insert
    lists[7] = new DoublingArrayList<int>;   // back  insert

    for (int i = 0; i < 8; i += 2)
    {
        frontTime = MeasureFrontInsertTime(lists[i]);
        backTime  = MeasureBackInsertTime (lists[i + 1]);

        // cout the duration in seconds
        cout << "Front time: " << frontTime << endl;
        cout << "Back time: " << backTime << endl;

        // release: you can optionally measure delete (removing all items) duration
        delete lists[i];
        delete lists[i + 1];
    }
    delete [] lists;
    return 0;
}
