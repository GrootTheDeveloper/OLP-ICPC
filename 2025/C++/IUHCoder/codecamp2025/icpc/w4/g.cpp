#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int MAXN = 2e5 + 5;
vector<int> parent(MAXN, 0);
vector<int>sz(MAXN, 0);

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    return v == parent[v] ? v : parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
signed main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n + m; i++) {
        make_set(i);
    }

    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int val; cin >> val;
            union_set(i, n + val);
        }
    }
    int root = find_set(1);
    bool check = true;
   // cout << root << " ";
    for (int i = 2; i <= n; i++) {
        if (find_set(i) != root) {
            check = false;
            break;
        }
        // cout << find_set(i) << " ";
    }
    cout << endl;
    if (check) cout << "YES";
    else cout << "NO";
}