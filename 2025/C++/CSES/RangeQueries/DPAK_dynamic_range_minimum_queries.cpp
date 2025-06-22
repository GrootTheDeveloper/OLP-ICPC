#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, q; 
vector<int> a;
vector<int> node;

void build(int idx, int l, int r) {
    if (l == r) {
        node[idx] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    node[idx] = min(node[idx * 2], node[idx * 2 + 1]);
}

void update(int idx, int l, int r, int pos, int value) {
    if (l == r) {
        if (l == pos)
            node[idx] = value;
        return;
    }
    int mid = l + r >> 1;
    if (mid >= pos) {
        update(2 * idx, l, mid, pos, value);
    }
    else {
        update(2 * idx + 1, mid + 1, r, pos, value);
    }
    node[idx] = min(node[idx * 2], node[idx * 2 + 1]);
}

int get(int idx, int l, int r, int u, int v) {
    if (r < u || l > v) {
        return 1000000007;
    }
    if (l >= u && r <= v) {
        return node[idx];
    }
    int mid = l + r >> 1;
    int left = get(2 * idx, l, mid, u, v);
    int right = get(2 * idx + 1, mid + 1, r, u, v);
    return min(left, right);
}
signed main(){
    cin >> n >> q;
    a.resize(n + 1);
    node.resize(4 * (n + 1), 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        
    }
    build(1,1,n);
    while(q--) {
        int type ; cin >> type;
        if (type == 1) {
            int pos, val;
            cin >> pos >> val;
            update(1,1,n,pos,val);
        }
        else {
            int l, r; cin >> l >> r;
            cout << get(1,1,n,l,r) << endl;
        }
    }
}