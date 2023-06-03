#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	int priority_index = 0;

	//�ε����� �����ϰ� �ִ� ���� ����
	vector<int> index_vector;
	for (int i = 0; i < priorities.size(); i++) {
		index_vector.push_back(i);
	}

	//���μ��� ������
	while (1) {
		//���� ó�� ���� �켱���� �ε��� ����
		priority_index = max_element(priorities.begin(), priorities.end()) - priorities.begin();
		//�켱���� �ε����� �� ������ �� �ڷ� ������
		for (int i = 0; i < priority_index; i++) {
			priorities.push_back(priorities.front());
			priorities.erase(priorities.begin());

			//�ε��� ���� ���� �ڷ� ������
			index_vector.push_back(index_vector.front());
			index_vector.erase(index_vector.begin());
		}
		//�켱���� �ε��� ������
		priorities.erase(priorities.begin());
		//���������� ī��Ʈ ����
		answer++;

		//location���� ������ ���μ��� ����
		if (location == index_vector.front()) break;
		//location���� �ƴϸ� ���� ���μ��� ����
		index_vector.erase(index_vector.begin());
	}

	return answer;
}