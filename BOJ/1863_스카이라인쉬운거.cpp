#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
1 2 1 3 1 0 2 3 2 1
다음 건물이 더 높으면 건물 높이 keep.
다음 건물이 더 낮으면 Out
*/
int main() {
	int buildingHeightNum, buildingHeight;
	int buildingCount = 0; // answer
	stack<int> stk;
	vector<int> buildings;

	cin >> buildingHeightNum;

	int x, y;
	for (int i = 0; i < buildingHeightNum; i++) {
		cin >> x >> y;
		buildings.push_back(y); // 높이만 저장
	}
	buildings.push_back(0); // 마지막에 0 저장해서 낮을 때 뺀다의 조건을 만족시키기
	
	for (int i = 0; i < buildings.size(); i++) {
		buildingHeight = buildings[i];
		stk.push(buildingHeight);

		// stack의 top에 위치한 높이가 현재 높이와 같거나 작아질 때까지 pop수행
		while (!stk.empty() && stk.top() >= buildingHeight) {
			if (stk.top() != buildingHeight) buildingCount += 1;
			stk.pop();
		}
		stk.push(buildingHeight);
	}
	cout << buildingCount << "\n";

	return 0;
}