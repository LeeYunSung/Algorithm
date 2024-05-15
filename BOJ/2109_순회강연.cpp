#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int universityNum, pay, day, maxPay = 0;

// 기한, 강연료 조합을 일단 모두 담을 벡터
vector<pair<int, int>> v;

// int형, prices(강연료), 오름차순 정렬(가장 적은 강연료가 루트에 위치)
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
		v.push_back({ day, pay }); // day(기한)를 기준으로 오름차순 정렬
	}
	sort(v.begin(), v.end());
}

// priority queue 오름차순 정렬 버전으로 최대비용 찾기
void SearchMaxPay() {
	for (int i = 0; i < universityNum; i++) {
		pq.push(v[i].second);// 앞 일자 기한부터 강연료 일단 넣기(오름차순 정렬됨)
		// 현재 pq 사이즈보다 일자 기한이 크면 'd일 안에 와서' 라는 조건을 만족할 수 없으므로
		// 맨위 최소값을 빼고, 더 큰값을 pq에 넣기 
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