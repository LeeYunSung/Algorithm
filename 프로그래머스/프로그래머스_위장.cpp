#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//2차원 vector는 vector안에 vector자료형을 담는다는 느낌
int solution(vector<vector<string>> clothes) {
	int answer = 1;

	unordered_map<string, int> map;
	for (vector<string> clothes_kinds : clothes) {
		map[clothes_kinds[1]]++;
	}

	//iterator: 탐색을 위한 반복자
	unordered_map<string, int>::iterator iter;
	for (iter = map.begin(); iter != map.end(); iter++) {
		answer *= iter->second + 1;
	}

	return answer - 1;
}