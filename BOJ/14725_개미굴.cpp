#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Node {
	map<string, Node> child;//map�� key�� �������� �ڵ����� �������� �����ϹǷ� unordered_map ���� map�� ���
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
	//idx�� vector ���� �����ϸ� ��.
	if (idx == feeds.size()) return;

	//feed ���Ϳ��� ������ string�� Ʈ���� �ִ��� count()�� Ȯ��.
	//������ 0�� ����. ���� key�� string���� �ϴ� node�� ����� ��.
	if (!node.child.count(feeds[idx]))
		node.child[feeds[idx]] = Node();

	//��� Ÿ�� ����
	insert(node.child[feeds[idx]], feeds, idx + 1);
}

void print(Node &root, int depth) {
	//��� ��� ��������
	for (auto node : root.child) {
		for (int i = 0; i < depth; i++) {
			cout << "--";
		}
		cout << node.first << "\n";

		print(node.second, depth + 1);
	}
}