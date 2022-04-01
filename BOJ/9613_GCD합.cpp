/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void SelectTwoNum(vector<int> num_vector);//�ִ������� ���ϱ����� �� ���� �����ϴ� �Լ�
int CalculateGCD(int a, int b);//�������� ���ؼ� �ִ������� ���� �Լ�

//���������� ���� ���ǹ� �Լ�
bool lower(int a, int b) {
	return (a > b);
}

int main() {
	int test_case = 0, num_count = 0, num = 0;//�׽�Ʈ ���̽� ��, �� �ٴ� �Է¹޴� ��, �� �ٿ� �ԷµǴ� ���ڵ�(���Ϳ� ��������)
	vector<int> num_vector;//�� �ٿ� �Էµ� ���ڵ��� ���� ����

	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		cin >> num_count;
		for (int j = 0; j < num_count; j++) {
			cin >> num;
			num_vector.push_back(num);
		}
		if (num_count >= 2) {//�� �ٿ� �Էµ� ���� 2 �̻��̸� �ִ������� ���Ϸ� ��. 1�� �̸� �� ���� �� �ִ�����.
			sort(num_vector.begin(), num_vector.end(), lower);//�׻� ū���� ���� ���� ������ ������������ ������. 
			SelectTwoNum(num_vector);//����� ���� ���ؾ� �ؼ� 2���� ���ڸ� ������ ����.
			num_vector.clear();//���ڸ� �ٽ� �޾ƾ� �ϹǷ� num_vector �ʱ�ȭ
		}
		else cout << num_vector.front() << "\n";
	}
	return 0;
}

void SelectTwoNum(vector<int> num_vector) {
	vector<int> check_vector;//0�� 1�� �̿��ؼ� 2���� �̴� ����� ���� ã�� ���� ����
	vector<int> selected_num;//���õ� �� ���� ���� ����
	long long sum = 0;

	for (int i = 0; i < 2; i++) { check_vector.push_back(1); }//1�� 2�� �־��ְ�(���õ� �ε��� ǥ��)
	for (int i = 0; i < num_vector.size() - 2; i++) { check_vector.push_back(0); }//�������� 0����.(���� �ȵ� �ε��� ǥ��)
	sort(check_vector.begin(), check_vector.end());//���� ������ ������ ���ؾ� �ϹǷ� �������� ����. �߰��� ��� ��� ���� ��� ����� ���� ���ϱ� ����.

	do {
		for (int i = 0; i < num_vector.size(); i++) {
			if (check_vector[i]){//���õ� �ε����� selected_num�� �߰�����.
				selected_num.push_back(num_vector[i]);
				if (selected_num.size() > 1) {//���õ� ���� 2���� �ִ����� ���Ϸ� ������.
					sum += CalculateGCD(selected_num.front(), selected_num.back());//���� �յ��� ����
					selected_num.clear();//���ڸ� �ٽ� �����ؾ� �ϹǷ� selected_num���� clear.
					break;
				}
			}
		}
	} while (next_permutation(check_vector.begin(), check_vector.end()));//���� 2���� �̴� ����� ���� �ִ��� Ȯ��. ������ �ݺ��� ��� ����.
	cout << sum << "\n";
}

int CalculateGCD(int a, int b) {//�ִ� �����
	if (a%b == 0) {
		return b;
	}
	return CalculateGCD(b, a%b);//��Ŭ���� ȣ���� GCD(a, b) = GCD(b, a%b)���� �̿�
}
*/


#include <iostream>
#include <vector>
using namespace std;

int CalculateGCD(int a, int b);

int main() {
	int test_case, num_count, num;
	cin >> test_case;

	while (test_case--) {
		vector<int> num_vector;

		cin >> num_count;
		for (int i = 0; i < num_count; i++) {
			cin >> num;
			num_vector.push_back(num);
		}
		long long sum = 0;

		for (int i = 0; i < num_count; i++) {
			for (int j = i+1; j < num_count; j++) {
				sum += CalculateGCD(num_vector[i], num_vector[j]);
			}
		}
		cout << sum << "\n";
		num_vector.clear();
	}
	return 0;
}

int CalculateGCD(int a, int b) {
	if (a%b == 0) {//�� �������� ū���� ������ �������ɱ�...
		return b;
	}
	return CalculateGCD(b, a%b);
}
