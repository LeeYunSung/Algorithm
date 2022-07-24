#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

void MakeBracket(int index, int curSum);//index: 문자열 인덱스, curSum: 현재까지 계산한 값
int Calculate(int num1, char oper, int num2);//num1 연산자 num2 를 계산하는 함수

int length; //연산식 길이
string str; //입력 문자열
int maxSum = INT_MIN; //최대값. 최대값이 -값이 나올 수도 있음.

int main() {
	cin >> length;
	cin >> str;
	
	MakeBracket(0,0);
	cout << maxSum;
	return 0;
}

void MakeBracket(int index, int curSum) {
	if (index >= length) {
		maxSum = max(maxSum, curSum);
		return;
	}
	char oper = (index == 0) ? '+' : str[index - 1];
	
	//괄호로 묶을 떄, "현재까지합 연산자 괄호값" 계산. 연산자와 괄호값으로 index 4개를 사용했으므로 index 4칸 이동
	if (index + 2 < length) {
		int bracket = Calculate(str[index] - '0', str[index + 1], str[index + 2] - '0');
		MakeBracket(index + 4, Calculate(curSum, oper, bracket));
	}
	//괄호로 안묵을 때, "현재까지합 연산자 다음" 계산. 연산자와 다음값으로 index 2개를 사용했으므로 index 2칸 이동
	MakeBracket(index + 2, Calculate(curSum, oper, str[index] - '0'));
}

int Calculate(int num1, char oper, int num2) {//num1 연산자 num2 를 계산함
	int result = num1;
	switch (oper) {
		case '+':
			result += num2;
			break;
		case '-':
			result -= num2;
			break;
		case '*':
			result *= num2;
	}
	return result;
}
