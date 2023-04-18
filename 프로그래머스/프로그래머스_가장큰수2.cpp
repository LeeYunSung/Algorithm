#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(string &a, string &b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer;
	vector<string> stringNumbers;

	//���ڿ� �񱳸� ���� ���� ���� -> ���ڿ� ���Ϳ� �־�α�
	for (int i = 0; i < numbers.size(); i++) {
		stringNumbers.push_back(to_string(numbers[i]));
	}

	//���ϸ� ū ������� ����
	sort(stringNumbers.begin(), stringNumbers.end(), compare);

	//���� ��ġ��
	for (int i = 0; i < stringNumbers.size(); i++) {
		answer += stringNumbers[i];
	}

	//���� 0���� �̷���� �����̸� 0�� �����ϱ�
	if (answer[0] == '0') return "0";
	return answer;
}