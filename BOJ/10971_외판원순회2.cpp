#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void SearchCity(int startCity, int currentCity, int costSum, int count, vector<vector<int>> visitedCityArr, vector<bool> visitedCityVector);
int leastCost = INT_MAX;

int main() {
	int cityNum, input;
	cin >> cityNum;

	vector<vector<int>> cityVector(cityNum, vector<int>(cityNum, 0));
	vector<bool> visitedCityArr(cityNum, false);

	for (int i = 0; i < cityNum; i++) {
		for (int j = 0; j < cityNum; j++) {
			cin >> cityVector[i][j];
		}
	}

	//탐색 gogo
	for (int city = 0; city < cityNum; city++) {
		SearchCity(city, city, 0, 0, cityVector, visitedCityArr);
	}
	cout << leastCost;

	//동적할당 해제
	for (int i = 0; i < cityNum; i++) {
		cityVector[i].clear();
	} cityVector.clear();
	visitedCityArr.clear();

	return 0;
}

void SearchCity(int startCity, int currentCity, int costSum, int count, vector<vector<int>> cityVector, vector<bool> visitedCityVector) {
	if (currentCity == startCity && count == cityVector.size()) {
		if (leastCost > costSum) leastCost = costSum;
		return;
	}
	for (int nextCity = 0; nextCity < cityVector.size(); nextCity++) {
		if (cityVector[currentCity][nextCity] != 0 && !visitedCityVector[currentCity]) {
			visitedCityVector[currentCity] = true;
			costSum += cityVector[currentCity][nextCity];

			if (leastCost >= costSum) SearchCity(startCity, nextCity, costSum, count + 1, cityVector, visitedCityVector);

			visitedCityVector[currentCity] = false;
			costSum -= cityVector[currentCity][nextCity];
		}
	}
}
