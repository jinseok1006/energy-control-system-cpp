#pragma once
#include "Device.h"
#include "DeviceVector.h"
#include "Devices.h"
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
  int roomNumber;
  double currentWatt;
  Devices devices;

  Room(string name, int roomNumber) : name(name), roomNumber(roomNumber), currentWatt(0) {}

public:
  void inspect() {
    double currentWatt = devices.getConsumption();
    this->currentWatt = currentWatt;
  }

  double getCurrentWatt() const { return currentWatt; }
  // 이름을 DeviceVector와 매칭해야함

  bool setDeviceOnOff(string name, int id, bool value) {
    if(id<0) return false;

    if (!devices.isDeviceExist(name, id)) {
      //cout << name << id << "없음" << endl;
      // 예외처리
      return false;
    }

    devices.setDeviceOnOff(name, id, value);
    return true;
  }
  void showName() { cout << roomNumber << "호 " << name; }
  void showCurrentWatt() { cout << "소비 전력:" << currentWatt; }

  void showVerbose() {
    showName();
    cout << "\n";
    showCurrentWatt();
    cout << "\n\n";

    devices.show();
  }
  bool addDevice(string name) {
    return devices.addDevice(name);
  }
};

class ComputerRoom : public Room {
public:
  ComputerRoom(int roomNumber) : Room("전산실", roomNumber) {
    devices = Devices(3, 2, 7, 0, 0);
  }
};

class LectureRoom : public Room {
public:
  LectureRoom(int roomNumber) : Room("강의실", roomNumber) {
    devices = Devices(5, 2, 1, 1, 0);
  }
};

class Laboratory : public Room {
public:
  Laboratory(int roomNumber) : Room("연구실", roomNumber) {
    devices = Devices(3, 2, 0, 0, 1);
  }
};