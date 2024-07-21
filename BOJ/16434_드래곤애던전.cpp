#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct Room {
    int type, attack, hp;
};

vector<Room> rooms;

int check(ll Hp, ll Atk);

int main() {
    int roomNum, currentAttack;
    ll result;

    cin >> roomNum >> currentAttack;

    // input
    for (int i = 0; i < roomNum; i++) {
        int type, attack, hp;
        cin >> type >> attack >> hp;
        rooms.push_back({ type, attack, hp });
    }

    // 최소 hp 이분탐색
    ll low = 1, high = 9e18, mid;
    while (low <= high) {
        mid = (low + high) / 2;

        if (check(mid, currentAttack)) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    cout << result << "\n";

    return 0;
}

int check(ll hp, ll attack) { // 내 hp, attack
    ll tempHp = hp;

    for (Room room : rooms) {
        //몬스터
        if (room.type == 1) {
            ll monsterHp = room.hp;
            ll monsterAttack = room.attack;

            // 몬스터를 죽이는데 필요한 공격 수
            ll needAttackNum = room.hp / attack;
            if (monsterHp % attack) needAttackNum += 1; // 몬스터 HP 가 공격량으로 나누어 떨어지지 않으면 1회 더 공격
            
            // 몬스터가 나에게 입히는 데미지량
            ll damage = room.attack * (needAttackNum - 1);
            tempHp -= damage;

            if (tempHp <= 0) {
                return 0;
            }
        }
        //포션
        else {
            attack += room.attack;
            tempHp += room.hp;

            if (tempHp > hp) {
                tempHp = hp;
            }
        }
    }

    return 1;
}