#pragma once
#include "EnergyObject.h"
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

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

inline bool random() { return rand() % 2; }

class Room {
public:
  const static int COMPUTER_ROOM = 0;
  const static int LABORATORY = 1;
  const static int LECTURE_ROOM = 2;

protected:
  string name;
  int number;
  double currentWh;
  MyVector<AirConditioner> aircons;
  MyVector<Light> lights;

  Room(string name, int number) : name(name), number(number), currentWh(0) {}

public:
  void inspect() {
    double currentWh = measureCurrentWh();
    this->currentWh = currentWh;
  }

  virtual double measureCurrentWh() const {
    double currentWh = 0;

    for (const auto &light : lights) {
      if (light.getOn()) {
        currentWh += light.getWh();
      }
    }

    for (const auto &aircon : aircons) {
      if (aircon.getOn()) {
        currentWh += aircon.getWh();
      }
    }
    return currentWh;
  }

  double getCurrentWh() const { return currentWh; }

  virtual bool controlEnergyObject(string name, int id, bool value) = 0;

  void showName() { cout << number << "ȣ " << name; }
  void showCurrentWh() { cout << "���»�뷮:" << currentWh; }

  virtual void showVerbose() {
    showName();
    cout << "\n";
    showCurrentWh();
    cout << "\n\n";

    lights.show();
    aircons.show();
  }
};

//=========================================
// ȣ���� ����ϴ� �� �����, ���ǽ�, �ǽ���, �繫�� ��
class ComputerRoom : public Room {
  MyVector<Computer> computers;

public:
  ComputerRoom(int number) : Room("�����", number) {
    lights = MyVector<Light>(3, Light(), "����");
    computers = MyVector<Computer>(7, Computer(), "��ǻ��");
    aircons = MyVector<AirConditioner>(2, AirConditioner(), "������");

    setRandom();
  }

  void setRandom() {
    for (auto &light : lights)
      light.setOn(random());
    for (auto &computer : computers)
      computer.setOn(random());
    for (auto &aircon : aircons)
      aircon.setOn(random());
  }

  double measureCurrentWh() const override {
    double currentWh =
        Room::measureCurrentWh(); // ���� ������Ʈ ���·����� üũ

    int num = 0;

    for (const auto &computer : computers) {
      if (computer.getOn()) {
        num++;
        currentWh += computer.getWh();
      }
    }

    return currentWh;
  }

  void showVerbose() override {
    Room::showVerbose();
    computers.show();
  }

  bool controlEnergyObject(string name, int id, bool value) override {
    if (name != "����" && name != "��ǻ��" && name != "������")
      return false;

    if (name == "����") {
      if (id >= lights.size())
        return false;
      lights.setOn(id, value);

    } else if (name == "��ǻ��") {
      if (id >= computers.size())
        return false;
      cout << "id ���";
      computers.setOn(id, value);
    } else { // ������
      if (id >= aircons.size())
        return false;
      aircons.setOn(id, value);
    }
    return true;
  }
};
class LectureRoom : public Room {
  MyVector<Computer> computers;
  MyVector<TV> tvs;

public:
  LectureRoom(int number) : Room("���ǽ�", number) {
    lights = MyVector<Light>(5, Light(), "����");
    aircons = MyVector<AirConditioner>(2, AirConditioner(), "������");
    computers = MyVector<Computer>(1, Computer(), "��ǻ��");
    tvs = MyVector<TV>(1, TV(), "TV");

    setRandom();
  }
  double measureCurrentWh() const override {
    double currentWh = Room::measureCurrentWh();

    for (const auto &computer : computers) {
      if (computer.getOn()) {
        currentWh += computer.getWh();
      }
    }

    for (const auto &tv : tvs) {
      if (tv.getOn()) {
        currentWh += tv.getWh();
      }
    }

    return currentWh;
  }
  bool controlEnergyObject(string name, int id, bool value) override {
    if (name != "����" && name != "��ǻ��" && name != "������" && name != "TV")
      return false;

    if (name == "����") {
      if (id >= lights.size())
        return false;
      lights.setOn(id, value);
    } else if (name == "��ǻ��") {
      if (id >= computers.size())
        return false;
      computers.setOn(id, value);
    } else if (name == "TV") {
      if (id >= tvs.size())
        return false;
      tvs.setOn(id, value);
    } else { // ������
      if (id >= aircons.size())
        return false;
      aircons.setOn(id, value);
    }
    return true;
  }

  void setRandom() {
    for (auto &light : lights)
      light.setOn(random());
    for (auto &aircon : aircons)
      aircon.setOn(random());

    for (auto &tv : tvs)
      tv.setOn(random());
  }

  void showVerbose() override {
    Room::showVerbose();
    tvs.show();
    computers.show();
  }
};
//
class Laboratory : public Room {
  MyVector<Equipment> equipments;

public:
  Laboratory(int number) : Room("������", number) {
    lights = MyVector<Light>(3, Light(), "����");
    aircons = MyVector<AirConditioner>(2, AirConditioner(), "������");
    equipments = MyVector<Equipment>(1, Equipment(), "�������");
  }

  void setRandom() {
    for (auto &light : lights)
      light.setOn(random());
    for (auto &aircon : aircons)
      aircon.setOn(random());
    for (auto &aircon : aircons)
      aircon.setOn(random());
  }

  double measureCurrentWh() const override {
    double currentWh = Room::measureCurrentWh();

    int num = 0;
    for (const auto &equipments : equipments) {
      if (equipments.getOn()) {
        num++;
        currentWh += equipments.getWh();
      }
    }

    return currentWh;
  }

  bool controlEnergyObject(string name, int id, bool value) override {
    if (name != "����" && name != "������" && name != "�������")
      return false;

    if (name == "����") {
      if (id >= lights.size())
        return false;
      lights.setOn(id, value);
    } else if (name == "�������") {
      if (id >= equipments.size())
        return false;
      equipments.setOn(id, value);
    } else { // ������
      if (id >= aircons.size())
        return false;
      aircons.setOn(id, value);
    }
    return true;
  }

  void showVerbose() override {
    Room::showVerbose();
    equipments.show();
  }
};