#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int num = 0;
	cin >> num;
	int *num_array = new int[num + 1]{0, }; //memorization

	for (int i = 2; i < num + 1; i++) { //Bottom-up 방식으로 작은 값인 2부터 값을 구해가면서 그 값을 이용해서 큰 값인 num의 값을 구함
		num_array[i] = num_array[i - 1] + 1; 
		if (i % 3 == 0) { 
			num_array[i] = min(num_array[i], num_array[i / 3] + 1); 
		}
		if (i % 2 == 0) { 
			num_array[i] = min(num_array[i], num_array[i / 2] + 1); 
		}
	}
	cout << num_array[num];

	delete[] num_array;
}