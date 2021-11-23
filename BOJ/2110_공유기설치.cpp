#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void SearchBinary(vector<int>& home_vector, int wifi_num) {
	int start = 1;//�����⸦ ���� �� �ִ� �ּҰŸ�
	int mid = 0;
	int end = home_vector.back() - home_vector.front();//�����⸦ ���� �� �ִ� �ִ�Ÿ�
	int max_distance = 0;

	while (start <= end) {
		mid = (end + start) / 2;
		int count = 1; // ��ġ�� ������ ����
		int prev_home = home_vector[0];
		for (int i = 1; i < home_vector.size(); i++) {//����(mid)���������� ������ ��ġ
			if (home_vector[i] - prev_home >= mid) {
				count++;
				prev_home = home_vector[i];
			}
		}
		if (count >= wifi_num) {//������ ���� �ٿ����Ѵٸ�, ������ �ø���.
			max_distance = max(max_distance, mid);
			start = mid + 1;
		}
		else end = mid - 1;//������ ���� �� ��ġ�Ǿ�� �Ѵٸ�, ������ ���δ�.
	}
	cout << max_distance;
}

int main() {
	int home_num, wifi_num, input;
	vector<int> home_vector;
	
	cin >> home_num >> wifi_num;
	for (int i = 0; i < home_num; i++) {
		cin >> input;
		home_vector.push_back(input);
	}
	sort(home_vector.begin(), home_vector.end());
	SearchBinary(home_vector, wifi_num);
}