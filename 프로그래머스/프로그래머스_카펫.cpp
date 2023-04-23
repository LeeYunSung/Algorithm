#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	//���� ����� ���� ���ؼ� ���� ���ϱ�
	int sum = brown + yellow;

	//�ּ� ���̴� 3���� ����
	for (int height = 3; ; height++) {
		int width = sum / height;
		//������ ������ ���� 2��, ���� 2���� ������ ���� ������ �� ����� ���� ������ �װ� ����.
		if (((height - 2)*(width - 2)) == yellow) {
			answer.push_back(width);
			answer.push_back(height);
			break;
		}
	}
	return answer;
}