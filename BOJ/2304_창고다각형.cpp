#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void InputData();
bool bigger(pair<int, int> bar1, pair<int, int> bar2);
int getArea();

vector<pair<int, int>> bars;

int main() {

	InputData();
	cout << getArea() << "\n";

	return 0;
}

bool bigger(pair<int, int> bar1, pair<int, int> bar2) {
	return bar1.first < bar2.first;
}

void InputData() {
	int barNum, x, y;

	cin >> barNum;
	for (int i = 0; i < barNum; i++) {
		cin >> x >> y;
		bars.push_back({ x,y });
	}
	sort(bars.begin(), bars.end(), bigger);
}

int getArea() {
	int area = 0; // 총 영역 넓이

	// 1. 왼쪽 영역 구하기
	int leftPos = bars[0].first;
	int leftMax = bars[0].second;

	for (auto& bar : bars) {
		if (leftMax <= bar.second) {
			area += (bar.first - leftPos) * leftMax;
			leftPos = bar.first;
			leftMax = bar.second;
		}
	}

	// 2. 오른쪽 영역 구하기
	int rightPos = bars.back().first;
	int rightMax = bars.back().second;
	
	for (int i = bars.size() - 1; i >= 0; i--) {
		if (rightMax < bars[i].second) {
			area += (rightPos - bars[i].first) * rightMax;
			rightPos = bars[i].first;
			rightMax = bars[i].second;
		}
	}

	return area + leftMax; // 중앙에 가장 높은 1개 넓이 더해서 반환
}