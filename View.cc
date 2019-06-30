#include <iostream>
#include <iomanip>
using namespace std;

#include "View.h"

void View::mainMenu(int &selection)
{
  int numOptions = 1;
  selection = -1;

  cout << endl;
  cout << "(1) Add student" << endl;
  cout << "(0) Exit" << endl;

  while (selection < 0 || selection > numOptions) {
    cout << "Enter your selection: ";
    cin  >> selection;
  }
}

void View::studentInfo(int &id)
{
  cout << "student id:   ";
  cin  >> id;
}

void View::courseInfo(int &courseCode, int &grade, int &term, string &instructor)
{
  cout << "course code <0 to end>:  ";
  cin  >> courseCode;
  if (courseCode == 0)
    return;
  cout << "grade:                   ";
  cin  >> grade;
  cout << "term:                    ";
  cin  >> term;
  cout << "instructor:              ";
  getline(cin >> ws, instructor);
}

void View::print(Storage* storage) 
{
  storage->print();
}