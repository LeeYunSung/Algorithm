#include <iostream>
#include <string>
#include <vector>
#include <unordered_map> //hash_map 헤더파일. <hash_map>은 공식이 아니란당..
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = ""; //완주하지 못한 선수의 이름

	//값 대입(첨엔 모두 완주 전이라고 가정하고 참가자 수를 value로 넣음)(동명이인 때문에)
	unordered_map<string, int> map;
	for (string name : participant) {
		map[name] += 1;
	}

	//완주자 vector로 탐색하면서 완주한 사람이면 1씩 빼서 완주처리함.
	for (string name : completion) {
		map[name]-=1;
	}

	//map 순회하면서 value가 0보다 크다면(=완주못한 사람이 있으면) 그 key를 반환
	for (auto pair : map) {
		if (pair.second > 0) {
			answer = pair.first;
			break;
		}
	}
	return answer;
}