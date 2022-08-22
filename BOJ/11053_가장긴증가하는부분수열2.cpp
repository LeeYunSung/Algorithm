#include <iostream>
#include <vector>
using namespace std;

int main() {
	int numCount, maxDistance = 0, input;
	vector<pair<int,int>> nums;//숫자, 증가수열 개수
	cin >> numCount;

	for (int i = 0; i < numCount; i++) {
		cin >> input;
		nums.push_back(make_pair(input, 1));
	}

	//반복문을 돌면서
	//현재 숫자보다 앞의 숫자들이 작고
	//앞의 숫자가 갖고 있는 증가수열의 개수에 +1한 값(그 값에 나를 더했을 경우)이
	//내가 갖고 있는 증가수열의 개수보다 크다면
	//나의 증가수열 개수를 1 늘려준다.
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