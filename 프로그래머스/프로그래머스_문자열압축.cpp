#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string s);

int main() {
	string character = "";
	cin >> character;
	cout << solution(character);
}

int solution(string original_string) {
	//�ּ� ���� �� ã������ �ϴ� �ִ� ����(���� character����)�� �־��
	int answer_length = original_string.size();

	//���ڿ��� 1�� ~ ���ڿ�/2�� �������� ���డ��
	for (int unit = 1; unit <= original_string.length() / 2; unit++) {
		string compressed_string;//����� ����
		string compare_string;//�������� ������ ���ڿ�
		int compressed_count = 1;//�����ϰ� �տ� ���� ����� ����

		compare_string = original_string.substr(0, unit);//�� ù���ں��� ���� ���������� �� ���ڿ��� ����
		for (int index = unit; index < original_string.length(); index += unit) {//�� ���ڿ� ���� ���ڿ����� ��� ���س�����.
			if (compare_string == original_string.substr(index, unit)) {//�� ���ڿ��� ���� ���ڿ��� ���ٸ�
				compressed_count++;//���� �����ϹǷ� compressed_count�� 1 �÷���
			} 
			else {//�ٸ��� ���� �Ұ���. ������� ����� ������ �տ� �����ְ� ���� ���డ�ɿ��θ� Ž���ؾ� ��.
				if (compressed_count > 1) {//compressed_count�� 1���� ũ�ٸ� ����� ���̹Ƿ�
					compressed_string += to_string(compressed_count);//�տ� copressed_count�� ������.
				}
				compressed_string += compare_string;//���� ���� ���ڿ��� ������
				compare_string = original_string.substr(index, unit);//���� �񱳹��ڷ� index�� �ű�� �ٽ� �� ����
				compressed_count = 1;//�ٽ� �����ؾ��ϹǷ� copressed_count�� 1�� �ʱ�ȭ ������.
			}
		}

		//���� �� ù���ں��� ������ ���ߴµ�, ������ �Ұ����� ��찡 ���ٸ� copressed_count�� �����������״�, ���� �����ֱ�.
		if (compressed_count > 1) {
			compressed_string += to_string(compressed_count);
		}

		//�ּҰ� ã��
		compressed_string += compare_string;
		answer_length = min(answer_length, (int)compressed_string.length());//��size()�� ���������� size_t �� ��ȯ��. ����!
	}
	return answer_length;
}