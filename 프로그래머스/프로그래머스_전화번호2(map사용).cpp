#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	unordered_map<string, int> map;
	for (string phone_number : phone_book) {
		map[phone_number] = 1;
	}
	for (int i = 0; i < phone_book.size(); i++) {
		string phone_number = "";
		for (int j = 0; j < phone_book[i].size(); j++) {
			phone_number = phone_book[i][j];
			if (map[phone_number] && phone_number != phone_book[i]) { //�� �ڽ��� ���λ�� �Ǵ��ϸ� �ȵǴϱ� phone_number != phone_book[i] ������ �ִ� ��!
				answer = false;
			}
		}
	}
	return answer;
}