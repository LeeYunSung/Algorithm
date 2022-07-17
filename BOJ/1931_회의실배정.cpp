#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool SortMeetings(pair<int, int> meeting1, pair<int, int> meeting2) {
	if (meeting1.second == meeting2.second) {
		return meeting1.first < meeting2.first;
	}
	return meeting1.second < meeting2.second;
}

int main() {
	int meetingNum, meetingStart, meetingEnd, selectedMeetingNum = 0;
	vector<pair<int,int>> meetings;

	cin >> meetingNum;
	for (int i = 0; i < meetingNum; i++) {
		cin >> meetingStart >> meetingEnd;
		meetings.push_back(make_pair(meetingStart, meetingEnd));
	}
	sort(meetings.begin(), meetings.end(), SortMeetings);

	int meetingEndTime = meetings[0].second;
	selectedMeetingNum++;
	for (int i = 1; i < meetings.size(); i++) {
		if (meetingEndTime <= meetings[i].first) {
			selectedMeetingNum++;
			meetingEndTime = meetings[i].second;
		}
	}
	cout << selectedMeetingNum << "\n";
	return 0;
}