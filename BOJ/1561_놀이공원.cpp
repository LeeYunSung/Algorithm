#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MAX_TIME = 60000000001;

bool check(ll mid, ll childrenNum, vector<int> rideTimes);

int main() {
	ll childrenNum, rideNum;
	vector<int> rideTimes;

	// input
	cin >> childrenNum >> rideNum;

	int time;
	for (int i = 0; i < rideNum; i++) {
		cin >> time;
		rideTimes.push_back(time);
	}

	// �ο������� ���̱ⱸ�� �� ������ �ٷ� �� Ż �� ����
	if (childrenNum <= rideNum) {
		cout << childrenNum << "\n";
	}
	else {
		// �̺�Ž������ (children - 1)���� ���ؼ� �������� Ÿ�� ���̱ⱸ ã��
		ll low = 1, high = MAX_TIME, mid;
		ll result = 0;
		while (low <= high) {
			mid = (low + high) / 2;
			if (check(mid, childrenNum, rideTimes)) {
				high = mid - 1;
				result = mid;
			}
			else {
				low = mid + 1;
			}
		}

		// 1) mid - 1 ��° �ð����� ���� ���̵� ī��Ʈ�ϰ�
		ll childrenCount = rideNum;
		for (int i = 0; i < rideTimes.size(); i++) {
			childrenCount += (result - 1) / rideTimes[i];
		}
		// 2) mid ��° �ð��� ���̱ⱸ �Ѱ��� ���̵� ī��Ʈ�ؼ� ������ ���̰� ž���� ���̱ⱸ ã��
		for (int i = 0; i < rideTimes.size(); i++) {
			if (result % rideTimes[i] == 0) {
				childrenCount += 1;
				if (childrenCount == childrenNum) {
					cout << i + 1 << "\n";
					break;
				}
			}
		}
	}

	return 0;
}

bool check(ll mid, ll childrenNum, vector<int> rideTimes) {
	ll childCount = rideTimes.size();
	
	for (int i = 0; i < rideTimes.size(); i++) {
		childCount += mid / rideTimes[i];
		
		if (childCount >= childrenNum) {
			return true;
		}
	}
	return false;
} 