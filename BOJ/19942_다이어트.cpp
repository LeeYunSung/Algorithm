#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


// 영양소를 더 가시적으로 표현하기 위한 음식 구조체. 최대 15개의 식재료
struct Food {
	int protein, fat, carbohydrate, vitamin, cost;
} foods[15];

// Input: 음식 수, 기준이 될 영양소 최소값
int foodNum;
int proteinMin, fatMin, carbohydrateMin, vitaminMin;

// Output: 정답 변수들: 최소비용, 정답비트
int minCost = INT_MAX;
map<int, vector<vector<int>>> results;//정답 경우의 수가 여러개일 때 사전순으로 빠른걸 찾기위기 위해 map 사용

void Input();
void SearchFoodCombi();
void PrintFoodCombi();


int main() {

	Input();
	SearchFoodCombi();
	PrintFoodCombi();

	return 0;
}

// 데이터 입력받기
void Input() {
	cin >> foodNum;
	cin >> proteinMin >> fatMin >> carbohydrateMin >> vitaminMin;
	for (int i = 0; i < foodNum; i++) {
		cin >> foods[i].protein >> foods[i].fat >> foods[i].carbohydrate >> foods[i].vitamin >> foods[i].cost;
	}
}

// 비트마스크로 완전탐색
void SearchFoodCombi() {
	// 0 ~ 2^N 까지 반복
	for (int i = 0; i < (1 << foodNum); i++) {
		int proteins = 0, fats = 0, carbohydrates = 0, vitamins = 0, costs = 0;
		vector<int> v;// 선택된 식재료
		// 해당 경우 중에서 선택한 식재료의 값 더하기
		for (int j = 0; j < foodNum; j++) {
			if (i & (1 << j)) {// ex. 000001 & 000001 = 000001(1번 식재료 선택)
				v.push_back(j + 1);
				proteins += foods[j].protein;
				fats += foods[j].fat;
				carbohydrates += foods[j].carbohydrate;
				vitamins += foods[j].vitamin;
				costs += foods[j].cost;
			}
		}
		// 최소 영양소 기준치 넘는지 확인
		if (proteins >= proteinMin && fats >= fatMin && carbohydrates >= carbohydrateMin && vitamins >= vitaminMin) {
			// 최소비용인지 확인 후 갱신
			if (costs <= minCost){
				minCost = costs;
				results[costs].push_back(v); // 해당 cost에 선택한 조합 저장.
			}
		}
	}
}

// 음식 비용, 음식 조합 출력
void PrintFoodCombi() {
	// minCost 가 변경이 안됐으면 선택불가의 경우
	if (minCost == INT_MAX) {
		cout << -1 << "\n";
	}
	// cost, 선택한 식재료 리스트 출력.
	else {
		// 출력조건을 맞추기 위한 오름차순 정렬
		cout << "\n\n";
		sort(results[minCost].begin(), results[minCost].end());
		cout << minCost << "\n";
		for (int foodNum : results[minCost][0]) {
			cout << foodNum << " ";
		}
	}
}