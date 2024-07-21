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

    // �ּ� hp �̺�Ž��
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

int check(ll hp, ll attack) { // �� hp, attack
    ll tempHp = hp;

    for (Room room : rooms) {
        //����
        if (room.type == 1) {
            ll monsterHp = room.hp;
            ll monsterAttack = room.attack;

            // ���͸� ���̴µ� �ʿ��� ���� ��
            ll needAttackNum = room.hp / attack;
            if (monsterHp % attack) needAttackNum += 1; // ���� HP �� ���ݷ����� ������ �������� ������ 1ȸ �� ����
            
            // ���Ͱ� ������ ������ ��������
            ll damage = room.attack * (needAttackNum - 1);
            tempHp -= damage;

            if (tempHp <= 0) {
                return 0;
            }
        }
        //����
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