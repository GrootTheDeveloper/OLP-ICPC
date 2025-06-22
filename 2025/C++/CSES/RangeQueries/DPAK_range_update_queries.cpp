#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, q; 
vector<int> a;
vector<int> node;
vector<int> lazy;

void push(int idx, int l, int r) {
    if (lazy[idx] != 0) {
        node[idx] += lazy[idx] * (r - l + 1);
        if (l != r) {
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }
    }
    lazy[idx] = 0;
}

void build(int idx, int l, int r) {
    if (l == r) {
        node[idx] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);
    node[idx] = node[idx * 2] + node[idx * 2 + 1];
}

int get(int idx, int l, int r, int pos) {
    push(idx, l , r);
    if (l == r) {
        return node[idx];
    }
    int mid = l + r >> 1;
    if (pos <= mid) {
        return get(2 * idx, l, mid, pos);
    }
    else {
        return get(2 * idx + 1, mid + 1, r, pos);
    }
}

void update(int idx, int l, int r, int u, int v, int val){
    push(idx, l, r);
    if (u > r || v < l) {
        return;
    }
    if (l >= u && r <= v) {
        lazy[idx] += val;
        push(idx, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(idx * 2,l,mid,u,v,val);
    update(idx*2+1,mid +1, r,u,v,val);
    node[idx] = node[idx* 2] + node[idx * 2 + 1];
}



signed main(){
    cin >> n >> q;
    a.resize(n + 1);
    node.resize(4 * (n + 1), 0);
    lazy.resize(4 * (n + 1), 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        
    }
    build(1,1,n);
    while(q--) {
        int type; cin >> type;
        if (type == 1) {
            int l, r, u;
            cin >> l >> r >> u;
            update(1,1,n,l,r,u);
        }
        else {
            int index; cin >> index;
            cout << get(1,1,n,index) << endl;
        }
    }
}