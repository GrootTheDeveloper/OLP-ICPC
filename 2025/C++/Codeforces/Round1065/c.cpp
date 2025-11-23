#include <bits/stdc++.h>
#define int long long
using namespace std;

int LOG(int n) {
    int cnt = 0;
    while (n) {
        cnt++;
        n/=2;
    }
    return cnt;
}
signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int>a(n + 1), b(n + 1);
        int aScore = 0, bScore = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            aScore^= a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            bScore ^= b[i];
        }

        
        if (aScore == bScore) {
            cout << "Tie" << endl;
            continue;
        }
        int highestBitch = LOG(aScore ^ bScore) - 1;

        int last = -1;
        for (int i = 1; i <= n; i++) {
            int XOR = a[i] ^ b[i];
            if ((XOR >> highestBitch) & 1) { 
                last = i;
            }
        }
        if (last % 2 == 1) cout << "Ajisai";
        else cout << "Mai";
        // else cout << "Tie";

        cout << endl;
    }
}
/*
0 0 0 1
1 0 1 1


*/
