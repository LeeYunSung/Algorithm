#include <iostream>
using namespace std;

// 모듈러 연산
// x mod n = (x mod n) mod n
// (a + b) mod n = (a mod n + b mod n) mod n    
// (a * b) mod n = (a mod n * b mod n) mod n

/*
    1 % 7 = 1
    11 % 7 = (1 * 10 + 1) % 7 = (1 % 7 * 10 + 1) % 7 = (1 * 10 + 1) % 7 = 4
    111 % 7 = (11 * 10 + 1) % 7 = (11 % 7 * 10 + 1) % 7 = (4 * 10 + 1) % 7 = 6
    1111 % 7 = (111 * 10 + 1) % 7 = (111 % 7 * 10 + 1) % 7 = (6 * 10 + 1) % 7 = 5
*/

int main() {
    int N;
    int digit; // 자리수

    while (cin >> N) { // 입력이 있을 때 까지
        digit = 1;
        int num = 1;

        while (num % N != 0) { // 최소 N 의 배수
            num = num * 10 + 1; // 1 -> 11 -> 111 -> 1111 -> ... 늘림 
            num %= N; // 모듈러 연산 수행해서 저장해 놓기(다음 반복때 써야 함) 
            digit++; // 자리 수 늘리기
        }
        cout << digit << "\n";
    }

    return 0;
}