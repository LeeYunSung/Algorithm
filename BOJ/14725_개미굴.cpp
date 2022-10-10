#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Node {
	map<string, Node> child;//map는 key를 기준으로 자동으로 오름차순 정렬하므로 unordered_map 말고 map을 사용
};

void insert(Node &p, vector<string> v, int idx);
void print(Node &p, int depth);

int main() {
	Node root;
	int feedNum;

	cin >> feedNum;
	for (int i = 0; i < feedNum; i++) {
		int feedLength;
		cin >> feedLength;

		vector<string> feeds(feedLength);

		for (int j = 0; j < feedLength; j++){
			cin >> feeds[j];
		}
		insert(root, feeds, 0);
	}
	print(root, 0);

	return 0;
}

void insert(Node &node, vector<string> feeds, int idx) {
	//idx가 vector 끝에 도달하면 끝.
	if (idx == feeds.size()) return;

	//feed 벡터에서 가져온 string이 트리에 있는지 count()로 확인.
	//없으면 0이 나옴. 따라서 key를 string으로 하는 node를 만들어 줌.
	if (!node.child.count(feeds[idx]))
		node.child[feeds[idx]] = Node();

	//노드 타고 들어가기
	insert(node.child[feeds[idx]], feeds, idx + 1);
}

void print(Node &root, int depth) {
	//모든 노드 가져오기
	for (auto node : root.child) {
		for (int i = 0; i < depth; i++) {
			cout << "--";
		}
		cout << node.first << "\n";

		print(node.second, depth + 1);
	}
}