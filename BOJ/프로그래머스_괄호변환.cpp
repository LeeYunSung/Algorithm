#include <string>
#include <iostream>
using namespace std;

bool isCorrectString(string balanace_string) {
	if (balanace_string == "") return true;

	int check = 0; // ( �� +1�� )�� -1�� ǥ���ؼ� ��ȣ����Ȯ���� ���� �ùٸ� ��ȣ���ڿ������� �Ǵ��Ѵ�.
	for (int i = 0; i < balanace_string.length(); i++) {
		if (check < 0) return false; //�ѹ��̶� ������ �Ǹ� )��ȣ�� ���� ���� ���̹Ƿ� false�� �����Ѵ�.
		check += (balanace_string[i] == '(') ? 1 : -1;
	}return check == 0 ? true : false; //�������� check ������ 0�� �Ǹ� �ùٸ� ��ȣ���ڿ��� ��!
}

int returnBalanceStringIndex(string original_string) {
	int check = 0; // ( �� +1�� )�� -1�� ǥ���ؼ� ��ȣ����Ȯ���� ���� �ùٸ� ��ȣ���ڿ������� �Ǵ��Ѵ�.
	for (int i = 0; i < original_string.length(); i++) {
		check += (original_string[i] == '(') ? 1 : -1;
		if (check == 0) return i;
	}return original_string.length();
}

string solution(string original_string) {	
	//1. �Է��� �� ���ڿ��̰ų� �ùٸ� ���ڿ��� ���, �״�� ��ȯ
	if (original_string == "" || isCorrectString(original_string)) {
		return original_string; 
	}

	//�Է� ���ڿ��� �ùٸ� ���ڿ��� �ƴ϶� ��ȣ ��ȯ�� �ʿ��� ���
	//2. ���ڿ��� �� "�������� ��ȣ ���ڿ�" balance_string1, balance_string2�� �и�
	string balance_string1 = "", balance_string2 = "";
	balance_string1 = original_string.substr(0, returnBalanceStringIndex(original_string) + 1);
	balance_string2 = original_string.substr(balance_string1.length());

	//3. ���ڿ� balance_string1�� "�ùٸ� ��ȣ ���ڿ�" �̶�� ���ڿ� balance_string2�� ���� 1�ܰ���� �ٽ� ����
	if (isCorrectString(balance_string1)) {
		//3-1. ������ ��� ���ڿ��� balance_string1�� �̾� ���� �� ��ȯ
		balance_string1 += solution(balance_string2);
		return balance_string1;
	}
	
	//4. ���ڿ� balance_string1�� "�ùٸ� ��ȣ ���ڿ�"�� �ƴ϶�� �Ʒ� ������ ����
	else {
		string correct_string = "";

		//4 - 1. �� ���ڿ��� ù ��° ���ڷ� '('�� ����
		correct_string += "(";

		//4 - 2. ���ڿ� balance_string2�� ���� 1�ܰ���� ��������� ������ ��� ���ڿ��� �̾� ����
		correct_string += solution(balance_string2);

		//4 - 3. ')'�� �ٽ� ����
		correct_string += ")";

		//�� 4 - 4. balance_string1�� ù ��°�� ������ ���ڸ� �����ϰ�, ������ ���ڿ��� ��ȣ ������ ����� �ڿ� ����
		balance_string1 = balance_string1.substr(1, balance_string1.length() - 2);

		for (int i = 0; i < balance_string1.length(); i++) {
			balance_string1[i] = (balance_string1[i] == '(') ? ')' : '(';
		}
		correct_string += balance_string1;

		//4 - 5. ������ ���ڿ��� ��ȯ
		return correct_string;
	}
}

//test�� �ڵ� �߰�..
int main() {
	string original_string = "";
	cin >> original_string;
	cout << solution(original_string);
}