#pragma once
#include "EnergyControlModule.h"
#include "Room.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class EnergyControlManager {
  EnergyControlModule module;

  // ����
public:
  EnergyControlManager() = default;

  void setDeviceOnOff(int roomNumber) {
    Room *room = module.getRoom(roomNumber);
    string name;
    int id;
    bool value;

    system("cls");
    room->showVerbose();

    while (true) {
      cout << "�����ϰ� ���� ����� �̸�, ��ȣ, ��(ON=1, OFF=0)�� ������� "
              "�Է��ϼ���('q'������)>>";
      cin >> name;
      if (name == "q")
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

  void addDevice(int roomNumber) {
    Room *room = module.getRoom(roomNumber);
    string name;

    system("cls");
    room->showVerbose();

    while (true) {
      cout << "�߰��ϱ� ���ϴ� ���(����,������,TV, ��ǻ��,�������)�� �̸��� "
              "�Է��ϼ���('q'�� ������)>>";
      getline(cin, name);

      if (name == "q")
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

  void inRoom(int roomNumber) {
    int input;
    Room *room = module.getRoom(roomNumber);
    system("cls");
    room->inspect();
    room->showVerbose();

    while (true) {
      cout << "1. ��� �߰��ϱ� 2. ��� ���º���(-1�� ������)>>";
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

  void run() {
    int roomNumber;

    module.inspect();
    while (true) {
      if (!cin.fail()) {
        system("cls");
        module.show();
      }
      cout << "�̵��ϰ���� ȣ�� ��ȣ�� �Է��ϼ���('-1'�� �����ϱ�)>>";
      cin >> roomNumber;
      cin.ignore();

      if (roomNumber == -1)
        return;

      if (cin.fail() || (roomNumber < 101 && roomNumber > 116)) {
        cin.clear();
        cin.ignore(100, '\n');
        continue;
      }

      inRoom(roomNumber);
    }
  }
};