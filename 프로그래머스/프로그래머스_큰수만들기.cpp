#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k);

int main() {
	string number = "";
	int k = 0;

	cin >> number >> k;
	cout << solution(number, k);

	return 0;
}

string solution(string number, int k) {
	string answer = "";

	for (int i = 0; i < number.length(); i++) {
		while (!answer.empty() && answer.back() < number[i] && k > 0) { //���� ��
			answer.pop_back();//answer�� ���� ������ ���� ���� �� ũ�ٸ� answer�� ������ ����
			k--;
		}
		if (k == 0) {
			answer += number.substr(i, number.length() - i);//���̻� �� �� ������ �ڿ� �ִ� ������ ���ڵ� �� �־��ֱ�
			break;
		}
		answer.push_back(number[i]);//���� �߰�
	}
	return answer.substr(0, answer.length() - k); //�̹� ���ĵǾ� �־ ���� ������ ���ߴٸ�, answer���� �ڿ� ���ڵ� ���ְ� ����ϱ�.
}