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
  int currentWatt;
  Devices devices;

  Room(string name, int roomNumber)
      : name(name), roomNumber(roomNumber), currentWatt(0) {}

public:
  // 현재 호실의 소비 전력 검사 후 currentWatt에 대입
  void inspect();

  double getCurrentWatt() const { return currentWatt; }
  bool setDeviceOnOff(string name, int id, bool value);
  void showName() { cout << roomNumber << "호 " << name; }
  void showCurrentWatt() { cout << "소비 전력:" << currentWatt; }
  // devices에 있는 모든 DeviceVector에 대해 show
  void showVerbose();
  bool addDevice(string name) { return devices.addDevice(name); }
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
    devices = Devices(5, 2, 1, 3, 0);
  }
};

class Laboratory : public Room {
public:
  Laboratory(int roomNumber) : Room("연구실", roomNumber) {
    devices = Devices(3, 2, 5, 0, 3);
  }
};