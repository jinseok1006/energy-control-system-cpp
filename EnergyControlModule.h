#pragma once
#include"Room.h"
#include<iostream>
#include<string>
#include<vector>
using std::vector;
using std::cout;
using std::endl;


class EnergyControlModule {
  double totalUsage;
  double totalWatt;
  double billingCharge;

  vector<Room *> rooms;

public:
  EnergyControlModule() {
    totalUsage = 0;
    totalWatt = 0;
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
    int totalWatt = 0;
    int i = 0;

    for (auto &room : rooms) {
      room->inspect();
      totalWatt += room->getCurrentWatt();
    }

    this->totalWatt = totalWatt;
  }

  void show() const {
    cout << "전북대학교 공과대학 건물 전력 관리 시스템" << endl;
    cout << "총 소비 전력: " << totalWatt << "W" << endl << endl;

    for (int row = 0; row < 4; row++) {
      for (int col = 0; col < 4; col++) {
        rooms[row * 4 + col]->showName();
        cout << '\t';
      }
      cout << endl;

      for (int col = 0; col < 4; col++) {
        rooms[row * 4 + col]->showCurrentWatt();
        cout << '\t';
      }
      cout << "\n\n";
    }
  }

  Room *getRoom(int roomNumber) { return rooms.at(roomNumber - 101); }
};