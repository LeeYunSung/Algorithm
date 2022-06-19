#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool Compare(string word1, string word2) {
	if (word1.length() == word2.length()) {
		return word1 < word2;
	}
	return word1.length() < word2.length();
}

int main() {
	int wordNum = 0;
	string word = "";
	vector<string> wordVector;
	
	cin >> wordNum;
	while(wordNum--) {
		cin >> word;
		if (find(wordVector.begin(), wordVector.end(), word) == wordVector.end()) {
			wordVector.push_back(word);
		}
	}
	sort(wordVector.begin(), wordVector.end(), Compare);
	
	for (string s : wordVector) {
		cout << s << "\n";
	}
	return 0;
}