#include <iostream>
#include <string>
using namespace std;

int main() {
	int testCaseNum = 0, score = 0, totalScore = 0;
	string QuizText;

	cin >> testCaseNum;
	while (testCaseNum--) {
		score = 0;
		totalScore = 0;
		cin >> QuizText;
		for (char text : QuizText) {
			if (text == 'O') {
				score += 1;
				totalScore += score;
			}
			else if (text == 'X') {
				score = 0;
			}
		}
		cout << totalScore << "\n";
	}
	return 0;
}