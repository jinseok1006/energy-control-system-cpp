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

public:
  EnergyControlManager() {}

  // 해당 호실의 디바이스 전원 조절하는 출력문
  void setDeviceOnOff(int roomNumber);
  // 해당 호실의 디바이스를 추가하는 출력문
  void addDevice(int roomNumber);
  // 호실에 입장했을 때 추가/전원 선택 출력문
  void inRoom(int roomNumber);
  // 메인
  void run();
};