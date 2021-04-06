#include <iostream>
#include <vector>
#include <utility> //pair vector�� ����ϱ� ���� �������
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
	calculateMaxProfit(0, 0, schedule);//index, profit, schedule vector �ѱ�
	cout << max_profit;
}

void calculateMaxProfit(int index, int profit, vector<pair<int, int>>& schedule) {
	if (index > schedule.size()) { //����� �Ұ����� ���
		return;
	}
	if (index == schedule.size()) { //��������� ���� �� �ִ� ����� ���� ã���� ��, Ž�������ϰ� �ִ����� �����ؼ� ����.
		if (profit > max_profit) {//�̹� ����� ���� �հ� ���ݱ��� ���� �ִ����� ���� ���ؼ� ����
			max_profit = profit;
		}
		return;
	}
	calculateMaxProfit(index + schedule[index].first, profit + schedule[index].second, schedule);//��� �� ��. ���ҿ�Ⱓ ������ ���� Ž����.
	calculateMaxProfit(index + 1, profit, schedule);//��� ���� ��. �ٷ� �������� Ž����.
}
