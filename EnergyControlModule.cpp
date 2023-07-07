#pragma once
#include "EnergyControlModule.h"

EnergyControlModule::EnergyControlModule() {
  totalUsage = 0;
  totalWatt = 0;

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

void EnergyControlModule::inspect() {
  int totalWatt = 0;
  int i = 0;

  for (auto &room : rooms) {
    room->inspect();
    totalWatt += room->getCurrentWatt();
  }

  this->totalWatt = totalWatt;
}

void EnergyControlModule::show() const {
  cout << "공과대학 건물 전력 관리 시스템" << endl;
  cout << "현재 총 소비 전력: " << totalWatt << "W" << endl << endl;

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