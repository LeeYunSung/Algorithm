#include <string>
#include <iostream>
using namespace std;

bool solution(string s) {
	int count = 0;

	for (int i = 0; i < s.size(); i++) {
		count += (s[i] == '(') ? 1 : -1;
		if (count < 0) return false;
	}

	return count == 0 ? true : false;
}