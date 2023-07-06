#pragma once
#include "Device.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

inline bool random() { return rand() % 10 > 3; }

class DeviceVector : public vector<Device *> {
  string name;

public:
  DeviceVector() : vector<Device *>() {}
  DeviceVector(int n, Device *object, string name)
      : vector<Device *>(n, object), name(name) {
    setRandom(); // �� ����̽��� ����/���� ���¸� �������� ����
  }
  void show() const {
    for (int i = 0; i < this->size(); i++)
      cout << name << (i + 1) << "\t";

    cout << '\n';

    for (int i = 0; i < this->size(); i++)
      cout << (*this)[i]->getOnString() << "\t";
    cout << "\n\n";
  }

  void setRandom() {
    for (auto &device : *this) {
      device->setOn(random());
    }
  }
};
