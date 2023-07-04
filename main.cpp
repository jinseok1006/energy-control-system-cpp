
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

//�������� ������ ���� �ý���
// ���⼭ �Ѱ� �������� room�� �ִ� ��Ʈ�ð� ����Ǿ����

// ȣ��
// �������� �ִ� ���⸦ �Դ� �ⱸ��
// ���⼭ ��뷮 üũ

// �������������
// �����忡�� �� ��ü�� �Ѱܼ� ������Ŵ

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
    cout << "���ϴ��б� �������� �ǹ� ���� ���� �ý���" << endl;
    cout << "�� ���� ��뷮: " << totalWh << "Wh" << endl << endl;

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

  // ����
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
      cout << "�̵��ϰ���� ȣ�� ��ȣ�� �Է��ϼ���('-1'�� �����ϱ�)>>";
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

// �ܺξ������ ���·� ��뿩�� ����
// ������������Ʈ�� �Ѹ� �迭�� ����(����, ������ ��Ʈ�� �ý��ۿ� �ִ� ���
// EnergyObject�� ���ؼ� �����ϰ� �����ִ��� Ȯ�� �� ������ �Ҹ� ����)
// ������� �迭�� ���ؼ� ������ ������ �Ҹ� ����

int main() {
  srand((unsigned)time(0));
  EnergyControlSystem system;
  system.run();
}
