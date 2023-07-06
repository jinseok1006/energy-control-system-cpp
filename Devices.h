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
        nLights, []() -> Device * { return new Light(); }, "����");
    aircons = DeviceVector(
        nAirconditioners, []() -> Device * { return new AirConditioner(); },
        "������");
    equipments = DeviceVector(
        nEquipments, []() -> Device * { return new Equipment(); }, "�������");
    computers = DeviceVector(
        nComputers, []() -> Device * { return new Computer(); }, "��ǻ��");
    tvs = DeviceVector(
        nTvs, []() -> Device * { return new TV(); }, "TV");
  }

  int getConsumption() {
    // ��������� �����ϸ� ����Լ����� �ּҷ� ������ �Ұ�����(�ֱ׷��� ��)
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

  bool isDeviceExist(string name, int id) { // �������̽����� �ѹ� �ɷ��� ��
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
