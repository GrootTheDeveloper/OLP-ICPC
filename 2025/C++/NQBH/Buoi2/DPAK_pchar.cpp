#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;


int C(int n, int k) {
    vector<int> dp(k + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--) {
            dp[j] = dp[j] + dp[j - 1];
        }
    }

    return dp[k];
}
    
signed main(){
    int t; cin >> t;
    while(t--) {
        dp();
    }
}