#pragma once
#include <cstdlib>
#include <ctime>
#include <string>

using std::string;

class EnergyObject {
  bool on;      // 켜짐여부
  const int wh; // 와트시
  static string name;

protected:
  EnergyObject(int on, int wh) : on(false), wh(wh) {}

public:
  bool getOn() const { return on; }
  void setOn(bool value) { on = value; }
  int getWh() const { return wh; }
  string getOnString() const { return on ? "ON" : "OFF"; }
};

class Light : public EnergyObject {
public:
  Light(bool on = false) : EnergyObject(on, 5) {}
};

class AirConditioner : public EnergyObject {
public:
  AirConditioner(bool on = false) : EnergyObject(on, 15) {}
};

class TV : public EnergyObject {

public:
  TV(bool on = false) : EnergyObject(on, 10) {}
};

class Computer : public EnergyObject {

public:
  Computer(bool on = false) : EnergyObject(on, 10) {}
};

class Equipment : public EnergyObject {

public:
  Equipment(bool on = false) : EnergyObject(on, 25) {}
};
