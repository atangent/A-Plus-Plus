#ifndef MONITOR_H
#define MONITOR_H

#include <vector>
#include "Student.h"

class Monitor
{
  public:
    virtual ~Monitor(); // virtual destructor
    virtual void update(Student*) = 0; // pure virtual function
    void printLogs(); // Prints the collection of logs to the screen

  protected:
    vector<string> logs; // Stores a collection of logs

};

#endif
