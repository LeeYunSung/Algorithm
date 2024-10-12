#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int buildingNum, maxBuildingCount = 0;
	cin >> buildingNum;

	vector<int> buildings(buildingNum, 0);
	vector<int> buildingCounts(buildingNum, 0);

	// Input
	for (int i = 0; i < buildingNum; i++) {
		cin >> buildings[i];
	}
	
	// BruteForce Algorithm
	for (int i = 0; i < buildingNum; i++) {
		double maxIncline = -9999999999;
		for (int j = i + 1; j < buildingNum; j++) {
			double incline = (double)(buildings[j] - buildings[i]) / (j - i);
			if (incline > maxIncline) {
				buildingCounts[i]++;
				buildingCounts[j]++;
				maxIncline = incline;
			}
		}
	}

	// Get Max Building count
	for (auto& count : buildingCounts) {
		maxBuildingCount = max(maxBuildingCount, count);
	}

	// Output
	cout << maxBuildingCount << "\n";

	return 0;
}