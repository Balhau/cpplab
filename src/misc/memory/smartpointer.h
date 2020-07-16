#pragma once

#include <iostream>

class DummyObject {
  public:
  DummyObject(int);                  //Constructor
  ~DummyObject();                         //destructor
  DummyObject(const DummyObject&);  //copy constructor
  DummyObject(DummyObject&&); //move constructor

  void doSomething();


  private:
  int size;
  int* list_of_numbers;

};