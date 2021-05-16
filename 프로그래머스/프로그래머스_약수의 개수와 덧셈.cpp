#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
	int answer = 0;
	for (int i = left; i <= right; i++) {
		int count = 0;
		for (int j = 1; j*j <= i; j++) {
			if (i%j == 0) count = +2; // j�� i/j 2��
			if (j*j == i) count++; // ������(¦���� �߰���) 1��
		}
		(count % 2 == 0) ? answer += i : answer -= i;
	}
	return answer;
}