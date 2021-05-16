#include <iostream>
#include <string>
#include <stack>
using namespace std;

int findCorrectBracket(string);	//�ùٸ� ���ڿ����� �ƴ����� üũ�ϴ� �Լ�
string rotateString(string);	//���ڿ� ���̸�ŭ �������� �� ĭ�� ȸ���ϴ� �Լ�

int main() {
	string bracketString;
	int correctNum = 0;

	cin >> bracketString;
	for (int idx = 0; idx < bracketString.length(); idx++) {
		correctNum += findCorrectBracket(bracketString);
		bracketString = rotateString(bracketString);
	}
	cout << correctNum;
}

string rotateString(string bracketString) {
	string firstString = bracketString.substr(0, 1);
	string subString = bracketString.substr(1, bracketString.length() - 1);
	return subString + firstString;
}

int findCorrectBracket(string bracketString) {
	int correctBracketNum = 0;
	stack<char> s_openBracket;

	for (int idx = 0; idx < bracketString.length(); idx++) {
		char closedBracket;
		char currentBracket = bracketString[idx];
		//�ùٸ��� ���� ��ȣ�� ��츦 ����ó�������� �����ְ�
		//�� ���� ��츦 �ùٸ� ��ȣ��� ó��������.

		//������ȣ
		if (currentBracket == '(' || currentBracket == '{' || currentBracket == '[') {
			s_openBracket.push(currentBracket);
		}
		//������ȣ
		else {
			if (s_openBracket.empty()) { //�ٷ� ),},] ���� ������ȣ�� �����ϸ� �װ� �ùٸ� ��ȣ ���ڿ��� �ƴ�
				return 0;
			}

			switch (currentBracket) {	// (,{,[ ���� ��ȣ�� ���������� �� ���� ����ó���� ��������.
			case ')':
				if (s_openBracket.top() != '(') { //���� ��ȣ�� (�̸� �̹� ��ȣ�� )���� �ùٸ� ��ȣ����
					return 0;
				}
				break;
			case '}':
				if (s_openBracket.top() != '{') { //���� ��ȣ�� {�̸� �̹� ��ȣ�� }���� �ùٸ� ��ȣ����
					return 0;
				}
				break;
			case ']':
				if (s_openBracket.top() != '[') {	//���� ��ȣ�� [�̸� �̹� ��ȣ�� ]���� �ùٸ� ��ȣ����
					return 0;
				}
				break;
			default:
				break;
			}
			s_openBracket.pop();	//�ùٸ� ��ȣ�̸� top() �����͸� ��ĭ �Űܼ� ������ �ùٸ� ��ȣ���� üũ�غ���.
		}
	}
	if (s_openBracket.empty()) return 1;	//���������� ������� �ùٸ� ��ȣ�� �Ǵ��� �Ǿ��� �� 1�� return.
	else return 0;	// �� �������� { �ϳ��� ���Ҵٸ� �ùٸ� ��ȣ�� �ƴϴϱ� �̷� ��쵵 ����ó�� ���ֱ�.
}
