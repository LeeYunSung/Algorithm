#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int homeworkNum, deadline, lamenNum, maxLamen = 0;

	priority_queue<int, vector<int>, greater<int>> pq;
	vector<pair<int, int>> v;
	
	cin >> homeworkNum;
	for (int i = 0; i < homeworkNum; i++) {
		cin >> deadline >> lamenNum;
		v.push_back({ deadline, lamenNum });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		pq.push(v[i].second);
		maxLamen += v[i].second;
		if (pq.size() > v[i].first) {
			maxLamen -= pq.top();
			pq.pop();
		}
	}
	cout << maxLamen << "\n";
	
	return 0;
}