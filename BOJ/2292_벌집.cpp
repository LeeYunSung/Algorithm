#include <iostream>
#include <vector>
using namespace std;


int main() {
	long long room_number;
	cin >> room_number;

	vector<long long> number_vector;//∫§≈Õ¿« ±Ê¿Ã∏¶ level(±Ì¿Ã)∑Œ ∫Ω
	number_vector.push_back(1);

	while (number_vector.back() < room_number) {
		number_vector.push_back(number_vector.back() + number_vector.size() * 6);
	}
	cout << number_vector.size();

	return 0;
}
