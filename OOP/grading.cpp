#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "quicksort.h"
using namespace std;

struct Student{
  string name;
  int grade;
  int originalP;
};

struct studentComp //Comparator for students
{ 
  bool operator()(const Student& lhs, const Student& rhs)
  {
    if (lhs.grade <= rhs.grade)
      return true;
    else
      return false;
  }
};

struct placeComp //Comparator for student placement
{ 
  bool operator()(const Student& lhs, const Student& rhs)
  {
    if (lhs.originalP <= rhs.originalP)
      return true;
    else
      return false;
  }
};

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    cout << "Please enter in an input file and an output file name" << endl;
    return 0;
  }

  ifstream inFile(argv[1]);
  if (inFile.fail())
  {
    cout << "Could not open file" << endl;
    return 0;
  }

  int numStudents, grade;
  string name;
  vector<int> propGrade; //Proposed grades to give to students
  vector<Student> studentList;
  
  inFile >> numStudents; //Number of students in class
  for (int i=0; i<numStudents; i++) //Add name and grade to student item ; n run time
  {
    inFile >> name >> grade;
    Student temp;
    temp.name = name;
    temp.grade = grade;
    temp.originalP = i;
    studentList.push_back(temp);
  }

  for (int i=0; i<numStudents; i++) //Proposed grades to students ; n run time
  {
    inFile >> grade;
    propGrade.push_back(grade);
  }

  numberCompare numComp;
  studentComp stuComp;

  randquickSort(propGrade, 0, propGrade.size()-1, numComp); //Quicksort nlogn time
  randquickSort(studentList, 0, studentList.size()-1, stuComp); //Quicksort nlogn time

  ofstream outFile(argv[2]);
  bool failFlag = false;

  for (int i=0; i<numStudents; i++) //Give each student corresponding grade ; n run time
  {
    if (studentList[i].grade <= propGrade[i]) //If student's grade is equal to or lower than proposed grade, give grade
    {
      studentList[i].grade = propGrade[i];
    }
    else
    {
      outFile << "This is impossible"; 
      failFlag = true;
      break;
    }
  }

  placeComp pComp;
  randquickSort(studentList, 0, studentList.size()-1, pComp); //Reorder original positions ; nlogn time

  if (failFlag == false) //Write out to file, n run time
  {
    for (int i=0; i<(signed)studentList.size(); i++)
      outFile << studentList[i].name << " " << studentList[i].grade << "\n";
  }

  //n + n + nlogn + nlogn + n + nlogn + n = 4n + 3nlogn = O(nlogn) run time
}

