#include <iostream>
#include <fstream>
#include "map.h"
#include <stdexcept>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    cout << "Please enter in a txt file name" << endl;
    return 0;
  }
  
  ifstream ifile (argv[1]);
  if (ifile.fail())
  {
    cout << "Can't open file" << endl;
    return 0;
  }

  string buffer, email, fname, lname;
  Map<string, string> look;

  while (1)
  {
    getline(ifile, buffer);
    stringstream push(buffer);
    if (buffer.empty()) //Stop at end of file
      break;

    push >> email >> fname >> lname;
    fname = fname + " " + lname;
    look.add(email, fname);
  }
  
  while (1)
  {
    cout << "Please enter in a key" << endl;
    cin >> buffer;
    
    if (buffer == ".") //End program
      return 0;

    try
    {
      cout << look.get(buffer) << endl;;
    }
    catch (const invalid_argument& ia)
    {
      cout << "No email was found in the data base" << endl;
    }
  }

}
