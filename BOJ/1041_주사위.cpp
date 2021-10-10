#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long Calculation(int n, vector<int> dice);

int main() {
	int n = 0;
	vector<int> dice;

	cin >> n;
	
	int num = 0;
	for (int i = 0; i < 6; i++) {
		cin >> num;
		dice.push_back(num);
	}
	sort(dice.begin(), dice.end()); // 최소구하는거니까 오름차순 정렬하고 시작
	cout << Calculation(n, dice);

	return 0;
}

long long Calculation(int n, vector<int> dice) {
	long long result = 0;

	if (n > 1) {
		long long sum = 0;
		for (int i = 0; i < 3; i++) {
			sum += dice[i];//면이 1개일때, 면이 2개일때, 면이 3개일때 합구하기.
			switch (i) {
				case 0://면1개가 보이는 개수만큼 곱해주기
					result += sum * ((long long)(n - 2)*(n - 2) + ((long long)(n - 2)*(n - 1)*4));
					break;
				case 1://면2개가 보이는 개수만큼 곱해주기
					result += sum * ((n - 2) * 4 + (n - 1) * 4);
					break;
				case 2://면3개가 보이는 개수만큼 곱해주기
					result += sum*4;
					break;
			}
		}
	}
	else {//주사위가 1개라면 면 5개의 합구해서 출력.
		for (int i = 0; i < dice.size() - 1; i++) {
			result += dice[i];
		}
	}
	return result;
}