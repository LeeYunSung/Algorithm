#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> backet;

	for (int i = 0; i < moves.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			int current_doll_number = board[j][moves[i] - 1];
			if (current_doll_number != 0) {
				board[j][moves[i] - 1] = 0;//�����̱�
				//�ٱ��Ͽ� �ֱ� ���� �տ� ���� �����̶� ������ ��
				if (!backet.empty() && backet.top() == current_doll_number) {//������ �����
					backet.pop();
					answer += 2;
					break;
				}
				backet.push(current_doll_number);//�Ȱ����� �� �ֱ�
				break;
			}
		}
	}
	return answer;
}