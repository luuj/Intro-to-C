#ifndef STRING_INT
#define STRING_INT
#include <iostream>
#include <string>
using namespace std;

class Stringint
{
  public:
    Stringint(){} //Default constructor
    ~Stringint(){}  //Destructor
    Stringint(bool tempBool){ giveInt = tempBool; giveChar = '^';}
    Stringint(char tempString) : giveChar(tempString), giveInt(-4569) {}
    Stringint(int tempInt) : giveChar('^'), giveInt(tempInt) {}
    Stringint(long int tempInt) { giveInt = tempInt; giveChar = '^'; }
    
    char getChar() const { return giveChar; }
    long int getInt() const { return giveInt; }

  private:
    char giveChar;
    long int giveInt;

};

#endif
