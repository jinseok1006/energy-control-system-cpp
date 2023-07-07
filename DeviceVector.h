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

inline bool random() { return rand() % 10 > 6; }

class DeviceVector : public vector<Device *> {
  string name;

public:
  DeviceVector() : vector<Device *>() {}
  DeviceVector(int size, function<Device *()> newDevice, string name);
  void show() const;

  void setRandom();

  string getName() const { return name; }
};
