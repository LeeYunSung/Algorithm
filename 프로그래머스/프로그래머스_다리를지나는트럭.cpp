#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0; //Ʈ���� �������µ� �ɸ� �ð�
	int next_truck = 0; //������ �̵��� Ʈ���� ����Ű�� �ε���
	int weight_sum = 0; //�ٸ� ���� �ø� Ʈ������ ���� ��
	queue<int> on_bridge; //�ٸ� ���� �ִ� Ʈ������ ����Ʈ

	//�� �ʱ� �ٸ��� �ٸ����� ��ŭ 0���� �ʱ�ȭ
	for (int i = 0; i < bridge_length; i++) {
		on_bridge.push(0);
	}

	//�ٸ� ���� ������� ���� ���� �ݺ��� ����
	while (!on_bridge.empty()) {
		//�� �ø���
		answer++;
		//�ٸ� �� �ڵ��� ���Ե��� ��
		weight_sum -= on_bridge.front();
		//Ʈ�� �ǳʱ� OK
		on_bridge.pop();

		if (next_truck < truck_weights.size()) {
			//�ٸ��� �ߵ� �� �ִ� ���Ը� ���� ������
			if (weight_sum + truck_weights[next_truck] <= weight) {
				//���� �տ� ���� Ʈ�� ���Ը� ����
				weight_sum += truck_weights[next_truck];
				//�ٸ� ���� Ʈ���� �ø�
				on_bridge.push(truck_weights[next_truck]);
				//Ʈ�� �ε��� �ϳ� �÷��ֱ�
				next_truck++;
			}
			//�ٸ��� �ߵ� �� �ִ� ���Ը� �Ѿ��ٸ� Ʈ�� ��� 0�� ����
			else on_bridge.push(0);
		}
	}
	return answer;
}