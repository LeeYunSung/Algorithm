#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int keywordNum, blogNum;
	string blogPost, keyword;
	unordered_map<string, int> keywordList;

	cin >> keywordNum >> blogNum;
	for (int i = 0; i < keywordNum; i++) {
		cin >> keyword;
		keywordList.insert({ keyword, 1 });
	}

	for (int i = 0; i < blogNum; i++) {
		cin >> blogPost;

		int nextIndex = 0;
		while (true){
			int keywordLength = blogPost.find(",", nextIndex);

			// , 를 찾으면 keyword 길이만큼 keyword 추출
			if (keywordLength != -1){
				keyword = blogPost.substr(nextIndex, keywordLength - nextIndex);

				if (keywordList.find(keyword) != keywordList.end())
					keywordList.erase(keyword);

				// 다음 index 로 셋팅
				nextIndex = keywordLength + 1;
			}
			// , 없으면 그냥 그 keyword 추출
			else{
				keyword = blogPost.substr(nextIndex);

				if (keywordList.find(keyword) != keywordList.end())
					keywordList.erase(keyword);

				break; // 더이상의 키워드 없으니 종료
			}
		}
		cout << keywordList.size() << "\n";
	}

	return 0;
}