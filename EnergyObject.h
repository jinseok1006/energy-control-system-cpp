#pragma once
#include <cstdlib>
#include <ctime>
#include <string>

using std::string;

class Device {
  bool on;      // 켜짐여부
  const int watt; // 와트시
  static string name;

protected:
  Device(int on, int watt) : on(false), watt(watt) {}

public:
  bool getOn() const { return on; }
  void setOn(bool value) { on = value; }
  int getWh() const { return watt; }
  string getOnString() const { return on ? "ON" : "OFF"; }
};

class Light : public Device {
public:
  Light(bool on = false) : Device(on, 5) {}
};

class AirConditioner : public Device {
public:
  AirConditioner(bool on = false) : Device(on, 15) {}
};

class TV : public Device {

public:
  TV(bool on = false) : Device(on, 10) {}
};

class Computer : public Device {

public:
  Computer(bool on = false) : Device(on, 10) {}
};

class Equipment : public Device {

public:
  Equipment(bool on = false) : Device(on, 25) {}
};
