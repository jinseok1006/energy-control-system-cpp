#pragma once
#include "Device.h"
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::function;
using std::string;
using std::vector;

inline bool random() { return rand() % 10 > 3; }

class DeviceVector : public vector<Device *> {
  string name;

public:
  DeviceVector() : vector<Device *>() {}
  DeviceVector(int size, function<Device *()> newDevice, string name)
      : vector<Device *>(size, nullptr), name(name) {

    for (auto &device : *this) {
      device = newDevice();
    }

    setRandom(); // 각 디바이스의 꺼짐/켜짐 상태를 랜덤으로 결정
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
      device->setOnOff(random());
    }
  }

  string getName() const { return name; }
};
