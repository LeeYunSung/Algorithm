#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
void swap(int, int);
void ascending(int x);
bool next_permutation();

int main() {
	int N = 0;
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}

	do {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		} cout << "\n";
	} while (next_permutation());

	return 0;
}

void swap(int i, int j) {
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void ascending(int idx) {
	for (int i = idx; i < v.size()-1; i++) {
		for (int j = i+1; j < v.size(); j++) {
			if (v[i] > v[j]) {
				swap(i, j);
			}
		}
	}
}

bool next_permutation() {
	if (v.size() < 1) return false;

	for (int i = v.size() - 1; i > 0; i--) {// 맨 뒤 원소부터 탐색 시작
		if (v[i - 1] < v[i]) {// v[i-1] > v[i] 부등호가 성립하지 않는 수(v[i-1]) 찾기 
			ascending(i);// v[i]부터 맨 끝자리 수까지 오름차순 정렬하기

			for (int j = i; j < v.size(); j++) {// > 부등호가 성립하지 않는 다음 수(v[i])부터 마지막 수까지 탐색
				if (v[j] > v[i-1]) {// v[i-1]보다 크면서 v[i]부터 마지막 수까지 중에 가장 작은 수 찾기
					swap(i - 1, j);// v[i-1]와 작은 수 위치 바꾸기			
					return true; // 다시 맨 뒤 원소부터 탐색 시작하기
				}
			}
		}
	} return false; // 맨 앞까지 탐색했을 때 v[i-1] > v[i] 가 성립하지 않는 곳이 없다면 = 내림차순 정렬되어 있다면 탐색종료
}