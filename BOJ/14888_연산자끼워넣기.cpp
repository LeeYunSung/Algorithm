#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h> //�ڷ����� �ִ񰪰� �ּڰ��� ���ǵ� ��� ����
using namespace std;

void calculation(vector<int>&, vector<int>&);

int main() {
	int N = 0;
	vector<int> nums; // 1, 2, 3, 4, 5
	vector<int> operators; // +, -, x, ��

	cin >> N;
	for (int i = 0; i < N; i++) {//�������� �־����� ���� �ޱ�
		int x = 0;
		cin >> x;
		nums.push_back(x);
	}
	for (int i = 0; i < 4; i++) {//�����ڸ� +, -, x, �� �ڸ��� �°� 0,1,2,3 ���� ǥ���� ��ü ���͸� �����.
		int x = 0;
		cin >> x;
		if (x != 0) {
			for (int j = 0; j < x; j++) {
				operators.push_back(i);
			}
		}		
	}
	calculation(nums, operators);
}

void calculation(vector<int>& nums, vector<int>& operators) {
	int min_val = INT_MAX; //���ϱ� ���� INT���� �ִ밪 2147483647 �� ����
	int max_val = INT_MIN; //INT���� �ּҰ� -2147483648 �� ����

	do{
		int value = nums[0]; //�켱 �� ���� ���ڸ� value�� �ְ�
		for (int i = 0; i < operators.size(); i++) { //�ں��ʹ� �����ڸ� �̿��ؼ� ����ؼ� �ִ´�.
			switch (operators[i]) {//ù��° �����ں��� ���� ����
				case 0: //�����ڰ� +�� ��
					value += nums[i+1];
					break;
				case 1: //�����ڰ� -�� ��
					value -= nums[i+1];
					break;
				case 2: //�����ڰ� x�� ��
					value *= nums[i+1];
					break;
				case 3: //�����ڰ� ���� ��
					value /= nums[i+1];
					break;
			}
		}
		//�ִ밪, �ּҰ� ����. ���� ���� �����Ƿ� �Ѵ� if������ ó��
		if (value < min_val) min_val = value;
		if (value > max_val) max_val = value;

	} while (next_permutation(operators.begin(), operators.end()));

	cout << max_val << "\n";
	cout << min_val << "\n";
}