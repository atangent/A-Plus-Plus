#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Storage.h"

Storage::Storage() : curStudents(0) {}

Storage::~Storage() 
{
  for (int i = 0; i < curStudents; i++) {
    delete students[i];
  }
}

void Storage::operator+=(Student *student)
{
  if (curStudents <= MAX_NUM_STU) {
    students[curStudents] = student;
    curStudents++;
  }
}

void Storage::print()
{
  cout << endl << endl << "STUDENT INFO: " << endl;

  for (int i=0; i<curStudents; ++i)
    students[i]->print();

  cout << endl;
}
