#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "./Source/stack.h"
#include "./Source/map.h"
#include "./Source/stringint.h"
using namespace std;
#define ERROR_NUM -4569

int main (int argc, char* argv[])
{
  if (argc != 3) //Command line checks
  {
    cout << "Correct format: ./exe 'formula.txt' 'variable.txt'" << endl;
    return 0;
  }
  ifstream formFile(argv[1]);
  ifstream varFile (argv[2]);

  if (formFile.fail() || varFile.fail())
  {
    cout << "Could not open one of the files" << endl;
    return 0;
  }

  Map<long int, char> variable;
  long int key;
  char value;

  varFile >> key >> value; //Read in variable assignments
  while (!varFile.eof())
  {
    variable.add(key, value);
    varFile >> key >> value;
  }  
  
  string line;
  vector<string> formula;
  getline(formFile, line);
  while (!formFile.eof()) //Read in formulas
  {
    formula.push_back(line);
    getline(formFile, line);
  }

  Stack<Stringint> parse;
  int errorFlag;

  for (int k=0; k<(signed)formula.size(); k++)
  {
    errorFlag = 0;
    string temp = formula[k]; 
    for (int i=0; i<(signed)temp.length(); i++)
    {
      if (isspace(temp[i]))
        continue;
      if (!isdigit(temp[i])) //If character, insert character
      {
        Stringint inserted(temp[i]);
        parse.push(inserted);
      }
      if (isdigit(temp[i]))
      {
        stringstream number;
        number << temp[i];
        while (isdigit(temp[i+1])) //If still a number, keep going until non-number
        {
          ++i;
          number << temp[i];
        }
        long int insertNumber;
        number >> insertNumber; 

        if (variable.get(insertNumber) == 'T') //Match number with map
          insertNumber = 1;
        else if (variable.get(insertNumber) == 'F')
          insertNumber = 0;
        else
        {
          cout << "Error in variable assignment" << endl;
          return 0;
        }
        Stringint inserted(insertNumber);
        parse.push(inserted); 
      }   

      int tempCalc, productCalc;    
      bool calculated;
      int currentOp = 0; //1 for &, 2 for |

      if (parse.top().getChar() == ')') //Once a ) is reached, start popping
      {
        parse.pop();
        while (parse.top().getChar() != '(') //Until a ( is reached
        {
          tempCalc = parse.top().getInt(); //First number must be T/F
          parse.pop();

          if (parse.isEmpty()) //Check for extra ) at the end
          {
            cout << k << ". Malformed." << endl;
            errorFlag = ERROR_NUM;
            break;
          }

          if (parse.top().getChar() == '(')
          {
            parse.pop();
            break;
          }

          if (parse.top().getChar() != '&' && parse.top().getChar() != '|' && parse.top().getChar() != '~') //Next thing must be an operator
          {   
            cout << k << ". Malformed." << endl;
            errorFlag = ERROR_NUM;
            break;
          }

          if (parse.top().getChar() == '~') //If ~ is encountered, keep checking until no more ~
          {
            bool tildaTemp = tempCalc;
            if (tildaTemp == false)
              tildaTemp = true;
            else if (tildaTemp)
              tildaTemp = false;
            parse.pop();
            while (parse.top().getChar() == '~')
            {
              if (tildaTemp == false)
                tildaTemp = true;
              else if (tildaTemp)
                tildaTemp = false;
              parse.pop();
            }
            tempCalc = tildaTemp;
          }

          if (parse.top().getChar() == '&' || parse.top().getChar() == '|')
          {
            if (currentOp == 1 && parse.top().getChar() == '|') //Check for mixed operators
            {
              cout << k << ". Malformed. Mixed operator types." << endl;
              errorFlag = ERROR_NUM;
              break;
            }
            if (currentOp == 2 && parse.top().getChar() == '&')
            {
              cout << k << ". Malformed. Mixed operator types." << endl;
              errorFlag = ERROR_NUM;
              break;
            }
            if (parse.top().getChar() == '&')
              currentOp = 1;
            if (parse.top().getChar() == '|')
              currentOp = 2;

            parse.pop();
            if (parse.top().getInt() == ERROR_NUM) //Next item must be an integer. If not, malformed
            {
              cout << k << ". Malformed." << endl;
              errorFlag = ERROR_NUM;
              break;
            }
          
            productCalc = parse.top().getInt(); //Next thing must be a bool value
            parse.pop();

            if (parse.top().getChar() == '~') //If ~ is encountered, keep checking until no more ~
            {
              bool tildaTemp = productCalc;
              if (tildaTemp == false)
                tildaTemp = true;
              else if (tildaTemp)
                tildaTemp = false;
              parse.pop();
              while (parse.top().getChar() == '~')
              {
                if (tildaTemp == false)
                  tildaTemp = true;
                else if (tildaTemp)
                  tildaTemp = false;
                parse.pop();
              }
              productCalc = tildaTemp;
            }
	  
	    if (currentOp == 1)
              calculated = tempCalc & productCalc;

            if (currentOp == 2)
              calculated = tempCalc | productCalc;

            if (parse.top().getChar() == '(') //If end of statement, break out and continue adding
            {
              parse.pop();
              Stringint insertBool(calculated);
              parse.push(insertBool);
              break;
           }
            Stringint insertBool(calculated);
            parse.push(insertBool);            
          }
        }
      currentOp = 0;        
      if (errorFlag == ERROR_NUM) //Break out of for loop if an error was encountered
      {
        parse.clearStack();
        break;
      }
    }
  }

  if (errorFlag != ERROR_NUM)
  {
    bool tildaTemp = parse.top().getInt();
    parse.pop();
    while (!parse.isEmpty())
    {
      if (parse.top().getChar() == '~') //Check for extra ~
      {
        if (tildaTemp == false)
          tildaTemp = true;
        else if (tildaTemp)
          tildaTemp = false;
          parse.pop();
      }
      else
      {
        cout << k << ". Malformed. Extra items left in stack" << endl;
        break;
      }
    }
    if (parse.isEmpty())
    {
      if (tildaTemp == 1)      
        cout << k << ". This formula is true" << endl;      
      else if (tildaTemp == 0)
        cout << k << ". This formula is false" << endl;
    }
    else
      parse.clearStack();
   }
 }
}





