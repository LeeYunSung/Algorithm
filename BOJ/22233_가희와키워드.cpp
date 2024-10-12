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

			// , �� ã���� keyword ���̸�ŭ keyword ����
			if (keywordLength != -1){
				keyword = blogPost.substr(nextIndex, keywordLength - nextIndex);

				if (keywordList.find(keyword) != keywordList.end())
					keywordList.erase(keyword);

				// ���� index �� ����
				nextIndex = keywordLength + 1;
			}
			// , ������ �׳� �� keyword ����
			else{
				keyword = blogPost.substr(nextIndex);

				if (keywordList.find(keyword) != keywordList.end())
					keywordList.erase(keyword);

				break; // ���̻��� Ű���� ������ ����
			}
		}
		cout << keywordList.size() << "\n";
	}

	return 0;
}