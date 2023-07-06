#pragma once
#include <cstdlib>
#include <ctime>
#include <string>

using std::string;

class Device {
  const int watt; // 와트
  bool state;     // 켜짐여부
  static string name;

protected:
  Device(int state, int watt) : state(state), watt(watt) {}

public:
  bool getOnOff() const { return state; }
  void setOnOff(bool value) { state = value; }
  int getWatt() const { return watt; }
  string getOnString() const { return state ? "ON" : "OFF"; }
};

class Light : public Device {
public:
  const static int WATT = 40;
  Light(bool state = false) : Device(state, WATT) {}
};

class AirConditioner : public Device {
public:
  const static int WATT = 1300;
  AirConditioner(bool state = false) : Device(state, WATT) {}
};

class TV : public Device {
public:
  const static int WATT = 300;
  TV(bool state = false) : Device(state, WATT) {}
};

class Computer : public Device {
public:
  const static int WATT = 80;
  Computer(bool state = false) : Device(state, WATT) {}
};

class Equipment : public Device {
public:
  const static int WATT = 40;
  Equipment(bool state = false) : Device(state, WATT) {}
};
