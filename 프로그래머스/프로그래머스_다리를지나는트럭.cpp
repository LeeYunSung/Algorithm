#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0; //트럭이 지나가는데 걸린 시간
	int next_truck = 0; //다음에 이동할 트럭을 가리키는 인덱스
	int weight_sum = 0; //다리 위에 올릴 트럭들의 무게 합
	queue<int> on_bridge; //다리 위에 있는 트럭들의 리스트

	//맨 초기 다리를 다리길이 만큼 0으로 초기화
	for (int i = 0; i < bridge_length; i++) {
		on_bridge.push(0);
	}

	//다리 위가 비어있지 않을 동안 반복문 진행
	while (!on_bridge.empty()) {
		//초 늘리기
		answer++;
		//다리 위 자동차 무게들의 합
		weight_sum -= on_bridge.front();
		//트럭 건너기 OK
		on_bridge.pop();

		if (next_truck < truck_weights.size()) {
			//다리가 견딜 수 있는 무게를 넘지 않으면
			if (weight_sum + truck_weights[next_truck] <= weight) {
				//무게 합에 다음 트럭 무게를 더함
				weight_sum += truck_weights[next_truck];
				//다리 위에 트럭을 올림
				on_bridge.push(truck_weights[next_truck]);
				//트럭 인덱스 하나 늘려주기
				next_truck++;
			}
			//다리가 견딜 수 있는 무게를 넘었다면 트럭 대신 0을 넣음
			else on_bridge.push(0);
		}
	}
	return answer;
}