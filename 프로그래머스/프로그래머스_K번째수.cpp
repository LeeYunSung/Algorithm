#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	//��� ������ŭ �ݺ�
	for (int i = 0; i < commands.size(); i++) {

		//��ɾ� �� �������� ����
		int beginIndex = commands[i][0];
		int endIndex = commands[i][1];
		int answerIndex = commands[i][2];

		//beginInde ~ endIndex���� �� ����
		vector<int> partArray(array.begin() + beginIndex - 1, array.begin() + endIndex);

		//�������� ����
		sort(partArray.begin(), partArray.end());

		//K��° �� ����
		answer.push_back(partArray[answerIndex - 1]);
	}

	return answer;
}