#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	unordered_map<string, int> map;

	//1. �� ������ key�� �ΰ� �� ������ ����.
	for (auto& i : clothes) {
		map[i[1]]++;
	}

	//2. �� ���� ������ŭ ���ؼ� ���� ������ ã�´�.
	for (pair<string, int> i : map) {
		//�� ���� ������ ������ϴ� ��츦 �߰��ؼ� +1�� ��.
		answer *= (i.second + 1);
	}

	//3. ���� ���� ���ϴ� ��� 1������ �����Ѵ�.
	answer--;

	return answer;
}