#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Home {
	int x;
	int y;
	int distance = INT_MAX;//ġŲ�Ÿ�
};

struct Chicken {
	int x;
	int y;
};

int CalculateChickenDistance(int& chickenNum, vector<Home>& homes, vector<Chicken>& chickens);

int main() {
	int mapSize, chickenNum, input;
	vector<vector<int>> map;
	vector<Home> homes;
	vector<Chicken> chickens;

	cin >> mapSize >> chickenNum;

	for (int i = 0; i < mapSize; i++) {
		vector<int> rowMap;
		for (int j = 0; j < mapSize; j++) {
			cin >> input;
			rowMap.push_back(input);
			if (input == 1) {
				Home home;
				home.x = i;
				home.y = j;
				homes.push_back(home);
			}
			else if (input == 2) {
				Chicken chicken;
				chicken.x = i;
				chicken.y = j;
				chickens.push_back(chicken);
			}
		}
		map.push_back(rowMap);
	}
	cout <<  CalculateChickenDistance(chickenNum, homes, chickens) << "\n";

	return 0;
}

int CalculateChickenDistance(int& chickenNum, vector<Home>& homes, vector<Chicken>& chickens) {
	
	int minDistance = INT_MAX;

	//������ ���� ���ͺ���. 1�� ����, 0�� �ȼ���.
	vector<int> checkVector(chickens.size(), 0);
	for (int i = 0; i < chickenNum; i++) checkVector[i] = 1; 

	do {
		int distanceSum = 0;
		for (int i = 0; i < homes.size(); i++){
			for (int j = 0; j < chickens.size(); j++) {
				if (checkVector[j] == 1) {
					int distance = abs(homes[i].x - chickens[j].x) + abs(homes[i].y - chickens[j].y);
					if (homes[i].distance > distance) homes[i].distance = distance;
				}
			}
			distanceSum += homes[i].distance;
		}
		if (minDistance > distanceSum) minDistance = distanceSum;
		//���� ġŲ�Ÿ��� �ٽ� ���ؾ� �ϹǷ� ���� �ִ밪���� �ʱ�ȭ.
		for (int i = 0; i < homes.size(); i++) homes[i].distance = INT_MAX;
	} while (prev_permutation(checkVector.begin(), checkVector.end()));

	return minDistance;
}