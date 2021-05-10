#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;

	int *d = new int[num + 1]{1, 1, };//momorization.

	for (int i = 2; i < num + 1; i++) {// 작은 값들을 활용해서 큰 값을 구하는 방법인 top-down 방식
		d[i] = (d[i - 1] + d[i - 2]) % 10007; //d[n-1] = 직전모양(n-1)의 오른쪽에 | 모양을 붙인 개수. d[n-2] = 전전모양(n-2)의 오른쪽에 = 모양을 붙인 개수
	}
	cout << d[num];

	delete[] d;
}
