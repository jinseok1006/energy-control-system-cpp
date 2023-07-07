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
  // 각 매개변수만큼 vector에 device 존재
  Devices(int nLights, int nAirconditioners, int nComputers, int nTvs,
          int nEquipments);
  // name벡터에 Device 추가
  bool addDevice(string name);
  // 이 방의 켜진 모든 Device에 대한 소비전력
  int getConsumption();
  // 이 방의 모든 Deivce를 콘솔에 출력
  void show();
  // name="컴퓨터" id=1 이면, 1번 컴퓨터가 존재하는지 확인
  bool isDeviceExist(string name, int id);
  // name벡터에서 id번의 Device 전원 조절
  void setDeviceOnOff(string name, int id, bool value);
};
