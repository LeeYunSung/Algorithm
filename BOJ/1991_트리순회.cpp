#include <iostream>
#include <vector>
using namespace std;

void SearchFront(char);
void SearchCenter(char);
void SearchBack(char);

const int MAX = 26;

struct node {
	char left;
	char right;
};
node tree[MAX];

int main() {
	int N = 0;
	cin >> N;

	char root, l, r;
	for (int i = 0; i < N; i++) {
		cin >> root >> l >> r;
		tree[root].left = l;
		tree[root].right = r;
	}
	SearchFront('A');
	cout << "\n";
	SearchCenter('A');
	cout << "\n";
	SearchBack('A');

	return 0;
}

void SearchFront(char node) {
	if (node == '.') return;
	cout << node;
	SearchFront(tree[node].left);
	SearchFront(tree[node].right);
}
void SearchCenter(char node) {
	if (node == '.') return;
	SearchCenter(tree[node].left);
	cout << node;
	SearchCenter(tree[node].right);
}
void SearchBack(char node) {
	if (node == '.') return;
	SearchBack(tree[node].left);
	SearchBack(tree[node].right);
	cout << node;
}
