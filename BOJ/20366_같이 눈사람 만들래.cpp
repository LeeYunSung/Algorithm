#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MAX_DIFFERENCE = 1000000000;

struct SnowMan {
	int index1;
	int index2;
	int size;
};

bool compare(const SnowMan& a, const SnowMan& b) {
	return a.size < b.size; // 눈사람 키 별로 정렬
}

int main() {
	int snow_num, input;
	vector<int> snow_vector;
	vector<SnowMan> snowman_vector;

	//1. snow_vector 채우기
	cin >> snow_num;
	for (int i = 0; i < snow_num; i++) {
		cin >> input;
		snow_vector.push_back(input);
	}
	//2. snow_num C 2 로 눈사람 2개 만들기
	for (int i = 0; i < snow_num-1; i++) {
		for (int j = i+1; j < snow_num; j++) {
			snowman_vector.push_back({ i,j, snow_vector[i] + snow_vector[j] });
		}
	}
	sort(snowman_vector.begin(), snowman_vector.end(), compare);

	//3. 인접한 눈사람 2개 선택해서 키차이 계산하기
	long long min_difference = MAX_DIFFERENCE;
	for (int i = 0; i < snowman_vector.size()-1; i++) {
		if (snowman_vector[i].index1 != snowman_vector[i + 1].index1 &&
			snowman_vector[i].index1 != snowman_vector[i + 1].index2 &&
			snowman_vector[i].index2 != snowman_vector[i + 1].index1 &&
			snowman_vector[i].index2 != snowman_vector[i + 1].index2) {

			if (min_difference > abs(snowman_vector[i].size - snowman_vector[i + 1].size)) {
				min_difference = abs(snowman_vector[i].size - snowman_vector[i + 1].size);
			}
		}
	}
	cout << min_difference;

	return 0;
}