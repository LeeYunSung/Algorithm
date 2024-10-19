#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
1 2 1 3 1 0 2 3 2 1
���� �ǹ��� �� ������ �ǹ� ���� keep.
���� �ǹ��� �� ������ Out
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
		buildings.push_back(y); // ���̸� ����
	}
	buildings.push_back(0); // �������� 0 �����ؼ� ���� �� ������ ������ ������Ű��
	
	for (int i = 0; i < buildings.size(); i++) {
		buildingHeight = buildings[i];
		stk.push(buildingHeight);

		// stack�� top�� ��ġ�� ���̰� ���� ���̿� ���ų� �۾��� ������ pop����
		while (!stk.empty() && stk.top() >= buildingHeight) {
			if (stk.top() != buildingHeight) buildingCount += 1;
			stk.pop();
		}
		stk.push(buildingHeight);
	}
	cout << buildingCount << "\n";

	return 0;
}