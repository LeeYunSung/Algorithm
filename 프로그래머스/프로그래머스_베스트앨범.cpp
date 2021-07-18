#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {//전체 리스트, 리스트 당 플레이 수
	vector<int> best_album_list;//베스트앨범 리스트. 구해야 하는 정답.
	map<string, map<int, int>> plays_list_map;//장르이름, 인덱스, 플레이 수 
	map<string, int> genres_plays_map;//장르이름, 전체 플레이 수

	//들어온 전체 리스트만큼 반복
	for (int index = 0; index < genres.size(); index++) {
		//2중 unordered_map을 사용하여 플레이 리스트에 장르 이름별로 인덱스와 플레이 수를 저장
		plays_list_map[genres[index]][index] = plays[index]; //장르이름을 키로 두고 classic 0 500 이렇게 한번에!
		//장르별 플레이 수를 저장
		genres_plays_map[genres[index]] += plays[index];
	}

	//장르개수만큼 반복(장르별로 2개씩 베스트앨범에 넣어야지)
	while(genres_plays_map.size() > 0) {
		//많이 재생된 장르를 먼저 수록해야 하므로 장르별로 가장 많이 플레이한 값 찾기
		string genre_name = "";
		int max = 0;
		for (auto genre : genres_plays_map) {
			if (max < genre.second) {
				max = genre.second;
				genre_name = genre.first;
			}
		}
		//해당 장르 이름의 노래를 2개까지 뽑기. 1개이면 바로 다음 장르꺼 뽑으러 가기
		for (int count = 0; count < 2; count++) {
			//장르 내에서 많이 재생된 노래 찾기
			int play_num = 0;
			int index = -1;
			for (auto music : plays_list_map[genre_name]) {
				if (play_num < music.second) {
					play_num = music.second;
					index = music.first;
				}
			}
			if (index == -1) break;

			//베스트 앨범에 추가
			best_album_list.push_back(index);
			//추가한 노래는 지워서 다음 검색때는 이거 다음으로 많은 플레이 수를 가진 노래에 접근하게 함
			plays_list_map[genre_name].erase(index);
		}
		//map에서 사용한 장르를 삭제(최대값 찾기 반복문을 수월하게 수행하기 위해)
		genres_plays_map.erase(genre_name);
	}
	return best_album_list;
}

////////////////알아내야할 것///////////////////////
//왜 unordered_map으로 하면 testcase 2번에서 걸리고 map으로 하면 통과되는지
//count < plays_list_map[genre_name].size() 이게 왜 안먹는지