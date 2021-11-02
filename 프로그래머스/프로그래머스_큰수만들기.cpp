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
		while (!answer.empty() && answer.back() < number[i] && k > 0) { //숫자 비교
			answer.pop_back();//answer에 넣은 수보다 현재 수가 더 크다면 answer에 넣은거 빼기
			k--;
		}
		if (k == 0) {
			answer += number.substr(i, number.length() - i);//더이상 뺄 수 없으면 뒤에 있는 나머지 숫자들 다 넣어주기
			break;
		}
		answer.push_back(number[i]);//숫자 추가
	}
	return answer.substr(0, answer.length() - k); //이미 정렬되어 있어서 빼는 연산을 안했다면, answer에서 뒤에 숫자들 빼주고 출력하기.
}