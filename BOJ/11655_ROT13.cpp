#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	const int SCREAT_NUM = 13;
	const int ALPHABET_NUM = 26;

	const int a = (int)'a';
	const int z = (int)'z';
	const int A = (int)'A';
	const int Z = (int)'Z';

	string str = "";
	
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		//소문자
		if (str[i] >= a && str[i] <= z) {
			if (str[i] + SCREAT_NUM > z) {
				str[i] = (str[i] + SCREAT_NUM) - ALPHABET_NUM;
			}
			else {
				str[i] += SCREAT_NUM;
			}
		}
		//대문자
		if(str[i] >= A && str[i] <= Z){
			if (str[i] + SCREAT_NUM > Z) {
				str[i] = (str[i] + SCREAT_NUM) - ALPHABET_NUM;
			}
			else {
				str[i] += SCREAT_NUM;
			}
		}
	}

	cout << str << "\n";
}