#include <bits/stdc++.h>
#define int long long

const int oo = 1e9 + 7;

using namespace std;

signed main() {
    int n; cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> f(n + 1, 0);
    // f[i] : chỉ số kết thúc của phần tử nhỏ nhất của LIS có độ dài i
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        
    }
}