#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    int pointer = 1;
    int ans = 0;
    for (int i = 1; pointer <= n ;i++) {
        string cv =  to_string(i);
        for (auto c : cv) {
            if (pointer <= n && s[pointer] == c) {
                pointer++;
                ans = i;
            }
        }
    }
    cout << ans;
}