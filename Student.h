#ifndef STUDENT_H
#define STUDENT_H

#include "defs.h"
#include "List.h"

class Student
{
  public:
    Student(int=0);
    void operator+=(Course*); // Adds a course to list of courses the student is taking
    void print(); // Prints out student info (including courses if any)
    float computeGPA();
    int computeNumFW();
    int getId(); // getter method for student id

  private:
    int    id; // numeric id for student
    List<Course> courses; // List of courses belonging to each student
};

#endif
