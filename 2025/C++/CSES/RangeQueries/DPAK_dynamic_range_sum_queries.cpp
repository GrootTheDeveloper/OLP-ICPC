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
    int mid = (l + r) >> 1;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    node[idx] = node[idx * 2] + node[idx * 2 + 1];
}

int get(int idx, int l, int r, int u, int v) {
    if (l >= u && r <= v) {
        return node[idx];
    }
    if (r < u || l > v) {
        return 0;
    }
    int mid = (l + r) >> 1;
    int left = get(2 * idx, l, mid, u, v);
    int right = get(2 * idx + 1, mid + 1, r, u, v);
    return left + right;
}

void update(int idx, int l, int r,int value, int index) {
    if (l == r) {
        if (l == index) {
            node[idx] = value;
        }
        return;
    }
    int mid = (l + r) >> 1;

    if (mid >= index) {
        update(2 * idx, l, mid,value, index);   
    }
    else {
        update(2 * idx + 1, mid + 1, r,value, index);
    }
    node[idx] = node[idx * 2] + node[idx * 2 + 1];
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
        int type; cin >> type;
        int l, r; cin >> l >> r;
        if (type == 2) {
            cout << get(1,1,n,l,r) << endl;
        }
        else {
            update(1,1,n,r,l);
        }
    }
}