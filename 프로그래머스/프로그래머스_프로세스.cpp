#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	//명령 갯수만큼 반복
	for (int i = 0; i < commands.size(); i++) {

		//명령어 값 보기좋게 선언
		int beginIndex = commands[i][0];
		int endIndex = commands[i][1];
		int answerIndex = commands[i][2];

		//beginInde ~ endIndex까지 값 추출
		vector<int> partArray(array.begin() + beginIndex - 1, array.begin() + endIndex);

		//오름차순 정렬
		sort(partArray.begin(), partArray.end());

		//K번째 수 추출
		answer.push_back(partArray[answerIndex - 1]);
	}

	return answer;
}