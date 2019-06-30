#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Monitor.h"

Monitor::~Monitor() {}

void Monitor::printLogs() 
{
  for (int i = 0; i < logs.size(); i++) {
    cout << "Student " << logs[i] << endl;
  }
}