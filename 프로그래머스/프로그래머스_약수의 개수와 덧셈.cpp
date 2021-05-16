#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
	int answer = 0;
	for (int i = left; i <= right; i++) {
		int count = 0;
		for (int j = 1; j*j <= i; j++) {
			if (i%j == 0) count = +2; // j¶û i/j 2°³
			if (j*j == i) count++; // Á¦°ö¼ö(Â¦¾ø´Â Áß°£°ª) 1°³
		}
		(count % 2 == 0) ? answer += i : answer -= i;
	}
	return answer;
}