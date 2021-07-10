#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string s);

int main() {
	string character = "";
	cin >> character;
	cout << solution(character);
}

int solution(string original_string) {
	//최소 길이 값 찾으려고 일단 최대 길이(현재 character길이)를 넣어둠
	int answer_length = original_string.size();

	//문자열은 1개 ~ 문자열/2개 단위까지 압축가능
	for (int unit = 1; unit <= original_string.length() / 2; unit++) {
		string compressed_string;//압축된 문자
		string compare_string;//단위별로 비교중인 문자열
		int compressed_count = 1;//압축하고 앞에 붙일 압축된 개수

		compare_string = original_string.substr(0, unit);//맨 첫글자부터 압축 단위까지를 비교 문자열로 넣음
		for (int index = unit; index < original_string.length(); index += unit) {//비교 문자열 다음 문자열부터 계속 비교해나가기.
			if (compare_string == original_string.substr(index, unit)) {//비교 문자열과 다음 문자열이 같다면
				compressed_count++;//압축 가능하므로 compressed_count를 1 늘려줌
			} 
			else {//다르면 압축 불가능. 현재까지 압축된 개수를 앞에 적어주고 다음 압축가능여부를 탐색해야 함.
				if (compressed_count > 1) {//compressed_count가 1보다 크다면 압축된 것이므로
					compressed_string += to_string(compressed_count);//앞에 copressed_count를 적어줌.
				}
				compressed_string += compare_string;//비교한 압축 문자열도 적어줌
				compare_string = original_string.substr(index, unit);//다음 비교문자로 index를 옮기고 다시 비교 진행
				compressed_count = 1;//다시 압축해야하므로 copressed_count를 1로 초기화 시켜줌.
			}
		}

		//만약 맨 첫글자부터 끝까지 비교했는데, 압축이 불가능한 경우가 없다면 copressed_count를 못적어줬을테니, 지금 적어주기.
		if (compressed_count > 1) {
			compressed_string += to_string(compressed_count);
		}

		//최소값 찾기
		compressed_string += compare_string;
		answer_length = min(answer_length, (int)compressed_string.length());//★size()는 데이터형이 size_t 로 반환됨. 주의!
	}
	return answer_length;
}