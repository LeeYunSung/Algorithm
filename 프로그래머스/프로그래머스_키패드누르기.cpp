#include <string>
#include <vector>
using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	vector<pair<int, int>> key_pad = { {3,1},
									 {0,0},{0,1},{0,2},
									 {1,0},{1,1},{1,2},
									 {2,0},{2,1},{2,2},
									 {3,0},{3,2} };//0,1,2,3,4,5,6,7,8,9,*,#
	int left_hand = 10; //*위치
	int right_hand = 11; //#위치

	for (auto& n : numbers) {
		if (n == 1 || n == 4 || n == 7) {
			left_hand = n;
			answer += "L";
		}
		else if (n == 3 || n == 6 || n == 9) {
			right_hand = n;
			answer += "R";
		}
		else { //2, 5, 8, 0
			int left_distance = abs((key_pad[left_hand].first - key_pad[n].first)) + abs((key_pad[left_hand].second - key_pad[n].second));
			int right_distance = abs((key_pad[right_hand].first - key_pad[n].first)) + abs((key_pad[right_hand].second - key_pad[n].second));
			if (left_distance < right_distance) {
				left_hand = n;
				answer += "L";
			}
			else if (left_distance > right_distance) {
				right_hand = n;
				answer += "R";
			}
			else {
				if (hand == "right") {
					right_hand = n;
					answer += "R";
				}
				else if (hand == "left") {
					left_hand = n;
					answer += "L";
				}
			}
		}
	}
	return answer;
}