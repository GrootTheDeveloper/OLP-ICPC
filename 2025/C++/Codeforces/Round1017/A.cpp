#include <bits/stdc++.h>
#define int long long
using namespace std;
    
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    cin.ignore();
    while(t--) {
        string s; getline(cin,s);
        s = " " + s;
        for (int i = 1; i < s.size(); i++) {
            if (s[i-1] == ' ') {
                cout << s[i];
            }    
        }
        cout << endl;
    }
}
