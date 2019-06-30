#ifndef VIEW_H
#define VIEW_H

#include "Storage.h"

class View {
  public:
    void mainMenu(int&); // Takes in user input for program control flow
    void studentInfo(int&); // Takes user input for student id
    void courseInfo(int&, int&, int&, string&); // Takes user input for course info
    void print(Storage*); // Calls print method in storage (prints out student info (including courses if any))

};

#endif