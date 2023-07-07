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

  // �ش� ȣ���� ����̽� ���� �����ϴ� ��¹�
  void setDeviceOnOff(int roomNumber);
  // �ش� ȣ���� ����̽��� �߰��ϴ� ��¹�
  void addDevice(int roomNumber);
  // ȣ�ǿ� �������� �� �߰�/���� ���� ��¹�
  void inRoom(int roomNumber);
  // ����
  void run();
};