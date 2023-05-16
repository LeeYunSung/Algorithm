#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	unordered_map<string, int> map;

	//1. 옷 종류를 key로 두고 옷 종류를 센다.
	for (auto& i : clothes) {
		map[i[1]]++;
	}

	//2. 옷 종류 개수만큼 곱해서 조합 개수를 찾는다.
	for (pair<string, int> i : map) {
		//옷 종류 개수에 착용안하는 경우를 추가해서 +1한 것.
		answer *= (i.second + 1);
	}

	//3. 전부 착용 안하는 경우 1가지를 제외한다.
	answer--;

	return answer;
}