#pragma once
#include"DeviceVector.h";
#include<string>
using std::vector;
using std::string;

class Devices {
  DeviceVector lights;
  DeviceVector computers;
  DeviceVector equipments;
  DeviceVector aircons;
  DeviceVector tvs;

public:
  Devices() = default;
  Devices(int nLights, int nAirconditioners, int nComputers, int nTvs,
          int nEquipments) {
    lights = DeviceVector(
        nLights, []() -> Device * { return new Light(); }, "조명");
    aircons = DeviceVector(
        nAirconditioners, []() -> Device * { return new AirConditioner(); },
        "에어컨");
    equipments = DeviceVector(
        nEquipments, []() -> Device * { return new Equipment(); }, "실험장비");
    computers = DeviceVector(
        nComputers, []() -> Device * { return new Computer(); }, "컴퓨터");
    tvs = DeviceVector(
        nTvs, []() -> Device * { return new TV(); }, "TV");
  }

  int getConsumption() {
    // 멤버변수로 설정하면 멤버함수에서 주소로 참조가 불가능함(왜그런지 모름)
    vector<DeviceVector *> devices = {&lights, &aircons, &equipments,
                                      &computers, &tvs};
    int consumption = 0;

    for (const auto &deviceVector : devices) {
      for (const auto &device : *deviceVector) {
        if (device->getOnOff())
          consumption += device->getWatt();
      }
    }

    return consumption;
  }

  void show() {
    vector<DeviceVector *> devices = {&lights, &aircons, &equipments,
                                      &computers, &tvs};

    for (const auto &deviceVector : devices) {
      if (deviceVector->size())
        deviceVector->show();
    }
  }

  bool isDeviceExist(string name, int id) { // 인터페이스에서 한번 걸러진 값
    vector<DeviceVector *> devices = {&lights, &aircons, &equipments,
                                      &computers, &tvs};
    if (id < 0)
      return false;

    for (const auto &deviceVector : devices) {
      if (deviceVector->getName() == name) {
        if (id < deviceVector->size())
          return true;
        else
          return false;
      }
    }

    return false;
  }

  void setDeviceOnOff(string name, int id, bool value) {
    vector<DeviceVector *> devices = {&lights, &aircons, &equipments,
                                      &computers, &tvs};

    for (const auto &deviceVector : devices) {
      if (deviceVector->getName() == name) {
        (*deviceVector)[id]->setOnOff(value);
      }
    }
  }
};
