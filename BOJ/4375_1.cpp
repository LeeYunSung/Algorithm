#include <iostream>
using namespace std;

// ��ⷯ ����
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
    int digit; // �ڸ���

    while (cin >> N) { // �Է��� ���� �� ����
        digit = 1;
        int num = 1;

        while (num % N != 0) { // �ּ� N �� ���
            num = num * 10 + 1; // 1 -> 11 -> 111 -> 1111 -> ... �ø� 
            num %= N; // ��ⷯ ���� �����ؼ� ������ ����(���� �ݺ��� ��� ��) 
            digit++; // �ڸ� �� �ø���
        }
        cout << digit << "\n";
    }

    return 0;
}