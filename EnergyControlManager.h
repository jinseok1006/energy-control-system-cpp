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

  void run() {
    module.inspect();
    enterRoom();
  }

  void controlDevice(int roomNumber) {
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

      if (id < 1)
        continue;

      bool res = room->controlDevice(name, id - 1, value);

      if (res) {
        system("cls");
        room->inspect();
        room->showVerbose();
      }
    }
  }

  void enterRoom() {
    int roomNumber;
    while (true) {
      if (!cin.fail()) {
        system("cls");
        module.show();
      }
      cout << "�̵��ϰ���� ȣ�� ��ȣ�� �Է��ϼ���('-1'�� �����ϱ�)>>";
      cin >> roomNumber;

      if (roomNumber == -1)
        return;

      if (cin.fail() || (roomNumber < 101 && roomNumber > 116)) {
        cin.clear();
        cin.ignore(100, '\n');
        continue;
      }

      controlDevice(roomNumber);
    }
  }
};