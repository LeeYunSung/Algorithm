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
	int area = 0; // �� ���� ����

	// 1. ���� ���� ���ϱ�
	int leftPos = bars[0].first;
	int leftMax = bars[0].second;

	for (auto& bar : bars) {
		if (leftMax <= bar.second) {
			area += (bar.first - leftPos) * leftMax;
			leftPos = bar.first;
			leftMax = bar.second;
		}
	}

	// 2. ������ ���� ���ϱ�
	int rightPos = bars.back().first;
	int rightMax = bars.back().second;
	
	for (int i = bars.size() - 1; i >= 0; i--) {
		if (rightMax < bars[i].second) {
			area += (rightPos - bars[i].first) * rightMax;
			rightPos = bars[i].first;
			rightMax = bars[i].second;
		}
	}

	return area + leftMax; // �߾ӿ� ���� ���� 1�� ���� ���ؼ� ��ȯ
}