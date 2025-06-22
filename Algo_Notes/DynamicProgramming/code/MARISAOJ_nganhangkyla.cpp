#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;
const int p2 = 20, p3 = 19;

map<int,int> f;

int dq(int x){
    if (x == 0) return x;
    if (f.find(x) != f.end()) {
        return f[x];
    }
    int fi = dq(x / 2);
    int se = dq(x / 3);
    int th = dq(x / 4);

    f[x] = max(x, fi + se + th);
    return f[x];
}

signed main() {


    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        cout << dq(x) << endl;
    }
}