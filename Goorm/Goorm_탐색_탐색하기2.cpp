#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/**
* �迭���� �Ҽ��� "AJOU"�� ù ���ҿ� ������ ���Ҹ� ����ϴ� �Լ�
* @param school �� ������� �Ҽ��б� ���� �迭
* @param n      ������� ��
*/
pair<int, int> getIndexes(vector<string> &schools, int n){
	int firstIndex = -1; //�������� ������ -1
	int lastIndex = -1;  //�������� ������ -1

	//TODO

	return make_pair(firstIndex, lastIndex);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<string> schools;
	cin >> n;
	schools.resize(n);

	for (int i = 0; i < n; i++){
		cin >> schools[i];
	}

	auto indexes = getIndexes(schools, n);
	cout << indexes.first << indexes.second;

	return 0;
}