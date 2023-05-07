#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool DFS(string airport, vector<vector<string>> tickets, vector<string> &answer, vector<bool> &isVisited, int ticketCount) {
	answer.push_back(airport);
	if (ticketCount == tickets.size()) return true;

	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == airport && !isVisited[i]) {
			isVisited[i] = true;
			if (DFS(tickets[i][1], tickets, answer, isVisited, ticketCount + 1)) {
				return true;
			}
			//재탐색을 위해 방문 false 처리
			isVisited[i] = false;
		}
	}
	answer.pop_back();
	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	vector<bool> isVisited(tickets.size(), false);

	//가능한 경로가 2개 이상일 때 알파벳 순서가 앞서는 경로를 return 해야 하므로 미리 정렬.
	sort(tickets.begin(), tickets.end());
	//DFS 탐색으로 모두 탐색하는 경로 찾기
	DFS("ICN", tickets, answer, isVisited, 0);

	return answer;
}