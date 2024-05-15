#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int universityNum, pay, day, maxPay = 0;

// ����, ������ ������ �ϴ� ��� ���� ����
vector<pair<int, int>> v;

// int��, prices(������), �������� ����(���� ���� �����ᰡ ��Ʈ�� ��ġ)
priority_queue<int, vector<int>, greater<int>> pq;


int main() {

	Input();
	SearchMaxPay();
	Output();
	return 0;
}

void Input() {
	cin >> universityNum;

	for (int i = 0; i < universityNum; i++) {
		cin >> pay >> day;
		v.push_back({ day, pay }); // day(����)�� �������� �������� ����
	}
	sort(v.begin(), v.end());
}

// priority queue �������� ���� �������� �ִ��� ã��
void SearchMaxPay() {
	for (int i = 0; i < universityNum; i++) {
		pq.push(v[i].second);// �� ���� ���Ѻ��� ������ �ϴ� �ֱ�(�������� ���ĵ�)
		// ���� pq ������� ���� ������ ũ�� 'd�� �ȿ� �ͼ�' ��� ������ ������ �� �����Ƿ�
		// ���� �ּҰ��� ����, �� ū���� pq�� �ֱ� 
		if (pq.size() > v[i].first) {
			pq.pop();
		}
	}
}

void Output() {
	while (pq.size()) {
		maxPay += pq.top(); pq.pop();
	}
	cout << maxPay << "\n";
}