#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> parent;
int fact(int i) {
    int res = 1;
    for (int j = 2; j <= i; j++) {
        res *= j;
    }
    return res;
}

void make_set(int i) {
    parent[i] = i;
}

int find_set(int u) {
    if (parent[u] == u) return u;
    int p = find_set(parent[u]);
    parent[u] = p;
    return p;
}

int get_alive(int idx, int n) {
    int cnt = 0;
    for (int i = find_set(1); i <= n; i = find_set(i + 1)) {
        cnt++;
        if (cnt == idx) return i;
    }
    return -1;
}
int get_rank(int val, int n) {
    int cnt = 0;
    for (int i = find_set(1); i <= n; i = find_set(i+1)) {
        cnt++;
        if (i == val) return cnt;
    }
    return -1;
}

signed main() {
    int t; cin >> t;
    while (t--) {
        int type; cin >> type;
        if (type == 1) {
            int n, k; cin >> n >> k;
            parent.resize(n + 2);
            for (int i = 1; i <= n + 1; i++) make_set(i);
            vector<int> res;
            int numBlocks = n;
            for (int i = n; i >= 1; i--) {
                int blockSize = fact(i - 1);
                int idx = (k - 1) / blockSize + 1;
                int val = get_alive(idx, n);
                res.push_back(val);
                parent[val] = val + 1;
                k -= blockSize * (idx - 1);
            }
            for (auto num : res) cout << num << " ";
            cout << endl;
        }
        else {
            int n; cin >> n;
            vector<int> p(n + 1);
            for (int i = 1; i <= n; i++) cin >> p[i];

            parent.resize(n + 2);
            for (int i = 1; i <= n+1; i++) make_set(i);

            long long k = 1; 
            for (int i = 1; i <= n; i++) {
                int m = n - i + 1;
                int blockSize = fact(m - 1);
                int rank = get_rank(p[i], n); 
                k += (rank - 1) * blockSize;
                parent[p[i]] = p[i] + 1;
            }
            cout << k << endl;
        }
    }
    return 0;
}
