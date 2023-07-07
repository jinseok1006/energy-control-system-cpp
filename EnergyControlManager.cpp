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
    cout << "설정하고 싶은 기기의 이름, 번호, 값(ON=1, OFF=0)을 순서대로 "
            "입력하세요('나가기'로 뒤로가기)>>";
    cin >> name;
    if (name == "나가기")
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
      cout << "입력이 잘못되었습니다." << endl;
    }
  }
}

void EnergyControlManager::addDevice(int roomNumber) {
  Room *room = module.getRoom(roomNumber);
  string name;

  system("cls");
  room->showVerbose();

  while (true) {
    cout << "추가하기 원하는 장비(조명,에어컨,TV, 컴퓨터,실험장비)의 이름을 "
            "입력하세요(뒤로 가려면 '나가기')>>";
    getline(cin, name);

    if (name == "나가기")
      break;

    bool res = room->addDevice(name);

    if (res) {
      system("cls");
      room->inspect();
      room->showVerbose();
    } else {
      cout << "입력이 잘못되었습니다." << endl;
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
    cout << "1. 기기 추가하기 2. 기기 상태변경(뒤로 가려면 '-1')>>";
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
      cout << "입력이 잘못되었습니다." << endl;
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
    cout << "이동하고싶은 호실 번호를 입력하세요(종료하려면 '-1')>>";
    cin >> roomNumber;
    cin.ignore();

    if (roomNumber == -1)
      return;

    if (cin.fail()) {
      cout << "입력이 잘못되었습니다." << endl;
      cin.clear();
      cin.ignore(100, '\n');
      continue;
    }

    if (roomNumber < 101 || roomNumber > 116) {
      cout << "입력이 잘못되었습니다." << endl;
      continue;
    }

    inRoom(roomNumber);
    system("cls");
    module.inspect();
    module.show();
  }
}
