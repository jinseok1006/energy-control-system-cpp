#pragma once
#include "Room.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class EnergyControlModule {
  double totalUsage;
  double totalWatt; // 총 사용 전력

  vector<Room *> rooms;

public:
  EnergyControlModule();
  void inspect(); // 모든 호실의 사용전력을 구하고 totalWatt에 대입
  void show() const;
  Room *getRoom(int roomNumber) { return rooms.at(roomNumber - 101); }
};