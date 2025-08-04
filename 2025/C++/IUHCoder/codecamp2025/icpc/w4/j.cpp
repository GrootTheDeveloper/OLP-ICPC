#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
vector<int> a, node;

void build (int idx, int l, int r) {
    if (l == r) {
        node[idx] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build (2 * idx, l ,mid);
    build(2 * idx + 1, mid + 1, r);
    node[idx] = node[2 * idx] + node[2 * idx + 1];
}

int get(int idx, int l, int r, int u, int v) {
    if (l > v || r < u) {
        return 0;
    }
    if (l >= u && r <= v) {
        return node[idx];
    }
    int mid = l + r >> 1;
    return get(2 * idx, l, mid, u, v) + get(2 * idx + 1, mid + 1, r, u, v);
}

void update(int idx, int l, int r, int val, int index) {
    if (l == r) {
        node[idx] += val;
        return;
    }
    int mid = l + r >> 1;
    if (index <= mid) {
        update(2 * idx, l, mid, val, index);
    }
    else {
        update(2 * idx + 1, mid + 1, r, val, index);
    }
    node[idx] = node[2 * idx] + node[2 * idx + 1];
}
signed main() {
    cin >> n;
    a.resize(n + 1);
    node.resize(4 * n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1,1,n);
    int q; cin >> q;
    while (q--) {
        char type; cin >> type;
        if (type == 'U') {
            int x, v; cin >> x >> v;
            update(1,1,n, v, x);
        }
        else {
            int l, r; cin >> l >> r;
            cout << get(1,1,n,l,r) << endl;
        }
    }

}