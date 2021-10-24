#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main() {
	int height, width, input;
	cin >> height >> width;

	vector<int> v;
	for (int i = 0; i < width; i++) {
		cin >> input;
		v.push_back(input);
	}
	
	int rain = 0;
	if (width >= 3) {
		for (int i = 1; i < width - 1; i++) {//맨끝은 벽이던 빗물칸이던 빗물값에 포함시킬 수 없음.
			int leftBlock = 0, rightBlock = 0;
			//현재 위치에서 왼쪽 탐색하기
			for (int j = i - 1; j >= 0; j--) {
				if (v[j] > v[i]) {
					leftBlock = max(leftBlock, v[j] - v[i]);//3
				}
			}
			//현재 위치에서 오른쪽 탐색하기
			for (int j = i + 1; j < width; j++) {
				if (v[j] > v[i]) {
					rightBlock = max(rightBlock, v[j] - v[i]);//4
				}
			}
			if (leftBlock != 0 && rightBlock != 0) {
				rain += min(leftBlock, rightBlock);//3
			}
		}
	}
	cout << rain;
}