#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

#include "Control.h"

Control::Control()
{
  GPAMonitor* gpaMon = new GPAMonitor(3.0);
  FWMonitor* fwMon = new FWMonitor(2);
  monitors.push_back(gpaMon);
  monitors.push_back(fwMon);

  vector<string> serverStudents;
  server.retrieve(serverStudents);

  stringstream ss;
  int id, coursecode, term, grade;
  string instructor;
  
  for (int i = 0; i < serverStudents.size(); i++) {
    ss.clear();
    ss.str(serverStudents[i]);
    ss >> id >> coursecode;
    Student* student = new Student(id);
    storage += student;

    while (coursecode != 0) {
      ss >> term >> grade >> instructor;
      Course* course = new Course(coursecode, term, grade, instructor);
      *student += course;
      ss >> coursecode;
    }
  }
}

Control::~Control()
{
  for (int i=0; i < monitors.size(); ++i) {
     monitors[i]->printLogs();
     delete monitors[i];
  }
}

void Control::launch()
{
  int numStu = 0;
  int menuSelection;
  Student* student;
  Course* course;

  while (1) {
    view.mainMenu(menuSelection);

    if (menuSelection == 0) 
      break;

    else if (menuSelection == 1) {
      int id;
      view.studentInfo(id);
      student = new Student(id);
      storage += student;
      numStu++;
      
      while (1) {
        int courseCode;
        int grade;
        int term;
        string instructor = "";
        view.courseInfo(courseCode, grade, term, instructor);
        
        if (instructor == "")
          break;

        course = new Course(courseCode, grade, term, instructor);
        *student += course;
      }
      
      notify(student);
    }
  }
  if (numStu > 0)
    view.print(&storage);
}

void Control::notify(Student* newStu)
{
  for (int i=0; i < monitors.size(); ++i) {
    monitors[i]->update(newStu);
  }
}