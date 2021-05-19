#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main() {
	string id = "";
	cin >> id;
	cout << solution(id);
}

string solution(string id) {
	string new_id = "";

	//1단계: 대문자->소문자로 변환
	for (int i = 0; i < id.size(); i++) {
		id[i] = tolower(id[i]);
	}
	//2단계: ~!@#$%^&*()=+[{]}:?,<>/ 문자 제거 (해당되는 문자만 new_id[]에 넣기)
	for (int i = 0; i < id.size(); i++) {
		if (id[i] != '-' && id[i] != '.'
			&& !('a' <= id[i] && id[i] <= 'z')
			&& !('0' <= id[i] && id[i] <= '9')) {
			continue;
		}
		new_id.push_back(id[i]);
	}
	//3단계: 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환
	string temp = "";
	for (int i = 0; i < new_id.size(); i++) {
		if (new_id[i] == '.') {
			temp.push_back('.');
			while (i < new_id.size() && new_id[i] == '.') i++;
			i--;
		}
		else temp.push_back(new_id[i]);
	}
	new_id = temp;

	//4단계: 양끝에 있는 마침표(.) 제거
	if (new_id[0] == '.') new_id = new_id.substr(1);
	if (new_id[new_id.size() - 1] == '.') new_id = new_id.substr(0, new_id.size() - 1);

	//5단계: id가 빈문자열일 경우, "a"를 대입
	if (new_id.empty()) new_id = "a";

	//6단계: id 길이가 16자 이상이면, 15개 이후 문자 모두 제거
	if (new_id.size() >= 16) new_id = new_id.substr(0, 15);
	if (new_id[new_id.size() - 1] == '.') new_id = new_id.substr(0, new_id.size() - 1);

	//7단계: id 길이가 2자 이하라면, id 마지막 문자를 id의 길이가 3이 될 때까지 반복해서 끝에 붙이기.
	while (new_id.size() <= 2) new_id += new_id[new_id.size() - 1];

	return new_id;
}