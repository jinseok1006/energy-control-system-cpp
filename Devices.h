#pragma once
#include "DeviceVector.h";
#include <string>
using std::string;
using std::vector;

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
    // chatgpt참조하여 작성
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

  // 이름을 -> 클래스로 치환
  // 성공하면 true 반환
  bool addDevice(string name) {
    vector<DeviceVector *> devices = {&lights, &aircons, &equipments,
                                      &computers, &tvs};

    Device *device;
    if (name == "조명")
      device = new Light();
    else if (name == "에어컨")
      device = new AirConditioner();
    else if (name == "실험장비")
      device = new Equipment();
    else if (name == "컴퓨터")
      device = new Computer();
    else if (name == "TV")
      device = new TV();
    else
      return false;

    // 벡터는 항상 존재하는데?
    /*if (!isVectorExist(name))
      return false;*/

    for (auto &deviceVector : devices) {
      if (deviceVector->getName() == name) {
        deviceVector->push_back(device);
        return true;
      }
    }
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
