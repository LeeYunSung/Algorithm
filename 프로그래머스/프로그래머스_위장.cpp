#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//2���� vector�� vector�ȿ� vector�ڷ����� ��´ٴ� ����
int solution(vector<vector<string>> clothes) {
	int answer = 1;

	unordered_map<string, int> map;
	for (vector<string> clothes_kinds : clothes) {
		map[clothes_kinds[1]]++;
	}

	//iterator: Ž���� ���� �ݺ���
	unordered_map<string, int>::iterator iter;
	for (iter = map.begin(); iter != map.end(); iter++) {
		answer *= iter->second + 1;
	}

	return answer - 1;
}