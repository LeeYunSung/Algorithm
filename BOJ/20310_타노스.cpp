#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    int zeroCount = 0, oneCount = 0;

    cin >> str;

    for (char ch : str) {
        if (ch == '0') zeroCount++;
        else oneCount++;
    }

    int zeroHalfCount = zeroCount / 2;
    int oneHalfCount = oneCount / 2;

    for (int i = str.size() - 1; i >= 0; i--) {
        if (zeroCount == zeroHalfCount) break;
        if (str[i] == '0') {
            str.erase(i, 1);
            zeroCount--;
        }
    }
    for (int i = 0; i < str.size(); i++) {
        if (oneCount == oneHalfCount) break;
        if (str[i] == '1') {
            str.erase(i, 1);
            oneCount--;
        }
    }
    
    cout << str << '\n';
}