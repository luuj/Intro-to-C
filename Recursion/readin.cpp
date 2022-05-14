#include <iostream>
#include <fstream> //File IO
#include <string>
#include <sstream> //Using stringstream
using namespace std;

int main(int argc, char* argv[])
{
	string buffer;

	ifstream inputText(argv[1]);
	int linecount, charcount;

	inputText >> linecount;
	getline(inputText, buffer); //Skip to next line

	int *countArr = new int[linecount];

	for (int i = 0; i < linecount; i++)
	{
		getline(inputText, buffer);

		stringstream count(buffer);
		while (1)
		{
			string temp;
			count >> temp;

			if (count.fail())
				break;

			charcount++;
		}
		countArr[i] = charcount;
		charcount = 0;
	}

	for (int i = 0; i < linecount; i++)
	{
		cout << countArr[linecount - i - 1] << endl;
	}

	delete[] countArr;

}

