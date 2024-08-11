#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	string name; // input �̸�
	int alphabet[26] = { 0, }; // ���ĺ� ī��Ʈ
	int oddCount = 0; // Ȧ�� ���ĺ� ī��Ʈ(��������)

	cin >> name;
	for (int i = 0; i < name.size(); i++) {
		alphabet[name[i] - 'A']++;
	}

	// Ȧ�� ���ĺ� ���� ã��
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > 0) {
			if (alphabet[i] % 2 == 1) {
				oddCount++;
			}
		}
	}

	// Ȧ�� ���ĺ��� 2 �̻��̸� �Ӹ���� �Ұ�
	if (oddCount > 1) {
		cout << "I'm Sorry Hansoo\n";
	}
	else {
		string outputName = "";

		// �տ� ���ڿ� �� �ֱ�
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < alphabet[i] / 2; j++) {
				outputName += i + 'A';
			}
		}
		// ���µ� ���ڿ� �ֱ�
		for (int i = 0; i < 26; i++) {
			if (alphabet[i] % 2 != 0) {
				outputName += i + 'A';
			}
		}
		// �ڿ� ���ڿ� �� �ֱ�
		for (int i = 25; i >= 0; i--) {
			for (int j = 0; j < alphabet[i] / 2; j++) {
				outputName += i + 'A';
			}
		}
		cout << outputName << "\n";
	}

	return 0;
}