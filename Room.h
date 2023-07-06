#pragma once
#include "Device.h"
#include "DeviceVector.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Room {
public:
  const static int COMPUTER_ROOM = 0;
  const static int LABORATORY = 1;
  const static int LECTURE_ROOM = 2;

protected:
  string name;
  int number;
  double currentWatt;
  DeviceVector aircons;
  DeviceVector lights;

  Room(string name, int number) : name(name), number(number), currentWatt(0) {}

public:
  void inspect() {
    double currentWatt = measureCurrentWh();
    this->currentWatt = currentWatt;
  }

  virtual double measureCurrentWh() const {
    double currentWatt = 0;

    for (const auto &light : lights) {
      if (light->getOn()) {
        currentWatt += light->getWatt();
      }
    }

    for (const auto &aircon : aircons) {
      if (aircon->getOn()) {
        currentWatt += aircon->getWatt();
      }
    }
    return currentWatt;
  }

  double getCurrentWh() const { return currentWatt; }
  virtual bool controlDevice(string name, int id, bool value) = 0;
  void showName() { cout << number << "ȣ " << name; }
  void showCurrentWatt() { cout << "�Һ� ����:" << currentWatt; }

  virtual void showVerbose() {
    showName();
    cout << "\n";
    showCurrentWatt();
    cout << "\n\n";

    lights.show();
    aircons.show();
  }
};

class ComputerRoom : public Room {
  DeviceVector computers;

public:
  ComputerRoom(int number) : Room("�����", number) {
    lights = DeviceVector(3, new Light(), "����");
    computers = DeviceVector(7, new Computer(), "��ǻ��");
    aircons = DeviceVector(2, new AirConditioner(), "������");
  }

  double measureCurrentWh() const override {
    double currentWatt =
        Room::measureCurrentWh(); // ���� ������Ʈ ���·����� üũ

    int num = 0;

    for (const auto &computer : computers) {
      if (computer->getOn()) {
        num++;
        currentWatt += computer->getWatt();
      }
    }

    return currentWatt;
  }

  void showVerbose() override {
    Room::showVerbose();
    computers.show();
  }

  bool controlDevice(string name, int id, bool value) override {
    if (name != "����" && name != "��ǻ��" && name != "������")
      return false;

    if (name == "����") {
      if (id >= lights.size())
        return false;

      lights[id]->setOn(value);

    } else if (name == "��ǻ��") {
      if (id >= computers.size())
        return false;

      computers[id]->setOn(value);
    } else { // ������
      if (id >= aircons.size())
        return false;
      aircons[id]->setOn(value);
    }
    return true;
  }
};
class LectureRoom : public Room {
  DeviceVector computers;
  DeviceVector tvs;

public:
  LectureRoom(int number) : Room("���ǽ�", number) {
    lights = DeviceVector(5, new Light(), "����");
    aircons = DeviceVector(2, new AirConditioner(), "������");
    computers = DeviceVector(1, new Computer(), "��ǻ��");
    tvs = DeviceVector(1, new TV(), "TV");
  }
  double measureCurrentWh() const override {
    double currentWatt = Room::measureCurrentWh();

    for (const auto &computer : computers) {
      if (computer->getOn()) {
        currentWatt += computer->getWatt();
      }
    }

    for (const auto &tv : tvs) {
      if (tv->getOn()) {
        currentWatt += tv->getWatt();
      }
    }

    return currentWatt;
  }
  bool controlDevice(string name, int id, bool value) override {
    if (name != "����" && name != "��ǻ��" && name != "������" && name != "TV")
      return false;

    if (name == "����") {
      if (id >= lights.size())
        return false;
      lights[id]->setOn(value);
    } else if (name == "��ǻ��") {
      if (id >= computers.size())
        return false;
      computers[id]->setOn(value);
    } else if (name == "TV") {
      if (id >= tvs.size())
        return false;
      tvs[id]->setOn(value);
    } else { // ������
      if (id >= aircons.size())
        return false;
      aircons[id]->setOn(value);
    }
    return true;
  }

  void showVerbose() override {
    Room::showVerbose();
    tvs.show();
    computers.show();
  }
};
//
class Laboratory : public Room {
  DeviceVector equipments;

public:
  Laboratory(int number) : Room("������", number) {
    lights = DeviceVector(3, new Light(), "����");
    aircons = DeviceVector(2, new AirConditioner(), "������");
    equipments = DeviceVector(1, new Equipment(), "�������");
  }

  double measureCurrentWh() const override {
    double currentWatt = Room::measureCurrentWh();

    int num = 0;
    for (const auto &equipments : equipments) {
      if (equipments->getOn()) {
        num++;
        currentWatt += equipments->getWatt();
      }
    }

    return currentWatt;
  }

  bool controlDevice(string name, int id, bool value) override {
    if (name != "����" && name != "������" && name != "�������")
      return false;

    if (name == "����") {
      if (id >= lights.size())
        return false;
      lights[id]->setOn(value);
    } else if (name == "�������") {
      if (id >= equipments.size())
        return false;
      equipments[id]->setOn(value);
    } else { // ������
      if (id >= aircons.size())
        return false;
      aircons[id]->setOn(value);
    }
    return true;
  }

  void showVerbose() override {
    Room::showVerbose();
    equipments.show();
  }
};