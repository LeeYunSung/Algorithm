#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main() {
	int height, width, input;
	cin >> height >> width;

	vector<int> v;
	for (int i = 0; i < width; i++) {
		cin >> input;
		v.push_back(input);
	}
	
	int rain = 0;
	if (width >= 3) {
		for (int i = 1; i < width - 1; i++) {//�ǳ��� ���̴� ����ĭ�̴� �������� ���Խ�ų �� ����.
			int leftBlock = 0, rightBlock = 0;
			//���� ��ġ���� ���� Ž���ϱ�
			for (int j = i - 1; j >= 0; j--) {
				if (v[j] > v[i]) {
					leftBlock = max(leftBlock, v[j] - v[i]);//3
				}
			}
			//���� ��ġ���� ������ Ž���ϱ�
			for (int j = i + 1; j < width; j++) {
				if (v[j] > v[i]) {
					rightBlock = max(rightBlock, v[j] - v[i]);//4
				}
			}
			if (leftBlock != 0 && rightBlock != 0) {
				rain += min(leftBlock, rightBlock);//3
			}
		}
	}
	cout << rain;
}