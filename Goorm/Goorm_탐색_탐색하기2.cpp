#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/**
* 배열에서 소속이 "AJOU"인 첫 원소와 마지막 원소를 출력하는 함수
* @param school 각 사람들의 소속학교 정보 배열
* @param n      사람들의 수
*/
pair<int, int> getIndexes(vector<string> &schools, int n) {
	int firstIndex = -1; //존재하지 않으면 -1
	int lastIndex = -1;  //존재하지 않으면 -1
	const string AJOU = "AJOU";

	for (int i = 0; i < schools.size(); i++) {
		if (schools[i] == AJOU) {
			if (firstIndex == -1) firstIndex = i + 1;
			else lastIndex = i + 1;
		}
	}

	return make_pair(firstIndex, lastIndex);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<string> schools(n);

	for (int i = 0; i < n; i++) cin >> schools[i];

	auto indexes = getIndexes(schools, n);
	cout << indexes.first << " " << indexes.second;

	return 0;
}