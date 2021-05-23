#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

void calculateMaxProfit(vector<pair<int, int>>, int);
int profitSum, maxProfit;

int main() {
	int dday = 0, day = 0, profit = 0;
	vector<pair<int, int>> schedule;

	cin >> dday;
	for (int index = 0; index < dday; index++) {
		cin >> day >> profit;
		schedule.push_back(make_pair(day, profit));
	}
	calculateMaxProfit(schedule, 0);
	cout << maxProfit;
}

void calculateMaxProfit(vector<pair<int, int>> schedule, int day) {
	for (int index = day; index < schedule.size(); index++) {
		if (index + schedule[index].first <= schedule.size()) {
			profitSum += schedule[index].second;
			calculateMaxProfit(schedule, index + schedule[index].first);
			profitSum -= schedule[index].second;;
		}
	}
	maxProfit = max(profitSum, maxProfit);
}