#include "Course.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

template <class T>
class List
{
  class Node
  {
    friend class List;
    private:
      Course* data;
      Node* next;
  };

    public:
      List();
      ~List(); // clean up the dynamically allocated memory (deletes everything in list)
      List<T>& operator+=(T*); // adds a course object pointer to the list
      void print(); // prints all the data for each node in the list
      float computeGPA(); // calculates the gpa of the student function is called on
      int computeNumFW(); // calculates the number of failed/withdrawn courses of the student function is called on


  private:
    Node* head;
    Node* tail;

};

template <class T>
List<T>::List() : head(0), tail(0) {}

template <class T>
List<T>::~List()
{
  Node* currNode;
  Node* nextNode;

  currNode = head;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

template <class T>
List<T>& List<T>::operator+=(T *course) 
{
  Node* tmpNode;
  Node* currNode = head;
  Node* prevNode = NULL;

  tmpNode = new Node;
  tmpNode->data = course;
  tmpNode->next = 0;

  while (currNode != NULL) {
    if (course->lessThan(currNode->data))
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL) {
    head = tmpNode;
  } else {
    prevNode->next = tmpNode;
  }

  tmpNode->next  = currNode;
  if (currNode == NULL) tail = tmpNode;
}

template <class T>
void List<T>::print()
{
  Node* currNode = head;

  while (currNode != NULL) {
    currNode->data->print();
    currNode = currNode->next;
  }

  // cout << "----------" << endl;
  // if (head != NULL) {
  //   cout << "head: ";
  //   head->data->print();
  //   cout << "tail: ";
  //   tail->data->print();
  // }
}

template <class T>
float List<T>::computeGPA()
{
  float courseNum = 0;
  float totalGrade = 0;
  Node* currNode = head;

  while (currNode != NULL) {
    if (currNode->data->getGrade() > 0) {
      totalGrade += currNode->data->getGrade();
      courseNum++;
    }
    currNode = currNode->next;
  }

  if (courseNum == 0) {
    return 0.0;
  } else {
    return float(totalGrade/courseNum);
  }
}

template <class T>
int List<T>::computeNumFW()
{
  int numFW = 0;
  Node* currNode = head;

  while (currNode != NULL) {
    int grade = currNode->data->getGrade();
    if (grade == 0 || grade == -1) {
      numFW++;
    }
    currNode = currNode->next;
  }

  return numFW;
}