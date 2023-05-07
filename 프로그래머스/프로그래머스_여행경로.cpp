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
			//��Ž���� ���� �湮 false ó��
			isVisited[i] = false;
		}
	}
	answer.pop_back();
	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	vector<bool> isVisited(tickets.size(), false);

	//������ ��ΰ� 2�� �̻��� �� ���ĺ� ������ �ռ��� ��θ� return �ؾ� �ϹǷ� �̸� ����.
	sort(tickets.begin(), tickets.end());
	//DFS Ž������ ��� Ž���ϴ� ��� ã��
	DFS("ICN", tickets, answer, isVisited, 0);

	return answer;
}