#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool solution(vector<string> phone_book) {
	sort(phone_book.begin(), phone_book.end());
	for (int idx = 0; idx < phone_book.size()-1; idx++) {
		if (phone_book[idx] == phone_book[idx + 1].substr(phone_book[idx].length())){
			return false;
		}
	}
	return true;
}
