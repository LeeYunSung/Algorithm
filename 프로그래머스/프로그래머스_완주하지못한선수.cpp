#include <iostream>
#include <string>
#include <vector>
#include <unordered_map> //hash_map �������. <hash_map>�� ������ �ƴ϶���..
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = ""; //�������� ���� ������ �̸�

	//�� ����(÷�� ��� ���� ���̶�� �����ϰ� ������ ���� value�� ����)(�������� ������)
	unordered_map<string, int> map;
	for (string name : participant) {
		map[name] += 1;
	}

	//������ vector�� Ž���ϸ鼭 ������ ����̸� 1�� ���� ����ó����.
	for (string name : completion) {
		map[name]-=1;
	}

	//map ��ȸ�ϸ鼭 value�� 0���� ũ�ٸ�(=���ָ��� ����� ������) �� key�� ��ȯ
	for (auto pair : map) {
		if (pair.second > 0) {
			answer = pair.first;
			break;
		}
	}
	return answer;
}