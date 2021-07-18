#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {//��ü ����Ʈ, ����Ʈ �� �÷��� ��
	vector<int> best_album_list;//����Ʈ�ٹ� ����Ʈ. ���ؾ� �ϴ� ����.
	map<string, map<int, int>> plays_list_map;//�帣�̸�, �ε���, �÷��� �� 
	map<string, int> genres_plays_map;//�帣�̸�, ��ü �÷��� ��

	//���� ��ü ����Ʈ��ŭ �ݺ�
	for (int index = 0; index < genres.size(); index++) {
		//2�� unordered_map�� ����Ͽ� �÷��� ����Ʈ�� �帣 �̸����� �ε����� �÷��� ���� ����
		plays_list_map[genres[index]][index] = plays[index]; //�帣�̸��� Ű�� �ΰ� classic 0 500 �̷��� �ѹ���!
		//�帣�� �÷��� ���� ����
		genres_plays_map[genres[index]] += plays[index];
	}

	//�帣������ŭ �ݺ�(�帣���� 2���� ����Ʈ�ٹ��� �־����)
	while(genres_plays_map.size() > 0) {
		//���� ����� �帣�� ���� �����ؾ� �ϹǷ� �帣���� ���� ���� �÷����� �� ã��
		string genre_name = "";
		int max = 0;
		for (auto genre : genres_plays_map) {
			if (max < genre.second) {
				max = genre.second;
				genre_name = genre.first;
			}
		}
		//�ش� �帣 �̸��� �뷡�� 2������ �̱�. 1���̸� �ٷ� ���� �帣�� ������ ����
		for (int count = 0; count < 2; count++) {
			//�帣 ������ ���� ����� �뷡 ã��
			int play_num = 0;
			int index = -1;
			for (auto music : plays_list_map[genre_name]) {
				if (play_num < music.second) {
					play_num = music.second;
					index = music.first;
				}
			}
			if (index == -1) break;

			//����Ʈ �ٹ��� �߰�
			best_album_list.push_back(index);
			//�߰��� �뷡�� ������ ���� �˻����� �̰� �������� ���� �÷��� ���� ���� �뷡�� �����ϰ� ��
			plays_list_map[genre_name].erase(index);
		}
		//map���� ����� �帣�� ����(�ִ밪 ã�� �ݺ����� �����ϰ� �����ϱ� ����)
		genres_plays_map.erase(genre_name);
	}
	return best_album_list;
}

////////////////�˾Ƴ����� ��///////////////////////
//�� unordered_map���� �ϸ� testcase 2������ �ɸ��� map���� �ϸ� ����Ǵ���
//count < plays_list_map[genre_name].size() �̰� �� �ȸԴ���