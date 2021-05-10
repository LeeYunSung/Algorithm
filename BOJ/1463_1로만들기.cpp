#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int num = 0;
	cin >> num;
	int *num_array = new int[num + 1]{0, }; //memorization

	for (int i = 2; i < num + 1; i++) { //Bottom-up ������� ���� ���� 2���� ���� ���ذ��鼭 �� ���� �̿��ؼ� ū ���� num�� ���� ����
		num_array[i] = num_array[i - 1] + 1; 
		if (i % 3 == 0) { 
			num_array[i] = min(num_array[i], num_array[i / 3] + 1); 
		}
		if (i % 2 == 0) { 
			num_array[i] = min(num_array[i], num_array[i / 2] + 1); 
		}
	}
	cout << num_array[num];

	delete[] num_array;
}