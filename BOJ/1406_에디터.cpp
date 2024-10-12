#include <iostream>
#include <string>
#include <list>
using namespace std;


const int MAX_SIZE = 100001;

int main() {
	string str, answer;
	int commandNum;

	cin >> str >> commandNum;

	// 연결리스트에 원소 할당
	list<char> li(str.begin(), str.end());
	
	// 커서위치를 입력된 문자 제일 끝에 위치
	auto cursor = li.end();

	for (int i = 0; i < commandNum; i++) {
		char command, addString;
		cin >> command;
		
		// 왼쪽으로 커서 옮김
		if (command == 'L') {
			if (cursor != li.begin()) {
				cursor--;
			}
		}
		// 오른쪽으로 커서 옮김
		else if (command == 'D') {
			if (cursor != li.end()) {
				cursor++;
			}
		}
		// 왼쪽 문자열 삭제
		else if (command == 'B') {
			if (cursor != li.begin()) {
				cursor--;
				cursor = li.erase(cursor);
			}
		}
		// 왼쪽에 문자열 추가
		else if(command == 'P'){
			cin >> addString;
			li.insert(cursor, addString);
		}
	}

	for (cursor = li.begin(); cursor != li.end(); cursor++) {
		cout << *cursor;
	}

	return 0;
}