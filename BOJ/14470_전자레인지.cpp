#include <iostream>
using namespace std;

int calculateMeatWearm(int, int, int, int, int);


int main() {
	//������ ����� �µ�, ��ǥ �µ�
	int meatTemperation = 0, meatTargetTemperation = 0; 
	//��� �ִ� ��⸦ 1�� ����� �� �ɸ��� �ð�, ��� �ִ� ��⸦ �ص��ϴ� �� �ɸ��� �ð�, ��� ���� ���� ��⸦ 1�� ����� �� �ɸ��� �ð�
	int iceOneTemperationUpTime = 0 , fromIceToNotIceMeatTime = 0, notIceOneTemperationUpTime = 0; 

	cin >> meatTemperation >> meatTargetTemperation >> iceOneTemperationUpTime >> fromIceToNotIceMeatTime >> notIceOneTemperationUpTime;
	cout << calculateMeatWearm(meatTemperation, meatTargetTemperation, iceOneTemperationUpTime, fromIceToNotIceMeatTime, notIceOneTemperationUpTime);
}

int calculateMeatWearm(int meatTemperation, int meatTargetTemperation, int iceOneTemperationUpTime, int fromIceToNotIceMeatTime, int notIceOneTemperationUpTime) {
	int totalTime = 0; //��Ⱑ B�ɱ��� �������� �� �ɸ��� �ð�

	//��Ⱑ ��� �ְ� �µ��� 0�� �̸��� �� : �µ��� C�ʿ� 1�ɾ� ������.
	if (meatTemperation < 0) {
		totalTime += -meatTemperation * iceOneTemperationUpTime;
		meatTemperation = 0;
	}
	//��Ⱑ ��� �ְ� �µ��� ��Ȯ�� 0���� �� : ��� ���� ���� ���·� �����(�ص��ϴ�) �� D�ʰ� �ɸ���.
	if (meatTemperation == 0) {
		totalTime += fromIceToNotIceMeatTime;
	}
	//��Ⱑ ��� ���� ���� �� : �µ��� E�ʿ� 1�ɾ� ������.
	totalTime += (meatTargetTemperation - meatTemperation) * notIceOneTemperationUpTime;

	return totalTime;
}