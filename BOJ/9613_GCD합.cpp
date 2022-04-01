/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void SelectTwoNum(vector<int> num_vector);//최대공약수를 구하기위해 두 수를 선택하는 함수
int CalculateGCD(int a, int b);//나머지를 구해서 최대공약수를 구할 함수

//내림차순을 위한 조건문 함수
bool lower(int a, int b) {
	return (a > b);
}

int main() {
	int test_case = 0, num_count = 0, num = 0;//테스트 케이스 수, 한 줄당 입력받는 수, 한 줄에 입력되는 숫자들(벡터에 넣으려구)
	vector<int> num_vector;//한 줄에 입력된 숫자들을 담은 벡터

	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		cin >> num_count;
		for (int j = 0; j < num_count; j++) {
			cin >> num;
			num_vector.push_back(num);
		}
		if (num_count >= 2) {//한 줄에 입력된 수가 2 이상이면 최대공약수를 구하러 감. 1개 이면 그 수가 곧 최대공약수.
			sort(num_vector.begin(), num_vector.end(), lower);//항상 큰수를 작은 수로 나누게 내림차순으로 정렬함. 
			SelectTwoNum(num_vector);//경우의 수를 구해야 해서 2개의 숫자를 뽑으러 가자.
			num_vector.clear();//숫자를 다시 받아야 하므로 num_vector 초기화
		}
		else cout << num_vector.front() << "\n";
	}
	return 0;
}

void SelectTwoNum(vector<int> num_vector) {
	vector<int> check_vector;//0과 1을 이용해서 2수를 뽑는 경우의 수를 찾기 위한 벡터
	vector<int> selected_num;//선택된 두 수를 담은 벡터
	long long sum = 0;

	for (int i = 0; i < 2; i++) { check_vector.push_back(1); }//1을 2개 넣어주고(선택될 인덱스 표시)
	for (int i = 0; i < num_vector.size() - 2; i++) { check_vector.push_back(0); }//나머지는 0으로.(선택 안될 인덱스 표시)
	sort(check_vector.begin(), check_vector.end());//작은 수부터 순열을 구해야 하므로 오름차순 정렬. 중간에 비는 경우 없이 모든 경우의 수를 구하기 위해.

	do {
		for (int i = 0; i < num_vector.size(); i++) {
			if (check_vector[i]){//선택된 인덱스면 selected_num에 추가해줌.
				selected_num.push_back(num_vector[i]);
				if (selected_num.size() > 1) {//선택된 수가 2개면 최대공약수 구하러 떠나기.
					sum += CalculateGCD(selected_num.front(), selected_num.back());//구한 합들을 저장
					selected_num.clear();//숫자를 다시 선택해야 하므로 selected_num벡터 clear.
					break;
				}
			}
		}
	} while (next_permutation(check_vector.begin(), check_vector.end()));//다음 2수를 뽑는 경우의 수가 있는지 확인. 있으면 반복문 계속 진행.
	cout << sum << "\n";
}

int CalculateGCD(int a, int b) {//최대 공약수
	if (a%b == 0) {
		return b;
	}
	return CalculateGCD(b, a%b);//유클리드 호제법 GCD(a, b) = GCD(b, a%b)임을 이용
}
*/


#include <iostream>
#include <vector>
using namespace std;

int CalculateGCD(int a, int b);

int main() {
	int test_case, num_count, num;
	cin >> test_case;

	while (test_case--) {
		vector<int> num_vector;

		cin >> num_count;
		for (int i = 0; i < num_count; i++) {
			cin >> num;
			num_vector.push_back(num);
		}
		long long sum = 0;

		for (int i = 0; i < num_count; i++) {
			for (int j = i+1; j < num_count; j++) {
				sum += CalculateGCD(num_vector[i], num_vector[j]);
			}
		}
		cout << sum << "\n";
		num_vector.clear();
	}
	return 0;
}

int CalculateGCD(int a, int b) {
	if (a%b == 0) {//왜 작은수를 큰수로 나눠도 괜찮은걸까...
		return b;
	}
	return CalculateGCD(b, a%b);
}
