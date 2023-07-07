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
  // �� �Ű�������ŭ vector�� device ����
  Devices(int nLights, int nAirconditioners, int nComputers, int nTvs,
          int nEquipments);
  // name���Ϳ� Device �߰�
  bool addDevice(string name);
  // �� ���� ���� ��� Device�� ���� �Һ�����
  int getConsumption();
  // �� ���� ��� Deivce�� �ֿܼ� ���
  void show();
  // name="��ǻ��" id=1 �̸�, 1�� ��ǻ�Ͱ� �����ϴ��� Ȯ��
  bool isDeviceExist(string name, int id);
  // name���Ϳ��� id���� Device ���� ����
  void setDeviceOnOff(string name, int id, bool value);
};
