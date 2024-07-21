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

	// 인원수보다 놀이기구가 더 많으면 바로 다 탈 수 있음
	if (childrenNum <= rideNum) {
		cout << childrenNum << "\n";
	}
	else {
		// 이분탐색으로 (children - 1)분을 정해서 마지막에 타는 놀이기구 찾기
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

		// 1) mid - 1 번째 시간까지 먼저 아이들 카운트하고
		ll childrenCount = rideNum;
		for (int i = 0; i < rideTimes.size(); i++) {
			childrenCount += (result - 1) / rideTimes[i];
		}
		// 2) mid 번째 시간을 놀이기구 한개씩 아이들 카운트해서 마지막 아이가 탑승할 놀이기구 찾기
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