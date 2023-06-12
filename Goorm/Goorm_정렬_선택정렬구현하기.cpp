#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

/**
* �־��� ������ �ּҰ��� ��ġ�� ��ȯ�ϴ� �Լ�
* @param data  ������ �迭
* @param begin Ž�� �� ���� ù(����) �ε���
* @param end   Ž�� �� ���� ������(������) �ε���
* @return	   data[begin] ~ data[end] �� ���� ���� ������ �ε���
*/
int getMinIndexInRange(vector<int> & data, int begin, int end) {
	int targetIndex = begin;
	for (int i = begin; i < end; i++) {
		if (data[targetIndex] > data[i]) targetIndex = i;
	}
	return targetIndex;
}

void selectionSort(vector<int> & data, int n) {
	int minIndex = 0;
	for (int i = 0; i < data.size(); i++) {
		int minIndex = getMinIndexInRange(data, i, data.size());
		int temp = 0;
		temp = data[i];
		data[i] = data[minIndex];
		data[minIndex] = temp;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> data(n);

	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}

	selectionSort(data, n);

	for (int i = 0; i < n; i++) {
		if (i > 0) {
			cout << " ";
		}
		cout << data[i];
	}
	return 0;
}