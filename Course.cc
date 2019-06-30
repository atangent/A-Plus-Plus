#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Course.h"

Course::Course(int c, int g, int t, string i) : code(c), grade(g), term(t), instructor(i) {}

bool Course::lessThan(Course* course)
{
  if (this->code < course->code) {
    return true;
  } else if (this->code == course->code){
      if (this->term < course->term)
        return true;
  }
  return false;
}

void Course::print()
{
  string str;

  cout << "-- COMP " << code << ":  ";
  cout << right << setw(2) << grade   << "  ";
  getGradeStr(str);
  cout << left << setw(3) << str << endl;
  cout << "\tInstructor: " << instructor << endl;
  cout << "\tTerm: " << term << endl; 
}

void Course::getGradeStr(string& gradeStr)
{
  string gradeStrings[] = {
    "WDN", "F", "D-", "D", "D+", "C-", "C", "C+", 
    "B-", "B", "B+", "A-", "A", "A+" };

  if ( grade >= -1 && grade <= 12 )
    gradeStr = gradeStrings[grade+1];
  else
    gradeStr = "Unknown";
}

int Course::getGrade()
{
  return grade;
}
