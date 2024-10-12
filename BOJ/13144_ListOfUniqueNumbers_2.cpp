#include <iostream>
#include <vector>
using namespace std;

int main() {
	int numCount, num;
	long long probability = 0;
	vector<int> numList;	// �Է����� �־����� ���ӵ� ���� ����Ʈ
	vector<bool> visited;   // �������� �̾��� �� ���� ���� ���� �ƴ��� üũ

	// Input
	cin >> numCount;
	for (int i = 0; i < numCount; i++) {
		cin >> num;
		numList.push_back(num);
		visited.push_back(false);
	}

	// ��������
	int left = 0, right = 0;
	while (left < numCount) {
		while (right < numCount) {
			if (visited[numList[right] - 1]) break;

			visited[numList[right] - 1] = true;
			right += 1;
		}
		visited[numList[left] - 1] = false;
		probability += right - left;
		left += 1;
	}

	// Output
	cout << probability << "\n";

	return 0;
}