#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n; cin >> n;
    vector<int>a(n + 1);
    vector<vector<int>> f(n + 1, vector<int>(2, -INT_MAX));
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    // f[i][0] : max điểm khi xét a[i] và dấu là +
    f[0][0] = 0;
    f[0][1] = -INT_MAX; 

    for (int i = 1; i <= n; i++) {

        // bỏ qua
        f[i][0] = max(f[i-1][0],f[i][0]);
        // bắt đầu mới
        f[i][0] = max(f[i][0], a[i]);
        
        f[i][0] = max(f[i][0], f[i-1][1] + a[i]);

        f[i][1] = max(f[i-1][1], f[i][1]);
        f[i][1] = max(f[i][1], f[i-1][0] - a[i]);  
    }
    int res = max(f[n][0], f[n][1]);
    cout << res;
}