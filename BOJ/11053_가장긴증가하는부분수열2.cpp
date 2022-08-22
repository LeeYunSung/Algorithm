#include <iostream>
#include <vector>
using namespace std;

int main() {
	int numCount, maxDistance = 0, input;
	vector<pair<int,int>> nums;//����, �������� ����
	cin >> numCount;

	for (int i = 0; i < numCount; i++) {
		cin >> input;
		nums.push_back(make_pair(input, 1));
	}

	//�ݺ����� ���鼭
	//���� ���ں��� ���� ���ڵ��� �۰�
	//���� ���ڰ� ���� �ִ� ���������� ������ +1�� ��(�� ���� ���� ������ ���)��
	//���� ���� �ִ� ���������� �������� ũ�ٸ�
	//���� �������� ������ 1 �÷��ش�.
	for (int i = 0; i < numCount; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[j].first < nums[i].first) {
				if(nums[j].second + 1 > nums[i].second){
					nums[i].second += 1;
				}
			}
		}
		if (maxDistance < nums[i].second) maxDistance = nums[i].second;
	}
	cout << maxDistance;
	
	return 0;
}