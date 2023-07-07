#pragma once
#include <cstdlib>
#include <ctime>
#include <string>

using std::string;

class Device {
  const int watt; // 와트
  bool power;     // 켜짐여부
  static string name;

protected:
  Device(int power, int watt) : power(power), watt(watt) {}

public:
  bool getPower() const { return power; }
  void setPower(bool value) { power = value; }
  int getWatt() const { return watt; }
  string getOnString() const { return power ? "ON" : "OFF"; }
};

class Light : public Device {
public:
  const static int WATT = 40;
  Light(bool power = false) : Device(power, WATT) {}
};

class AirConditioner : public Device {
public:
  const static int WATT = 1300;
  AirConditioner(bool power = false) : Device(power, WATT) {}
};

class TV : public Device {
public:
  const static int WATT = 300;
  TV(bool power = false) : Device(power, WATT) {}
};

class Computer : public Device {
public:
  const static int WATT = 80;
  Computer(bool power = false) : Device(power, WATT) {}
};

class Equipment : public Device {
public:
  const static int WATT = 40;
  Equipment(bool power = false) : Device(power, WATT) {}
};
