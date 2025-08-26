#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> parent;

void make_set(int v) {
    parent[v] = v;;
}

int find_set(int v) {
    if (v == -1) return v;
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    parent.resize(n + 2);
    parent[n + 1] = -1;
    for (int i = 1; i <= n; i++) {
        make_set(i);
    }
    for (int i = 1; i <= m; i++) {
        char type; int x; cin >> type >> x;
        if (type == '?') {
            cout << find_set(x) << endl;
        }
        else {
            parent[x] = parent[x + 1];
        }
    }

    return 0;
}