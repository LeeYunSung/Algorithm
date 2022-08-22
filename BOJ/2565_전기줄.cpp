#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct LINE {
	int left;
	int right;
	int longCount;
};

bool compare(LINE line1, LINE line2) {
	return (line1.left < line2.left) ? true : false;
}

int main() {
	int lineNum = 0;
	int longestCount = 0;
	vector<LINE> lines;
	cin >> lineNum;

	//전기줄 정보 입력받기
	for (int i = 0; i < lineNum; i++) {
		LINE line;
		cin >> line.left >> line.right;
		line.longCount = 1;
		lines.push_back(line);
	}
	
	//어디가 꼬였는지 보기 쉽게 순서대로 정렬 
	sort(lines.begin(), lines.end(), compare);

	//오른쪽 값을 가장 긴 오름차순으로 정렬하는데 방해하는 라인을 없애면 됨.
	for (int i = 0; i < lineNum; i++) {
		for (int j = 0; j < i; j++) {
			if (lines[j].right < lines[i].right) {
				if (lines[j].longCount + 1 > lines[i].longCount) {
					lines[i].longCount = lines[j].longCount + 1;
				}
			}
		}
		if (longestCount < lines[i].longCount) longestCount = lines[i].longCount;
	}
	cout << lineNum - longestCount;

	return 0;
}