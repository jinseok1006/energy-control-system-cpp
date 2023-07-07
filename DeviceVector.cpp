#pragma once
#include "DeviceVector.h"

using std::cout;
using std::endl;
using std::function;
using std::string;
using std::vector;

DeviceVector::DeviceVector(int size, function<Device *()> newDevice,
                           string name)
    : vector<Device *>(size, nullptr), name(name) {

  for (auto &device : *this) {
    device = newDevice();
  }

  setRandom(); // 각 디바이스의 꺼짐/켜짐 상태를 랜덤으로 결정
}
void DeviceVector::show() const {
  for (int i = 0; i < this->size(); i++)
    cout << name << (i + 1) << "\t";

  cout << '\n';

  for (int i = 0; i < this->size(); i++)
    cout << (*this)[i]->getOnString() << "\t";
  cout << "\n\n";
}

void DeviceVector::setRandom() {
  for (auto &device : *this) {
    device->setPower(random());
  }
}
