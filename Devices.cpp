#pragma once
#include "Devices.h"
using std::string;
using std::vector;

Devices::Devices(int nLights, int nAirconditioners, int nComputers, int nTvs,
                 int nEquipments) {
  // chatgpt�����Ͽ� �ۼ�
  // stl vector �����ڷ� �ʱ�ȭ �ϸ� ���� ���� ����� �ּҰ� ���� ������ �߻�
  // �ݹ� �Լ��� �����ϰ� �����ڿ��� �ݹ��Լ��� ȣ���Ͽ� ���Ϳ� ��ü�ּҸ�
  // �ִ°����� ó��
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

bool Devices::addDevice(string name) {
  vector<DeviceVector *> devices = {&lights, &aircons, &equipments, &computers,
                                    &tvs};
  // �����ϸ� true ��ȯ

  // �̸��� -> Ŭ������ ġȯ
  Device *device;
  if (name == "����")
    device = new Light();
  else if (name == "������")
    device = new AirConditioner();
  else if (name == "�������")
    device = new Equipment();
  else if (name == "��ǻ��")
    device = new Computer();
  else if (name == "TV")
    device = new TV();
  else
    return false;

  for (auto &deviceVector : devices) {
    if (deviceVector->getName() == name) {
      if(deviceVector->size()>9) return false;

      deviceVector->push_back(device);
      return true;
    }
  }
}

int Devices::getConsumption() {
  // ��������� �����ϸ� ����Լ����� �ּҷ� ������ �Ұ�����(�ֱ׷��� ��)
  vector<DeviceVector *> devices = {&lights, &aircons, &equipments, &computers,
                                    &tvs};
  int consumption = 0;

  for (const auto &deviceVector : devices) {
    for (const auto &device : *deviceVector) {
      if (device->getPower())
        consumption += device->getWatt();
    }
  }

  return consumption;
}

void Devices::show() {
  vector<DeviceVector *> devices = {&lights, &aircons, &equipments, &computers,
                                    &tvs};

  for (const auto &deviceVector : devices) {
    if (deviceVector->size())
      deviceVector->show();
  }
}

bool Devices::isDeviceExist(string name,
                            int id) { // id�� �������̽����� �ѹ� �ɷ��� ��
  vector<DeviceVector *> devices = {&lights, &aircons, &equipments, &computers,
                                    &tvs};
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

void Devices::setDeviceOnOff(string name, int id, bool value) {
  vector<DeviceVector *> devices = {&lights, &aircons, &equipments, &computers,
                                    &tvs};

  for (const auto &deviceVector : devices) {
    if (deviceVector->getName() == name) {
      (*deviceVector)[id]->setPower(value);
    }
  }
}
