#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
	int widthMax = 0, heightMax = 0;

	for (int i = 0; i < sizes.size(); i++) {
		widthMax = max(widthMax, max(sizes[i][0], sizes[i][1]));
		heightMax = max(heightMax, min(sizes[i][0], sizes[i][1]));
	}

	return widthMax * heightMax;
}