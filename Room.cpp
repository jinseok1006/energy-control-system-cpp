#include "Room.h"


void Room::inspect() {
  double currentWatt = devices.getConsumption();
  this->currentWatt = currentWatt;
}

bool Room::setDeviceOnOff(string name, int id, bool value) {
  if (id < 0)
    return false;

  if (!devices.isDeviceExist(name, id)) {
    // cout << name << id << "����" << endl;
    //  ����ó��
    return false;
  }

  devices.setDeviceOnOff(name, id, value);
  return true;
}

void Room::showVerbose() {
  showName();
  cout << "\n";
  showCurrentWatt();
  cout << "\n\n";

  devices.show();
}