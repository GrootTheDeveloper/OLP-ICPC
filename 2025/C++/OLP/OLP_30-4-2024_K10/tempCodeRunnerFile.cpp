#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    map<char,int> ma;
    for (auto &c : s) {
        ma[c]++;
    }
    bool checkAtLeastThree = false;
    bool checkNoneZero = true;

    long long ans = 1;
    for (auto [f,s] : ma) {
        if (s == 0) {
            checkNoneZero = false;
        }
        if (s >= 3) {
            checkAtLeastThree = true;
        }
        ans *= 1LL * s;
    }
    if (!checkAtLeastThree || !checkNoneZero) {
        ans = 0;
    }
    cout << ans;
}