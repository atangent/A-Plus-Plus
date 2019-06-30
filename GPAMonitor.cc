#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "GPAMonitor.h"

GPAMonitor::GPAMonitor(float m) : minGPA(m) {}

void GPAMonitor::update(Student* stu) 
{
  if (stu->computeGPA() < minGPA) {
    logs.push_back(to_string(stu->getId()) + " - GPA: " + to_string(stu->computeGPA()));
  }
}