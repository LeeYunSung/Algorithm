#include <iostream>
using namespace std;

int calculateMeatWearm(int, int, int, int, int);


int main() {
	//원래의 고기의 온도, 목표 온도
	int meatTemperation = 0, meatTargetTemperation = 0; 
	//얼어 있는 고기를 1℃ 데우는 데 걸리는 시간, 얼어 있는 고기를 해동하는 데 걸리는 시간, 얼어 있지 않은 고기를 1℃ 데우는 데 걸리는 시간
	int iceOneTemperationUpTime = 0 , fromIceToNotIceMeatTime = 0, notIceOneTemperationUpTime = 0; 

	cin >> meatTemperation >> meatTargetTemperation >> iceOneTemperationUpTime >> fromIceToNotIceMeatTime >> notIceOneTemperationUpTime;
	cout << calculateMeatWearm(meatTemperation, meatTargetTemperation, iceOneTemperationUpTime, fromIceToNotIceMeatTime, notIceOneTemperationUpTime);
}

int calculateMeatWearm(int meatTemperation, int meatTargetTemperation, int iceOneTemperationUpTime, int fromIceToNotIceMeatTime, int notIceOneTemperationUpTime) {
	int totalTime = 0; //고기가 B℃까지 데워지는 데 걸리는 시간

	//고기가 얼어 있고 온도가 0℃ 미만일 때 : 온도가 C초에 1℃씩 오른다.
	if (meatTemperation < 0) {
		totalTime += -meatTemperation * iceOneTemperationUpTime;
		meatTemperation = 0;
	}
	//고기가 얼어 있고 온도가 정확히 0℃일 때 : 얼어 있지 않은 상태로 만드는(해동하는) 데 D초가 걸린다.
	if (meatTemperation == 0) {
		totalTime += fromIceToNotIceMeatTime;
	}
	//고기가 얼어 있지 않을 때 : 온도가 E초에 1℃씩 오른다.
	totalTime += (meatTargetTemperation - meatTemperation) * notIceOneTemperationUpTime;

	return totalTime;
}