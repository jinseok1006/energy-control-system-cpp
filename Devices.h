#pragma once
#include "DeviceVector.h";
#include <string>
using std::string;
using std::vector;

class Devices {
  DeviceVector lights;
  DeviceVector computers;
  DeviceVector equipments;
  DeviceVector aircons;
  DeviceVector tvs;

public:
  Devices() = default;
  Devices(int nLights, int nAirconditioners, int nComputers, int nTvs,
          int nEquipments);
  bool addDevice(string name);
  int getConsumption();
  void show();
  bool isDeviceExist(string name, int id);
  void setDeviceOnOff(string name, int id, bool value);
};
