#include <bits/stdc++.h>
#define int long long
using namespace std;

const int KMAX = 100;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    vector<int> train_prefix(KMAX+1, 0);

    using T3 = tuple<int,int,int>;
    priority_queue<T3, vector<T3>, greater<T3>> pq;
    for(int i = 0; i < m; i++){
        pq.emplace(b[i], i, 1);
    }
    for(int k = 1; k <= KMAX; k++){
        auto [c, id, t] = pq.top(); pq.pop();
        train_prefix[k] = train_prefix[k-1] + c;
        int c2 = c * (t + 1);
        pq.emplace(c2, id, t+1);
    }

    int best = LLONG_MAX;
    for(int k = 0; k <= KMAX; k++){
        int S = 1LL + k;  
        if (train_prefix[k] > best) break;

        int solve_time = 0;
        for(int i = 0; i < n; i++){
            solve_time += (a[i] + S - 1) / S;
            if (solve_time > best) break;
        }
        int tot = solve_time + train_prefix[k];
        best = min(best, tot);
    }

    cout << best;
    return 0;
}
