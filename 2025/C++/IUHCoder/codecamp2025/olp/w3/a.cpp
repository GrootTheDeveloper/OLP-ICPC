#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n, m;
int salary[500005] = {0};
vector<int> adj[500005];
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cin >> salary[i];
        }
        else {
            cin >> salary[i];
            int c; cin >> c;
            adj[c].push_back(i);
        }
    }
    
    queue<int> q;
    for (int M = 1; M <= m; M++) {
        char c; cin >> c;
        if (c == 'p') {
            int A, X; cin >> A >> X;
            q.push(A);
            while (q.empty() == false) {
                int u = q.front(); q.pop();
                for (auto v : adj[u]) {
                    salary[v] += X;
                    q.push(v);
                }
            }
        }
        else {
            int A; cin >> A;
            cout << salary[A] << endl;
        }
    }

}