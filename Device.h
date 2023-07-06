#pragma once
#include <cstdlib>
#include <ctime>
#include <string>

using std::string;

class Device {
  const int watt; // 와트
  bool on;        // 켜짐여부
  static string name;

protected:
  Device(int on, int watt) : on(on), watt(watt) {}

public:
  bool getOn() const { return on; }
  void setOn(bool value) { on = value; }
  int getWatt() const { return watt; }
  string getOnString() const { return on ? "ON" : "OFF"; }
};

class Light : public Device {
public:
  const static int WATT = 40;
  Light(bool on = false) : Device(on, WATT) {}
};

class AirConditioner : public Device {
public:
  const static int WATT = 1300;
  AirConditioner(bool on = false) : Device(on, WATT) {}
};

class TV : public Device {
public:
  const static int WATT = 300;
  TV(bool on = false) : Device(on, WATT) {}
};

class Computer : public Device {
public:
  const static int WATT = 80;
  Computer(bool on = false) : Device(on, WATT) {}
};

class Equipment : public Device {
public:
  const static int WATT = 40;
  Equipment(bool on = false) : Device(on, WATT) {}
};
