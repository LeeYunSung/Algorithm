#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer = 0;

//���۴ܾ�, Ÿ�ٴܾ�, �ܾ���, �湮üũ�迭, Ž�� Ƚ��
void DFS(string begin, string target, vector<string> words, vector<bool>& isVisited, int searchCount) {
	//���� ������ŭ �ݺ�
	for (int i = 0; i < words.size(); i++) {
		//�ٸ� ���ĺ� ���� ã��
		int diffCount = 0;
		for (int j = 0; j < words[i].length(); j++) {
			if (!isVisited[i] && begin[j] != words[i][j]) diffCount++;
		}
		//�� ���� �ٸ��ٸ� 
		if (diffCount == 1) {
			//�� �ܾ target�̸� asnwer�� 1 �ø��� return 
			if (target == words[i] && answer > searchCount + 1) {
				answer = searchCount + 1;
				return;
			}
			//�ܾ� �湮üũ �ϰ� DFS ��� ����
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