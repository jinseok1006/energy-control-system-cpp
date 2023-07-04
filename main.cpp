
#include "EnergyObject.h"
#include "Room.h"
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

//공과대학 에너지 관리 시스템
// 여기서 켜고 끌때마다 room에 있는 와트시가 변경되어야함

// 호실
// 공통으로 있는 전기를 먹는 기구들
// 여기서 사용량 체크

// 에너지관리모듈
// 쓰레드에게 이 객체를 넘겨서 변동시킴

class EnergyControlModule {
  double totalUsage;
  double totalWh;
  double billingCharge;

  vector<Room *> rooms;

public:
  EnergyControlModule() {
    totalUsage = 0;
    totalWh = 0;
    billingCharge = 0;

    for (int i = 0; i < 16; i++) {
      int roomType = rand() % 3;
      Room *room;

      switch (roomType) {
      case Room::COMPUTER_ROOM:
        room = new ComputerRoom(101 + i);
        break;
      case Room::LABORATORY:
        room = new Laboratory(101 + i);
        break;
      case Room::LECTURE_ROOM:
        room = new LectureRoom(101 + i);
        break;
      }

      rooms.push_back(room);
    }
  }

  void inspect() {
    int totalWh = 0;
    int i = 0;

    for (auto &room : rooms) {
      room->inspect();
      totalWh += room->getCurrentWh();
    }

    this->totalWh = totalWh;
  }

  void show() {
    cout << "전북대학교 공과대학 건물 전력 관리 시스템" << endl;
    cout << "총 전력 사용량: " << totalWh << "Wh" << endl << endl;

    for (int row = 0; row < 4; row++) {
      for (int col = 0; col < 4; col++) {
        rooms[row * 4 + col]->showName();
        cout << '\t';
      }
      cout << endl;

      for (int col = 0; col < 4; col++) {
        rooms[row * 4 + col]->showCurrentWh();
        cout << '\t';
      }
      cout << "\n\n";
    }
  }

  Room *getRoom(int number) { return rooms.at(number - 101); }
};

//============================================================

class EnergyControlSystem {
  EnergyControlModule module;
  Room *room;

  // 메인
public:
  EnergyControlSystem() = default;

  void run() {
    while (true) {

      module.inspect();

      bool exit = enter();
      if (exit)
        break;

      control();
    }
  }

  void control() {
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

      bool res = room->controlEnergyObject(name, id - 1, value);

      if (res) {
        system("cls");
        room->inspect();
        room->showVerbose();
      }
    }
  }

  bool enter() {
    int number;
    system("cls");
    module.show();
    while (true) {
      cout << "이동하고싶은 호실 번호를 입력하세요('-1'로 종료하기)>>";
      cin >> number;
      cin.clear();
      cin.ignore(100, '\n');

      if (number == -1)
        return true;

      if (number >= 101 && number <= 116) {
        this->room = module.getRoom(number);
        return false;
      }
    }
  }
};

// 외부쓰레드로 전력량 사용여부 조절
// 에너지오브젝트를 켜면 배열에 삽입(ㄴㄴ, 에너지 컨트롤 시스템에 있는 모든
// EnergyObject에 대해서 접근하고 켜져있는지 확인 후 에너지 소모 누적)
// 쓰레드는 배열에 대해서 루프당 에너지 소모량 누적

int main() {
  srand((unsigned)time(0));
  EnergyControlSystem system;
  system.run();
}
