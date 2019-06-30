#ifndef CONTROL_H
#define CONTROL_H

#include <vector>
#include "Storage.h"
#include "View.h"
#include "Monitor.h"
#include "GPAMonitor.h"
#include "FWMonitor.h"
#include "StuServer.h"

class Control
{
  public:
    Control();
    ~Control(); // loops over monitors and calls printLogs() and deallocates the memory for the monitor objects
    void launch(); // main function that implements the program control flow
    void notify(Student*); // loops over monitors and calls update() function on each monitor object

  private:
    Storage storage; // Stores an array of students and number of students
    View view; // View object reads in student and course information
    vector<Monitor*> monitors; // A collection of Monitor object pointers
    StuServer server;
};

#endif