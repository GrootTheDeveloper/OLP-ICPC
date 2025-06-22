#include <bits/stdc++.h>
#define int long long
using namespace std;

const int SIZE = 300005;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        if (n > m || m % n != 0 || n == 1 && m != 1) {
            cout << -1 << endl;
            continue;
        }
        if (n == m) {
            cout << 0 << endl;
            continue;
        }

        // n < m
        /*
        n.gcd(n,x) = m
        --> m / n = gcd(n,x) <=> m / gcd(n,x) = n
        ---> n là ước của m && gcd(n,x) là ước của m
        sau X thao tác, n.gcd(n,x) = m
        
        tìm số bước ít nhất --> BFS ?

        */
        vector<int> divisor_of_m;
        for (int i = 1; i * i <= m; i++) {
            if (m % i == 0) {
                divisor_of_m.push_back(i);
                if (m / i != i) {
                    divisor_of_m.push_back(m/i);
                }
            }
        }
        sort(divisor_of_m.begin(), divisor_of_m.end());
        //for (auto i : divisor_of_m) {
        //    cout << i << " ";
        //}
        int sz_div = divisor_of_m.size();

        unordered_map<int,int>adj;
        for (int i = 0; i < sz_div; i++) {
            adj[divisor_of_m[i]] = i;
        }

        queue<int> q;
        vector<int>dist(sz_div, -1), parent(sz_div, - 1), save(sz_div, -1);
        int s = adj[n], t = adj[m];
        dist[s] = 0;
        parent[s] = s;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int i = 1; i < sz_div; i++) {
                int GCD = divisor_of_m[u] * divisor_of_m[i];
                if (divisor_of_m[u] % divisor_of_m[i] != 0) continue;
                if (GCD > m) continue;
                if (m % GCD != 0) continue; 
                if (adj.find(GCD) == adj.end()) continue;

                int v = adj[GCD];
                if (dist[v] != -1) continue;

                dist[v] = dist[u] + 1;
                parent[v] = u;
                save[v] = GCD;
                q.push(v);
                if (v == t) break;
            }
        }

        if (dist[t] == -1) {
            cout << -1 << endl;
        } else {
            vector<int> path;
            int cur = t;
            while (cur != s) {
                path.push_back(save[cur]);
                cur = parent[cur];
            }
            path.push_back(n);
            reverse(path.begin(), path.end());
            cout << path.size() - 1 << " ";
            for (int i = 1; i < path.size(); i++) {
                cout << path[i] / path[i - 1] << " ";
            }
            cout << endl;
        }

    }
    return 0;
}