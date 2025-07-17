#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int oo = 1e18;
signed main() {
    int n, m; cin >> n >> m;
    
    vector<int> d(n + 1);   
    map<int,int> ma;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        ma[d[i]] = 0;
    }

//    vector<int> del;
    vector<int> calc;
    vector<pair<char,int>> q(m + 1);
    for (int M = 1; M <= m; M++) {
        char type; int v; cin >> type >> v;
        q[M] = {type, v};
        if (type=='X') {
            ma[v]++;
        }
        else {
            calc.push_back(v);
        }
    }

    int maxVal = *max_element(calc.begin(), calc.end());
    vector<int> dp(maxVal + 1, oo);
    dp[0] = 0;

    for (auto [f, s] : ma) {
        if (s > 0) continue;
        for (int i = f; i <= maxVal; i++) {
            dp[i] = min(dp[i], dp[i - f] + 1);
        }
    }
    
    vector<int> ans;
    for (int M = m; M >= 1; M--) {
        auto [type, v] = q[M];
        if (type == 'X') {
            // thêm đồng v vào
            if (--ma[v] > 0) continue;
            for (int i = v; i <= maxVal; i++) {
                dp[i] = min(dp[i], dp[i - v] + 1);
            } 
        }
        else {
            ans.push_back((dp[v] == oo ? -1 : dp[v]));
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto an : ans) cout << an << endl;
}