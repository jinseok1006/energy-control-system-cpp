
#include "EnergyControlManager.h"

//공과대학 에너지 관리 시스템
// 여기서 켜고 끌때마다 room에 있는 전력이 변경되어야함

// 호실
// 공통으로 있는 전기를 먹는 기구들
// 여기서 사용량 체크

// 에너지관리모듈
// 쓰레드에게 이 객체를 넘겨서 변동시킴(보류)

//============================================================
//
// 유저 인풋을 통해서
// 방을 새로 생성하고
// 방에 원하는 장치를 넣을 수 있음

// 외부쓰레드로 전력량 사용여부 조절
// 에너지오브젝트를 켜면 배열에 삽입(ㄴㄴ, 에너지 컨트롤 시스템에 있는 모든
// EnergyObject에 대해서 접근하고 켜져있는지 확인 후 에너지 소모 누적)
// 쓰레드는 배열에 대해서 루프당 에너지 소모량 누적

int main() {
  EnergyControlManager manager;
  manager.run();
}
