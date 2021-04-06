#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h> //자료형의 최댓값과 최솟값이 정의된 헤더 파일
using namespace std;

void calculation(vector<int>&, vector<int>&);

int main() {
	int N = 0;
	vector<int> nums; // 1, 2, 3, 4, 5
	vector<int> operators; // +, -, x, ÷

	cin >> N;
	for (int i = 0; i < N; i++) {//문제에서 주어지는 숫자 받기
		int x = 0;
		cin >> x;
		nums.push_back(x);
	}
	for (int i = 0; i < 4; i++) {//연산자를 +, -, x, ÷ 자리에 맞게 0,1,2,3 으로 표현한 대체 벡터를 만든다.
		int x = 0;
		cin >> x;
		if (x != 0) {
			for (int j = 0; j < x; j++) {
				operators.push_back(i);
			}
		}		
	}
	calculation(nums, operators);
}

void calculation(vector<int>& nums, vector<int>& operators) {
	int min_val = INT_MAX; //비교하기 쉽게 INT형의 최대값 2147483647 을 넣음
	int max_val = INT_MIN; //INT형의 최소값 -2147483648 을 넣음

	do{
		int value = nums[0]; //우선 맨 앞의 숫자를 value에 넣고
		for (int i = 0; i < operators.size(); i++) { //뒤부터는 연산자를 이용해서 계산해서 넣는다.
			switch (operators[i]) {//첫번째 연산자부터 연산 시작
				case 0: //연산자가 +일 때
					value += nums[i+1];
					break;
				case 1: //연산자가 -일 때
					value -= nums[i+1];
					break;
				case 2: //연산자가 x일 때
					value *= nums[i+1];
					break;
				case 3: //연산자가 ÷일 때
					value /= nums[i+1];
					break;
			}
		}
		//최대값, 최소값 갱신. 같을 수도 있으므로 둘다 if문으로 처리
		if (value < min_val) min_val = value;
		if (value > max_val) max_val = value;

	} while (next_permutation(operators.begin(), operators.end()));

	cout << max_val << "\n";
	cout << min_val << "\n";
}