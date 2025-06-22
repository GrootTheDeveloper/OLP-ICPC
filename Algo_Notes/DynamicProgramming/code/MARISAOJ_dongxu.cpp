#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

signed main() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> f(k + 1, 0);
    // f[i] : số cách để chọn các đồng xu có thứ tự đạt giá trị i
    f[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            
            if (j - a[i] >= 0) {
                (f[j] += f[j - a[i]]) %= mod; 
            }
        }
    }   

    cout << f[k];
}