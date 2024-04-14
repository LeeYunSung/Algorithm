#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int mapSize, quizNum;
	string input;

	cin >> mapSize >> quizNum;

	map<string, int> mp;
	vector<string> v(mapSize + 1, "");

	//도감 정보
	for (int i = 1; i <= mapSize; i++) {
		cin >> input;
		mp.insert({ input, i });
		v[i] = input;
	}

	//문제
	for (int i = 0; i < quizNum; i++) {
		cin >> input;
		//문자
		if (atoi(input.c_str()) == 0) {
			cout << mp[input] << "\n";
		}
		//숫자
		else {
			cout << v[stoi(input)] << "\n";
		}
	}
	return 0;
}