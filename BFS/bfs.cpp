#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

void abstract(string* border, int r, int c, char storage[][15]);
void color (char storage[][15], int* colored, int i, int count, int total);

int main(int argc, char* argv[])
{
  if (argc == 1 || argc > 2){
    cout << "Please enter in one file name" << endl;
    return 0;
  }
  //Error testing 
  ifstream input (argv[1]);

  if (input.fail()){
    cout << "Could not open file" << endl;
    return 0;
  }

  int cNum, row, col;
  input >> cNum >> row >> col;

  string border[row];

  for (int i=0; i<row; i++) //Read in map
    input >> border[i];

  char storage[cNum][15];
  for (int i=0; i<cNum; i++) //Initialize values in array
  {
    for (int k=0; k<15; k++)
    {
      storage[i][k] = -1;
    }
  }

  abstract(border, row, col, storage);

  int colored[cNum];
  colored[cNum-1] = -1;

  color(storage, colored, 1, 0, cNum-1);


  for (int i=0; i<cNum; i++)
  {
    cout << (char)(i+65) << ": " << colored[i] << endl;
  }


}

void abstract(string* border, int r, int c, char storage[][15])
{
  for (int i=0; i<r; i++)
  {
    for (int k=0; k<c; k++)
    {
      if (k < (c-1) && i < r)
      {
        if (border[i][k] != border[i][k+1]) //Checking left
        {
          storage[(border[i][k])-65][(border[i][k+1])-65] = border[i][k+1];
          storage[(border[i][k+1])-65][(border[i][k])-65] = border[i][k];
        }
      } 
      if (k < c && i < (r-1)) //Checking below
      {
        if (border[i][k] != border[i+1][k])
        {
          storage[border[i][k]-65][border[i+1][k]-65] = border[i+1][k];
          storage[border[i+1][k]-65][border[i][k]-65] = border[i][k];	
        } 
      }   
    }
  }
}

void color (char storage[][15], int* colored, int num, int count, int total)
{

  colored[count] = num;

  if (num > 4)
  {
    count--;
    if (++colored[count] >4)
    {
      count--;
    }
    if (count == 0 && num == 4)
    {
      cout << "No solution could be found" << endl;
      return;
    }
    return color(storage, colored, ++colored[count], count, total); 
  }


  for (int i=0; i<15; i++)
  {
    if (storage[count][i] == -1)
      continue;

    if (colored[count] == colored[(storage[count][i]) - 65] )
    {
      return color(storage, colored, ++num, count, total);
    }
  }

  if (colored[total] != -1 && colored[total] < 5)
    return;

  return color(storage, colored, 1, ++count, total);
}







