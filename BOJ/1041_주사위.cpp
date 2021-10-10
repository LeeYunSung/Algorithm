#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long FindMinCase(int n, vector<int> &dice);

int main() {
	int n = 0;
	vector<int> dice;

	cin >> n;

	int num = 0;
	for (int i = 0; i < 6; i++) {
		cin >> num;
		dice.push_back(num);
	}
	//sort(dice.begin(), dice.end()); //*****주사위 값 위치가 정해져 있어서 무작정 정렬하면 안됨!!
	if (n > 1) {
		cout << FindMinCase(n, dice);//주사위 숫자가 최소로 보일 수 있는 경우 찾기
	}
	else {
		sort(dice.begin(), dice.end());
		int sum = 0;
		for (int i = 0; i < dice.size() - 1; i++) {
			sum += dice[i];
		}
		cout << sum;
	}
	return 0;
}

long long FindMinCase(int n, vector<int> &dice) {
	int sum1 = 50;//면이 1개일 때 최소합
	int sum2 = 100;//면이 2개일 때 최소합
	int sum3 = 150;//면이 3개일 때 최소합

	for (int i = 0; i < dice.size(); i++) {
		if (sum1 > dice[i]) sum1 = dice[i];
		for (int j = i + 1; j < dice.size(); j++) {
			if (i + j == 5) continue;//마주보는 면은 함께 구할 수 없음
			if (sum2 > dice[i] + dice[j]) sum2 = dice[i] + dice[j];
			for (int k = j + 1; k < dice.size(); k++) {
				if (j + k == 5 || i + k == 5) continue;//마주보는 면은 함께 구할 수 없음
				if (sum3 > dice[i] + dice[j] + dice[k]) sum3 = dice[i] + dice[j] + dice[k];
			}
		}
	}
	long long result = 0;
	//면1개가 보이는 개수만큼 곱해주기
	result += sum1 * ((long long)(n - 2)*(n - 2) + ((long long)(n - 2)*(n - 1) * 4));
	//면2개가 보이는 개수만큼 곱해주기
	result += sum2 * ((n - 2) * 4 + ((n - 1) * 4));
	//면3개가 보이는 개수만큼 곱해주기
	result += sum3 * 4;

	return result;
}
