#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> person1 = { 1, 2, 3, 4, 5 }; //5
	vector<int> person2 = { 2, 1, 2, 3, 2, 4, 2, 5 }; //8
	vector<int> person3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }; //10
	vector<int> answerNum(3);

	//1. person�� �ݺ��� ���鼭 answer���̶� ���ϱ�
	//2. ����� �ٸ��ϱ� answer ���̸�ŭ ��� size�� ���� ������ index�� �̵��ϸ� �ݺ�
	for (int i = 0; i < answers.size(); i++) {
		if (person1[i%person1.size()] == answers[i]) answerNum[0]++;
		if (person2[i%person2.size()] == answers[i]) answerNum[1]++;
		if (person3[i%person3.size()] == answers[i]) answerNum[2]++;
	}

	//3. ���� ���� ���� ��� ã��
	int maxValue = *max_element(answerNum.begin(), answerNum.end());
	for (int i = 0; i <= answerNum.size(); i++) {
		if (answerNum[i] == maxValue) answer.push_back(i + 1);
	}

	return answer;
}