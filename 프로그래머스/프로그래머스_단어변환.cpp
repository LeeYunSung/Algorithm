#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer = 0;

//시작단어, 타겟단어, 단어목록, 방문체크배열, 탐색 횟수
void DFS(string begin, string target, vector<string> words, vector<bool>& isVisited, int searchCount) {
	//글자 개수만큼 반복
	for (int i = 0; i < words.size(); i++) {
		//다른 알파벳 개수 찾기
		int diffCount = 0;
		for (int j = 0; j < words[i].length(); j++) {
			if (!isVisited[i] && begin[j] != words[i][j]) diffCount++;
		}
		//한 개만 다르다면 
		if (diffCount == 1) {
			//그 단어가 target이면 asnwer값 1 늘리고 return 
			if (target == words[i] && answer > searchCount + 1) {
				answer = searchCount + 1;
				return;
			}
			//단어 방문체크 하고 DFS 재귀 실행
			isVisited[i] = true;
			DFS(words[i], target, words, isVisited, searchCount + 1);
			isVisited[i] = false;
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	vector<bool> isVisited(words.size(), false);
	DFS(begin, target, words, isVisited, 0);
	return answer;
}