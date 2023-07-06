#pragma once
#include <iostream>
#include <vector>
#include<string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

template <typename T> class MyVector : public vector<T> {
  string name;

public:
  MyVector() : vector<T>() {}
  MyVector(int n, T object, string name) : vector<T>(n, object), name(name) {}
  void show() const {
    for (int i = 0; i < this->size(); i++)
      cout << name << (i + 1) << "\t";

    cout << '\n';

    for (int i = 0; i < this->size(); i++)
      cout << (*this)[i].getOnString() << "\t";
    cout << "\n\n";
  }
  void setOn(int id, bool value) { (*this)[id].setOn(value); }
};