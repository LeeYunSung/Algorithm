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

	//���� ������ ���� �����ϱ�
	sort(numbers.begin(), numbers.end());

	//�������� �� �̱�
	do {
		for (int i = 1; i < numbers.size() + 1; i++) {
			//string -> int�� �ٲٱ�
			num = stoi(numbers.substr(0, i));
			//���� ���� �Ҽ����� �Ǻ��ϱ�. ���� ���� +1
			if (isPrime(num)) answer.insert(num);
		}
	} while (next_permutation(numbers.begin(), numbers.end()));

	//�Ҽ� ���� ����
	return answer.size();
}