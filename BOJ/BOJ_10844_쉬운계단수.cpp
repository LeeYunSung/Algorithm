#include <iostream>
using namespace std;

int searchStairsNumber(int);
const int overflow = 1000000000;

// int, long: 2,147,483,647
// long long: 9,223,372,036,854,775,807

int main() {
	int n = 0;
	cin >> n;
	cout << searchStairsNumber(n);
}

int searchStairsNumber(int n) {
	long long count_array[101][10] = { {0,0}, };
	for (int i = 1; i <= 9; i++) { count_array[1][i] = 1; }
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) count_array[i][j] = count_array[i - 1][1];
			else if (j == 9) count_array[i][j] = count_array[i - 1][8];
			else count_array[i][j] = count_array[i - 1][j - 1] + count_array[i - 1][j + 1];
			
			count_array[i][j] = count_array[i][j] % overflow;
		}
	}
	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += count_array[n][i];
	}sum = sum % overflow;

	return sum;
}