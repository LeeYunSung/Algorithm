#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DFS(int index, int wordNum, int canTeachNum, int learned);

const int STANDARD_NUM = 5;
int learn, words[50];

int main() {
	int wordNum, canTeachNum, canReadNum = 0;
	string word;

	// Input
	cin >> wordNum >> canTeachNum;

	// antic 배운단어로 체크
	learn |= (1 << 'a' - 'a');
	learn |= (1 << 'n' - 'a');
	learn |= (1 << 't' - 'a');
	learn |= (1 << 'i' - 'a');
	learn |= (1 << 'c' - 'a');

	for (int i = 0; i < wordNum; i++) {
		cin >> word;

		// anta, tica 문자열 삭제하고 나머지만 체크
		word = word.substr(4, word.length() - 8);

		for (char str : word) {
			words[i] |= (1 << str - 'a');// 배운단어로 체크
		}
	}

	// Check
	if (canTeachNum < STANDARD_NUM) {
		canReadNum = 0;
	}
	else {
		//canTeachNum -= STANDARD_NUM;
		canReadNum = DFS(0, wordNum, canTeachNum, 5);
	}

	// Output
	cout << canReadNum;

	return 0;
}


int DFS(int index, int wordNum, int canTeachNum, int learned) { // index, 배울 수 있는 단어 수, 배운 단어 수
	int result = 0;

	if (learned == canTeachNum)
	{
		for (int i = 0; i < wordNum; i++)
			if ((words[i] & learn) == words[i])
				result++;

		return result;
	}

	for (int i = index; i < 26; i++)
	{
		if ((learn & (1 << i)) == 0)
		{
			learn |= (1 << i);
			result = max(result, DFS(i + 1, wordNum, canTeachNum, learned + 1));
			learn &= ~(1 << i);
		}
	}

	return result;
}