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

  // 메인
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
      cout << "설정하고 싶은 기기의 이름, 번호, 값(ON=1, OFF=0)을 순서대로 "
              "입력하세요('q'나가기)>>";
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
      cout << "이동하고싶은 호실 번호를 입력하세요('-1'로 종료하기)>>";
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