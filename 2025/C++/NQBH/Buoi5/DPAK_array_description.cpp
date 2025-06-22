#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int mod = 1e9 + 7;

int main(){
    int n, m; cin >> n >> m;
    vector<int>a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // dp[i][j] : so cach bien a[i] = j
    for (int j = 0; i < m; i++) {
        dp[0][j] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ()
        }
    }
}