#include <iostream>
#include <string>
#include <list>
using namespace std;


const int MAX_SIZE = 100001;

int main() {
	string str, answer;
	int commandNum;

	cin >> str >> commandNum;

	// ���Ḯ��Ʈ�� ���� �Ҵ�
	list<char> li(str.begin(), str.end());
	
	// Ŀ����ġ�� �Էµ� ���� ���� ���� ��ġ
	auto cursor = li.end();

	for (int i = 0; i < commandNum; i++) {
		char command, addString;
		cin >> command;
		
		// �������� Ŀ�� �ű�
		if (command == 'L') {
			if (cursor != li.begin()) {
				cursor--;
			}
		}
		// ���������� Ŀ�� �ű�
		else if (command == 'D') {
			if (cursor != li.end()) {
				cursor++;
			}
		}
		// ���� ���ڿ� ����
		else if (command == 'B') {
			if (cursor != li.begin()) {
				cursor--;
				cursor = li.erase(cursor);
			}
		}
		// ���ʿ� ���ڿ� �߰�
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