#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
void swap(int, int);
void ascending(int x);
bool next_permutation();

int main() {
	int N = 0;
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}

	do {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		} cout << "\n";
	} while (next_permutation());

	return 0;
}

void swap(int i, int j) {
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void ascending(int idx) {
	for (int i = idx; i < v.size()-1; i++) {
		for (int j = i+1; j < v.size(); j++) {
			if (v[i] > v[j]) {
				swap(i, j);
			}
		}
	}
}

bool next_permutation() {
	if (v.size() < 1) return false;

	for (int i = v.size() - 1; i > 0; i--) {// �� �� ���Һ��� Ž�� ����
		if (v[i - 1] < v[i]) {// v[i-1] > v[i] �ε�ȣ�� �������� �ʴ� ��(v[i-1]) ã�� 
			ascending(i);// v[i]���� �� ���ڸ� ������ �������� �����ϱ�

			for (int j = i; j < v.size(); j++) {// > �ε�ȣ�� �������� �ʴ� ���� ��(v[i])���� ������ ������ Ž��
				if (v[j] > v[i-1]) {// v[i-1]���� ũ�鼭 v[i]���� ������ ������ �߿� ���� ���� �� ã��
					swap(i - 1, j);// v[i-1]�� ���� �� ��ġ �ٲٱ�			
					return true; // �ٽ� �� �� ���Һ��� Ž�� �����ϱ�
				}
			}
		}
	} return false; // �� �ձ��� Ž������ �� v[i-1] > v[i] �� �������� �ʴ� ���� ���ٸ� = �������� ���ĵǾ� �ִٸ� Ž������
}