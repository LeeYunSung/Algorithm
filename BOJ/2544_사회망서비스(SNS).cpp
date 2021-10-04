#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000001;

vector<int> tree[MAX];
int dp[MAX][2];
bool visited[MAX];

void SearchEarlyAdaptorNum(int);

int main() {
	int node_num = 0;
	cin >> node_num;

	int n = 0, m = 0;
	for (int i = 0; i < node_num; i++) {
		cin >> n >> m;
		tree[n].push_back(m);
		tree[m].push_back(n);//양방향으로 연결
	}
	SearchEarlyAdaptorNum(1);//root노드부터 DFS로 leaf노드까지 탐색
	cout << min(dp[1][0], dp[1][1]);//마지막 root노드의 값 출력

	return 0;
}

void SearchEarlyAdaptorNum(int current_node) {
	visited[current_node] = true;
	dp[current_node][0] = 0; //내가 얼리어답터가 아닐 때. 얼리어답터 1명 추가안함.
	dp[current_node][1] = 1; //내가 얼리어답터 일 때. 얼리어답터 1명 추가.
	for (int i = 0; i < tree[current_node].size(); i++) {
		int neighbor_node = tree[current_node][i];
		if (!visited[neighbor_node]) {
			SearchEarlyAdaptorNum(neighbor_node);//DFS
			//자식노드를 기반으로 역으로 채워주는 과정
			dp[current_node][0] += dp[neighbor_node][1];//내가 얼리어답터가 아니면, 내 친구는 얼리어답터여야 한다
			dp[current_node][1] += min(dp[neighbor_node][0], dp[neighbor_node][1]);//내가 얼리어답터면, 친구는 얼리어답터여도 되고 아니어도 된다.
		}
	}
}