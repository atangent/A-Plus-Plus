#ifndef COURSE_H
#define COURSE_H

class Course
{
  public:
    Course(int=0, int=0, int=0, string="");
    bool lessThan(Course*); // Compares course code and term, returns true if course function is called on is less than the one passed in
    void print(); // prints out all course information
    void getGradeStr(string&); // changes numeric grade to string representation
    int getGrade();

  private:
    int code;	// course code, for example 2404 for COMP2404
    int grade;	// numeric grade from 0 (F) to 12 (A+), with -1 for WDN
    int term;   // numeric representation for term, 4 numbers for year and 2 represeting the term 
    string instructor; // name of instructor
};

#endif
