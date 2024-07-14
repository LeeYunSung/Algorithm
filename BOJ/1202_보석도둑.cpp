#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

long long GetMaxPrice(vector<pair<int, int>> jewelryInfos, vector<int> bagInfos);

int main() {

	int jewelryNum, bagNum;
	int jewelryWeight, jewelryPrice, bagWeight; //input

	vector<pair<int, int>> jewelryInfos;	    // 보석들의 무게, 가격
	vector<int> bagInfos;					    //가방들의 무게

	// Input
	cin >> jewelryNum >> bagNum;
	for (int i = 0; i < jewelryNum; i++) {
		cin >> jewelryWeight >> jewelryPrice;
		jewelryInfos.push_back({ jewelryWeight, jewelryPrice });
	}
	for (int i = 0; i < bagNum; i++) {
		cin >> bagWeight;
		bagInfos.push_back(bagWeight);
	}

	// Output
	cout << GetMaxPrice(jewelryInfos, bagInfos);

	return 0;
}


// 가방 무게 범위 안에 들어오는 보석들을 저장한 후,
// 가장 비싼 보석들을 가방 개수만큼 선택(priority_queue)
long long GetMaxPrice(vector<pair<int, int>> jewelryInfos, vector<int> bagInfos) {

	long long totalPrice = 0;
	priority_queue<int> selectedJewelrys;	    //가장 비싼 보석 선택

	sort(jewelryInfos.begin(), jewelryInfos.end());
	sort(bagInfos.begin(), bagInfos.end());

	int searchedIndex = 0;
	for (int i = 0; i < bagInfos.size(); i++) {
		for (int j = searchedIndex; j < jewelryInfos.size(); j++) {
			if (bagInfos[i] >= jewelryInfos[j].first) {
				selectedJewelrys.push(jewelryInfos[j].second);
				searchedIndex++;
			}
			else {
				break;
			}
		}
		if (!selectedJewelrys.empty())
		{
			totalPrice += selectedJewelrys.top();
			selectedJewelrys.pop();
		}
	}

	return totalPrice;
}