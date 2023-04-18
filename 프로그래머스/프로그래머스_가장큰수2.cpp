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

	//문자열 비교를 위해 숫자 벡터 -> 문자열 벡터에 넣어두기
	for (int i = 0; i < numbers.size(); i++) {
		stringNumbers.push_back(to_string(numbers[i]));
	}

	//비교하며 큰 순서대로 정렬
	sort(stringNumbers.begin(), stringNumbers.end(), compare);

	//숫자 합치기
	for (int i = 0; i < stringNumbers.size(); i++) {
		answer += stringNumbers[i];
	}

	//값이 0으로 이루어진 배일이면 0을 리턴하기
	if (answer[0] == '0') return "0";
	return answer;
}