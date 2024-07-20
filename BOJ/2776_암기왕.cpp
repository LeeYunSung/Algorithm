#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int hasNote(int num, vector<int> &noteNums);

int main() {
	int testcaseNum = 0, noteNum = 0, input = 0;
	vector<int> noteNums;

	scanf_s("%d", &testcaseNum);

	while (testcaseNum--){
		scanf_s("%d", &noteNum);
		for (int i = 0; i < noteNum; i++) {
			scanf_s("%d", &input);
			noteNums.push_back(input);
		}
		sort(noteNums.begin(), noteNums.end());

		scanf_s("%d", &noteNum);
		for (int i = 0; i < noteNum; i++) {
			scanf_s("%d", &input);
			printf("%d\n" , hasNote(input, noteNums));
		}
		noteNums.clear();
	}
	return 0;
}

int hasNote(int num, vector<int> &noteNums) {
	int low = 0, high = noteNums.size() - 1, mid;
	
	while (low <= high) {
		mid = (low + high) / 2;
		if (noteNums[mid] > num) high = mid - 1;
		else if (noteNums[mid] == num) return 1;
		else low = mid + 1;
	}
	return 0;
}