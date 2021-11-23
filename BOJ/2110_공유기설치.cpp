#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void SearchBinary(vector<int>& home_vector, int wifi_num) {
	int start = 1;//공유기를 놓을 수 있는 최소거리
	int mid = 0;
	int end = home_vector.back() - home_vector.front();//공유기를 놓을 수 있는 최대거리
	int max_distance = 0;

	while (start <= end) {
		mid = (end + start) / 2;
		int count = 1; // 설치한 공유기 개수
		int prev_home = home_vector[0];
		for (int i = 1; i < home_vector.size(); i++) {//간격(mid)를기준으로 공유기 설치
			if (home_vector[i] - prev_home >= mid) {
				count++;
				prev_home = home_vector[i];
			}
		}
		if (count >= wifi_num) {//공유기 수를 줄여야한다면, 간격을 늘린다.
			max_distance = max(max_distance, mid);
			start = mid + 1;
		}
		else end = mid - 1;//공유기 수가 더 설치되어야 한다면, 간격을 줄인다.
	}
	cout << max_distance;
}

int main() {
	int home_num, wifi_num, input;
	vector<int> home_vector;
	
	cin >> home_num >> wifi_num;
	for (int i = 0; i < home_num; i++) {
		cin >> input;
		home_vector.push_back(input);
	}
	sort(home_vector.begin(), home_vector.end());
	SearchBinary(home_vector, wifi_num);
}