#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	//answer�� ���ϱ� ���� �������� ����. 6 5 3 1 0
	sort(citations.begin(), citations.end(), greater<int>());

	// �ִ밪�� 0�̸� 0 ���
	if (!citations[0]) { return 0; }

	//citations ���� ���鼭 h�� �̻� �ο�Ǿ����� üũ
	for (int h = 0; h < citations.size(); h++) {
		if (citations[h] > h) answer++;
		else break;
	}

	return answer;
}