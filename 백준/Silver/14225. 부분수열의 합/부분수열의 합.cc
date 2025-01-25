#include <iostream>
#include <vector>
using namespace std;

int numCount, numList[21];
bool sumList[20 * 100000 + 1];

void searchSum(int curIndex, int curSum);

int main() {
	cin >> numCount;
	for (int i = 0; i < numCount; i++) {
		cin >> numList[i];
	}

	searchSum(0, 0);
	
	for (int i = 0; i < sizeof(sumList)/sizeof(bool); i++) {
		if (!sumList[i]) {
			cout << i << "\n";
			break;
		}
	}
	return 0;
}

void searchSum(int curIndex, int curSum){
	if (curIndex > numCount) return;
	
	sumList[curSum] = true;

	searchSum(curIndex + 1, curSum + numList[curIndex]);
	searchSum(curIndex + 1, curSum);
}