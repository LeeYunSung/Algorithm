#include <iostream>
#include <vector>
#include <utility> //pair vector를 사용하기 위한 헤더파일
using namespace std;

void calculateMaxProfit(int, int, vector<pair<int, int>>&);
int max_profit;

int main() {
	int dday = 0;
	vector<pair<int, int>> schedule;

	cin >> dday;
	for (int i = 0; i < dday; i++) {
		int day, profit;
		cin >> day >> profit;
		schedule.push_back({day, profit});
	}
	calculateMaxProfit(0, 0, schedule);//index, profit, schedule vector 넘김
	cout << max_profit;
}

void calculateMaxProfit(int index, int profit, vector<pair<int, int>>& schedule) {
	if (index > schedule.size()) { //상담이 불가능한 경우
		return;
	}
	if (index == schedule.size()) { //상담일정을 세울 수 있는 경우의 수를 찾았을 때, 탐색종료하고 최대이익 갱신해서 리턴.
		if (profit > max_profit) {//이번 경우의 수의 합과 지금까지 구한 최대이익 값을 비교해서 갱신
			max_profit = profit;
		}
		return;
	}
	calculateMaxProfit(index + schedule[index].first, profit + schedule[index].second, schedule);//상담 할 때. 상담소요기간 이후의 날을 탐색함.
	calculateMaxProfit(index + 1, profit, schedule);//상담 안할 때. 바로 다음날을 탐색함.
}
