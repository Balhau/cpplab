#include "smartpointer.h"
#include <memory>

#define UPtr std::unique_ptr
#define SPtr std::shared_ptr

DummyObject::DummyObject(int num_elements)
{
  std::cout << "Constructor called " << num_elements << std::endl;
  size = num_elements;
  list_of_numbers = new int[size];
}

DummyObject::~DummyObject()
{
  std::cout << "Destructor called " << size << std::endl;
  delete[] list_of_numbers;
}

DummyObject::DummyObject(const DummyObject &other)
{
  std::cout << "Copy constructor called " << other.size << std::endl;
  list_of_numbers = new int[other.size];
  for (int i = 0; i < other.size; i++)
  {
    list_of_numbers[i] = other.list_of_numbers[i];
  }
  size = other.size;
}

DummyObject::DummyObject(DummyObject&& moved)
{
  std::cout << "Move constructor called " << moved.size << std::endl;
}

void DummyObject::doSomething()
{
  std::cout << "This do amazing stuff: " << size << std::endl;
}

DummyObject createDummy(int size)
{
  DummyObject d(size);
  return d;
}

int main(void)
{
  std::cout << "Smart pointer examples" << std::endl;

  DummyObject d(15);
  DummyObject copy = d;

  DummyObject *dmtPtr = new DummyObject(20);
  UPtr<DummyObject> dmySmtPtr = UPtr<DummyObject>(new DummyObject(30));

  dmySmtPtr->doSomething();
  dmtPtr->doSomething();

  SPtr<DummyObject> firstSmtPtr = SPtr<DummyObject>(dmtPtr);
  SPtr<DummyObject> secondSmtPtr = firstSmtPtr;

  DummyObject retDummy = createDummy(32);
  DummyObject secondDummy = std::move(retDummy);

  retDummy.doSomething();
  secondDummy.doSomething();

  firstSmtPtr->doSomething();
  secondSmtPtr->doSomething();
}