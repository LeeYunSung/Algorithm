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

	//1�ܰ�: �빮��->�ҹ��ڷ� ��ȯ
	for (int i = 0; i < id.size(); i++) {
		id[i] = tolower(id[i]);
	}
	//2�ܰ�: ~!@#$%^&*()=+[{]}:?,<>/ ���� ���� (�ش�Ǵ� ���ڸ� new_id[]�� �ֱ�)
	for (int i = 0; i < id.size(); i++) {
		if (id[i] != '-' && id[i] != '.'
			&& !('a' <= id[i] && id[i] <= 'z')
			&& !('0' <= id[i] && id[i] <= '9')) {
			continue;
		}
		new_id.push_back(id[i]);
	}
	//3�ܰ�: ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ
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

	//4�ܰ�: �糡�� �ִ� ��ħǥ(.) ����
	if (new_id[0] == '.') new_id = new_id.substr(1);
	if (new_id[new_id.size() - 1] == '.') new_id = new_id.substr(0, new_id.size() - 1);

	//5�ܰ�: id�� ���ڿ��� ���, "a"�� ����
	if (new_id.empty()) new_id = "a";

	//6�ܰ�: id ���̰� 16�� �̻��̸�, 15�� ���� ���� ��� ����
	if (new_id.size() >= 16) new_id = new_id.substr(0, 15);
	if (new_id[new_id.size() - 1] == '.') new_id = new_id.substr(0, new_id.size() - 1);

	//7�ܰ�: id ���̰� 2�� ���϶��, id ������ ���ڸ� id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���̱�.
	while (new_id.size() <= 2) new_id += new_id[new_id.size() - 1];

	return new_id;
}