#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Student.h"

Student::Student(int i) : id(i) {}

void Student::operator+=(Course *course) 
{
  courses += course;
}

void Student::print()
{
  cout<< endl << "Id: " << id << endl;
  courses.print();
  if (computeGPA() != 0.0) {
    cout << "GPA: " << computeGPA() << endl;
  }
}

float Student::computeGPA()
{
  return courses.computeGPA();
}

int Student::computeNumFW()
{
  return courses.computeNumFW();
}

int Student::getId()
{
  return id;
}