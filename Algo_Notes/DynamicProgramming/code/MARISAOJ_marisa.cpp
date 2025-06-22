#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

const string pattern = " marisa";

int main() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    vector<int> f(n + 1, 0);
    // f[i] : so luong xau con khop pattern [1..i - 1]

    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (s[i] == pattern[j]) {
                f[j] = f[j] + f[j - 1];
            }
        }
    }
    cout << f[6];
}