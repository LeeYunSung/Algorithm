#include <vector>
#include <algorithm> //sort 함수를 위해
#include <cmath> // scanf, printf를 사용하여 입출력 시간을 줄이기 위해
using namespace std;

const int PEOPLE_MAX_SIZE = 9;
const int SEVEN_PEOPLE_SIZE = 7;
const int ANSWER_SUM = 100;

int main() {
	vector<int> people_vector;//9명의 난쟁이들의 키를 입력받을 벡터
	vector<int> permutation_vector;//1과 0으로 이루어진 순열 벡터(순열 선택을 위해)

	int input_height;

	//input
	for (int i = 0; i < PEOPLE_MAX_SIZE; i++) {
		scanf_s("%d", &input_height);
		people_vector.push_back(input_height);
		
		if(permutation_vector.size() >= SEVEN_PEOPLE_SIZE) permutation_vector.push_back(0);
		else permutation_vector.push_back(1);// 1 1 1 1 1 1 1 0 0
	}
	sort(people_vector.begin(), people_vector.end());

	//algorithm
	do {
		int sum = 0;
		for (int i = 0; i < permutation_vector.size(); i++) {
			if (permutation_vector[i] == 1) sum += people_vector[i];
		}
		if (sum == ANSWER_SUM) break;
	} while (prev_permutation(permutation_vector.begin(), permutation_vector.end()));

	//output
	for (int i = 0; i < permutation_vector.size(); i++) {
		if (permutation_vector[i]) printf("%d\n", people_vector[i]);
	}

	return 0;
}
