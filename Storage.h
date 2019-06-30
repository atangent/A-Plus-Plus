#ifndef STORAGE_H
#define STORAGE_H

#include "defs.h"
#include "Student.h"

class Storage
{
  public:
    Storage();
    ~Storage(); // Deallocates the memory for students objects in array
    void operator+=(Student*); // Adds a student pointer to the array
    void print(); // Prints out student info (including courses if any)

  private:
    Student* students[MAX_NUM_STU]; // Stores student pointers in an array
    int curStudents; // Amount of students in storage
};

#endif