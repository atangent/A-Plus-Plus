#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "FWMonitor.h"

FWMonitor::FWMonitor(int m) : maxFW(m) {}

void FWMonitor::update(Student* stu) 
{
  if (stu->computeNumFW() > maxFW) {
    logs.push_back(to_string(stu->getId()) + " - FW: " + to_string(stu->computeNumFW()));
  }
}