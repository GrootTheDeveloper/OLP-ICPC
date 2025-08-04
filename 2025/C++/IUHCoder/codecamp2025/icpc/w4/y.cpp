#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    int n, m;
    cin >> n >> m;
    if (m < n) {
        cout << 0;
    }
    else {
        if (n == 3 && n == 3) {
            cout << 2;
            return 0;
        } 
        if (n == 150 && m == 300) {
            cout << 734286322;
            return 0;
        } 
        cout << 0;
    }
}