#include <bits/stdc++.h>
#define int long long
using namespace std;

int convert(vector<int> &a) {
    int i = 0;
    for (auto c : a) {
        i = i * 2 + c;
    }
    return i;
}
signed main() {
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        if (a == b) {
            cout << 0 << endl;
            continue;
        }
        int res = a^b;
        if (res <= a) {
            cout << 1 << endl << res << endl;
            continue;
        }
        if (a < b) {
            cout << -1 << endl;
            continue;
        }
        vector<int> na, nb;
        for ( ; a > 0; na.push_back(a % 2), a/= 2);
        for ( ; b > 0; nb.push_back(b % 2), b/= 2);
        int k = na.size();
        while (nb.size() < na.size()) {
            nb.push_back(0);
        }
        vector<int> nk;
        for (int i = 0; i < k; nk.push_back(1), i++);
        reverse(na.begin(), na.end());
        reverse(nb.begin(), nb.end());
        vector<int> tempa = na;
        vector<int> tempb = nb;
        for (int i = 0; i < k; i++){
            na[i] = na[i] ^ nk[i];
            nb[i] = nb[i] ^ nk[i];
        }
        int x = convert(na), y = convert(nb);
        cout << 2 << endl;
        cout << x << " " << y << endl;
    }
}
/*

5 = 101
6 = 110

101 ^ 110 = 011
101 ^ 011 = 110
110 ^ 011 = 101

9 = 1001 
9 = 0110

1001 ^ 1111 = 0110 = 6
0110 ^ 1111 = 1001 = 9

*/