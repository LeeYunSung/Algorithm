#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

void MakeBracket(int index, int curSum);//index: ���ڿ� �ε���, curSum: ������� ����� ��
int Calculate(int num1, char oper, int num2);//num1 ������ num2 �� ����ϴ� �Լ�

int length; //����� ����
string str; //�Է� ���ڿ�
int maxSum = INT_MIN; //�ִ밪. �ִ밪�� -���� ���� ���� ����.

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
	
	//��ȣ�� ���� ��, "��������� ������ ��ȣ��" ���. �����ڿ� ��ȣ������ index 4���� ��������Ƿ� index 4ĭ �̵�
	if (index + 2 < length) {
		int bracket = Calculate(str[index] - '0', str[index + 1], str[index + 2] - '0');
		MakeBracket(index + 4, Calculate(curSum, oper, bracket));
	}
	//��ȣ�� �ȹ��� ��, "��������� ������ ����" ���. �����ڿ� ���������� index 2���� ��������Ƿ� index 2ĭ �̵�
	MakeBracket(index + 2, Calculate(curSum, oper, str[index] - '0'));
}

int Calculate(int num1, char oper, int num2) {//num1 ������ num2 �� �����
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
