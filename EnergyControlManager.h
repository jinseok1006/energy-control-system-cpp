#pragma once
#include "EnergyControlModule.h"
#include "Room.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class EnergyControlManager {
  EnergyControlModule module;

  // ∏ﬁ¿Œ
public:
  EnergyControlManager() { srand((unsigned)time(0)); }

  void setDeviceOnOff(int roomNumber);
  void addDevice(int roomNumber);
  void inRoom(int roomNumber);
  void run();
};