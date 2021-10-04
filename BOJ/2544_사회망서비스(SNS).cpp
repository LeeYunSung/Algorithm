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
		tree[m].push_back(n);//��������� ����
	}
	SearchEarlyAdaptorNum(1);//root������ DFS�� leaf������ Ž��
	cout << min(dp[1][0], dp[1][1]);//������ root����� �� ���

	return 0;
}

void SearchEarlyAdaptorNum(int current_node) {
	visited[current_node] = true;
	dp[current_node][0] = 0; //���� �󸮾���Ͱ� �ƴ� ��. �󸮾���� 1�� �߰�����.
	dp[current_node][1] = 1; //���� �󸮾���� �� ��. �󸮾���� 1�� �߰�.
	for (int i = 0; i < tree[current_node].size(); i++) {
		int neighbor_node = tree[current_node][i];
		if (!visited[neighbor_node]) {
			SearchEarlyAdaptorNum(neighbor_node);//DFS
			//�ڽĳ�带 ������� ������ ä���ִ� ����
			dp[current_node][0] += dp[neighbor_node][1];//���� �󸮾���Ͱ� �ƴϸ�, �� ģ���� �󸮾���Ϳ��� �Ѵ�
			dp[current_node][1] += min(dp[neighbor_node][0], dp[neighbor_node][1]);//���� �󸮾���͸�, ģ���� �󸮾���Ϳ��� �ǰ� �ƴϾ �ȴ�.
		}
	}
}