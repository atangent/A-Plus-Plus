#ifndef FWMONITOR_H
#define FWMONITOR_H

#include "Monitor.h"

class FWMonitor : public Monitor
{
  public:
    FWMonitor(int);
    virtual void update(Student*); // If the student’s FW course is above maxFW creates a new log and adds it to the collection of logs

  private:
    int maxFW;
};

#endif
