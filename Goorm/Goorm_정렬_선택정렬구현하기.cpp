#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

/**
* 주어진 범위의 최소값의 위치를 반환하는 함수
* @param data  데이터 배열
* @param begin 탐색 할 가장 첫(왼쪽) 인덱스
* @param end   탐색 할 가장 마지막(오른쪽) 인덱스
* @return	   data[begin] ~ data[end] 중 가장 작은 원소의 인덱스
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