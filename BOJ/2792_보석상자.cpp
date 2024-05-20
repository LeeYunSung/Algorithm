#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int childrenNum, colorNum, input;
int minNum = 1, maxNum = 0;
vector<int> colors;

int GetJealousy();

int main() {

	cin >> childrenNum >> colorNum;
	for (int i = 0; i < colorNum; i++) {
		cin >> input;
		colors.push_back(input);
		maxNum = max(maxNum, input);
	}

	cout << GetJealousy() << "\n";

	return 0;
}

int GetJealousy() {
	int jealousy = 0;

	while (minNum <= maxNum) {
		int mid = (minNum + maxNum) / 2;
		int divideNum = 0;

		for (int color : colors) {
			if (color % mid) divideNum += (color / mid) + 1;
			else divideNum += (color / mid); 
		}

		if (divideNum <= childrenNum) { 
			jealousy = mid;
			maxNum = mid - 1;
		}
		else minNum = mid + 1;  
	}
	return jealousy;
}
