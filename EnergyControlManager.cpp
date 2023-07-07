#pragma once
#include "EnergyControlManager.h"
#include <limits>;

using std::cin;
using std::cout;
using std::endl;
using std::string;

void EnergyControlManager::setDeviceOnOff(int roomNumber) {
  Room *room = module.getRoom(roomNumber);
  string name;
  int id;
  bool value;

  system("cls");
  room->showVerbose();

  while (true) {
    cout << "�����ϰ� ���� ����� �̸�, ��ȣ, ��(ON=1, OFF=0)�� ������� "
            "�Է��ϼ���('������'�� �ڷΰ���)>>";
    cin >> name;
    if (name == "������")
      break;

    cin >> id >> value;
    cin.clear();
    cin.ignore(100, '\n');

    bool res = room->setDeviceOnOff(name, id - 1, value);

    if (res) {
      system("cls");
      room->inspect();
      room->showVerbose();
    } else {
      cout << "�Է��� �߸��Ǿ����ϴ�." << endl;
    }
  }
}

void EnergyControlManager::addDevice(int roomNumber) {
  Room *room = module.getRoom(roomNumber);
  string name;

  system("cls");
  room->showVerbose();

  while (true) {
    cout << "�߰��ϱ� ���ϴ� ���(����,������,TV, ��ǻ��,�������)�� �̸��� "
            "�Է��ϼ���(�ڷ� ������ '������')>>";
    getline(cin, name);

    if (name == "������")
      break;

    bool res = room->addDevice(name);

    if (res) {
      system("cls");
      room->inspect();
      room->showVerbose();
    } else {
      cout << "�Է��� �߸��Ǿ����ϴ�." << endl;
    }
  }
}

void EnergyControlManager::inRoom(int roomNumber) {
  int input;
  Room *room = module.getRoom(roomNumber);
  system("cls");
  room->inspect();
  room->showVerbose();

  while (true) {
    cout << "1. ��� �߰��ϱ� 2. ��� ���º���(�ڷ� ������ '-1')>>";
    cin >> input;
    cin.ignore();

    switch (input) {
    case 1:
      addDevice(roomNumber);
      system("cls");
      room->showVerbose();
      break;
    case 2:
      setDeviceOnOff(roomNumber);
      system("cls");
      room->showVerbose();
      break;
    case -1:
      return;
    default:
      cout << "�Է��� �߸��Ǿ����ϴ�." << endl;
      cin.clear();
      cin.ignore(100, '\n');
      break;
    }
  }
}

void EnergyControlManager::run() {
  int roomNumber;
  bool failbit = false;
  module.inspect();
  system("cls");
  module.show();

  while (true) {
    cout << "�̵��ϰ���� ȣ�� ��ȣ�� �Է��ϼ���(�����Ϸ��� '-1')>>";
    cin >> roomNumber;
    cin.ignore();

    if (roomNumber == -1)
      return;

    if (cin.fail()) {
      cout << "�Է��� �߸��Ǿ����ϴ�." << endl;
      cin.clear();
      cin.ignore(100, '\n');
      continue;
    }

    if (roomNumber < 101 || roomNumber > 116) {
      cout << "�Է��� �߸��Ǿ����ϴ�." << endl;
      continue;
    }

    inRoom(roomNumber);
    system("cls");
    module.inspect();
    module.show();
  }
}
