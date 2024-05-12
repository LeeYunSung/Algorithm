#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


// ����Ҹ� �� ���������� ǥ���ϱ� ���� ���� ����ü. �ִ� 15���� �����
struct Food {
	int protein, fat, carbohydrate, vitamin, cost;
} foods[15];

// Input: ���� ��, ������ �� ����� �ּҰ�
int foodNum;
int proteinMin, fatMin, carbohydrateMin, vitaminMin;

// Output: ���� ������: �ּҺ��, �����Ʈ
int minCost = INT_MAX;
map<int, vector<vector<int>>> results;//���� ����� ���� �������� �� ���������� ������ ã������ ���� map ���

void Input();
void SearchFoodCombi();
void PrintFoodCombi();


int main() {

	Input();
	SearchFoodCombi();
	PrintFoodCombi();

	return 0;
}

// ������ �Է¹ޱ�
void Input() {
	cin >> foodNum;
	cin >> proteinMin >> fatMin >> carbohydrateMin >> vitaminMin;
	for (int i = 0; i < foodNum; i++) {
		cin >> foods[i].protein >> foods[i].fat >> foods[i].carbohydrate >> foods[i].vitamin >> foods[i].cost;
	}
}

// ��Ʈ����ũ�� ����Ž��
void SearchFoodCombi() {
	// 0 ~ 2^N ���� �ݺ�
	for (int i = 0; i < (1 << foodNum); i++) {
		int proteins = 0, fats = 0, carbohydrates = 0, vitamins = 0, costs = 0;
		vector<int> v;// ���õ� �����
		// �ش� ��� �߿��� ������ ������� �� ���ϱ�
		for (int j = 0; j < foodNum; j++) {
			if (i & (1 << j)) {// ex. 000001 & 000001 = 000001(1�� ����� ����)
				v.push_back(j + 1);
				proteins += foods[j].protein;
				fats += foods[j].fat;
				carbohydrates += foods[j].carbohydrate;
				vitamins += foods[j].vitamin;
				costs += foods[j].cost;
			}
		}
		// �ּ� ����� ����ġ �Ѵ��� Ȯ��
		if (proteins >= proteinMin && fats >= fatMin && carbohydrates >= carbohydrateMin && vitamins >= vitaminMin) {
			// �ּҺ������ Ȯ�� �� ����
			if (costs <= minCost){
				minCost = costs;
				results[costs].push_back(v); // �ش� cost�� ������ ���� ����.
			}
		}
	}
}

// ���� ���, ���� ���� ���
void PrintFoodCombi() {
	// minCost �� ������ �ȵ����� ���úҰ��� ���
	if (minCost == INT_MAX) {
		cout << -1 << "\n";
	}
	// cost, ������ ����� ����Ʈ ���.
	else {
		// ��������� ���߱� ���� �������� ����
		cout << "\n\n";
		sort(results[minCost].begin(), results[minCost].end());
		cout << minCost << "\n";
		for (int foodNum : results[minCost][0]) {
			cout << foodNum << " ";
		}
	}
}