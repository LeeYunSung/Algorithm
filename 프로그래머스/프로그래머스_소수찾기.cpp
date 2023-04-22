#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;

bool isPrime(int a) {
	if (a <= 1) return false;
	for (int i = 2; i <= sqrt(a); i++) {
		if (a%i == 0) return false;
	}
	return true;
}

int solution(string numbers) {
	int num = 0;
	unordered_set<int> answer;

	//조합 돌리기 쉽게 정렬하기
	sort(numbers.begin(), numbers.end());

	//조합으로 수 뽑기
	do {
		for (int i = 1; i < numbers.size() + 1; i++) {
			//string -> int로 바꾸기
			num = stoi(numbers.substr(0, i));
			//뽑은 수가 소수인지 판별하기. 정답 갯수 +1
			if (isPrime(num)) answer.insert(num);
		}
	} while (next_permutation(numbers.begin(), numbers.end()));

	//소수 갯수 리턴
	return answer.size();
}