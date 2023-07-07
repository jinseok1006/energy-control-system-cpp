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
  double totalWatt;

  vector<Room *> rooms;

public:
  EnergyControlModule();
  void inspect();
  void show() const;
  Room *getRoom(int roomNumber) { return rooms.at(roomNumber - 101); }
};