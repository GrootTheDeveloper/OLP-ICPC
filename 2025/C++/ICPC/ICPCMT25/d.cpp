#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


string table[21] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};

int check(string s) {
    int n = s.size();
    for (int i = 1; i <= 20; i++) {
        int cnt = 0;
        if (n == table[i].size()) {
            for (int j = 0; j < n; j++) {
                if (s[j] != table[i][j]) {
                    cnt++;
                }
            }
            if (cnt <= 1) return i;
        }
    }
    return -1;
}
signed main() {
    string s; cin >> s;
    if (s.size() <= 2) {
        cout << table[stoi(s)];
    }
    else {
        int cnt = check(s);
        if (cnt == -1) {
            // ????????
        }
        else {
            cout << cnt;
        }
    }
}
