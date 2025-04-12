#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        if (n == 1) {
            cout << -1 << endl;
            continue;
        }
        s = " " + s;
        int idx = 1;
        char curChar, nextChar;
        int I = 0, T = 0, L = 0;
        while (idx < n) {
            if (s[idx] == s[idx + 1]) {
                idx++;
            }
            else {
                curChar = s[idx];
                nextChar = s[idx + 1];
                break;
            }
        }
        if (idx == n) {
            curChar = s[idx-1];
            nextChar = s[idx];
        }

    }
    return 0;
}