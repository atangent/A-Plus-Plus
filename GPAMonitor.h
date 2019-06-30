#ifndef GPAMONITOR_H
#define GPAMONITOR_H

#include "Monitor.h"

class GPAMonitor : public Monitor
{
public:
  GPAMonitor(float);
  virtual void update(Student *); // If the student’s GPA is below minGPA creates a new log and adds it to the collection of logs

private:
  float minGPA; // Represents the minimum threshold for GPAs to be flagged
};

#endif
