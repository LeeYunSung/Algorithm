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

	//������ ���� �Է¹ޱ�
	for (int i = 0; i < lineNum; i++) {
		LINE line;
		cin >> line.left >> line.right;
		line.longCount = 1;
		lines.push_back(line);
	}
	
	//��� �������� ���� ���� ������� ���� 
	sort(lines.begin(), lines.end(), compare);

	//������ ���� ���� �� ������������ �����ϴµ� �����ϴ� ������ ���ָ� ��.
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