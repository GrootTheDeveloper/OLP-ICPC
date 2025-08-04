#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, q;

struct V {
    int val;
    int max;
};

vector<V> node[2005];

void updateRow(int id, int idx, int l, int r, int val) {
    if (l == r) {
        node[id][idx].val += val;
        node[id][idx].max = node[id][idx].val;
        return;
    }
    int mid = l + r >> 1;
    updateRow(id, idx * 2, l, mid, val);
    updateRow(id, idx * 2 + 1, mid + 1, r, val);
    node[id][idx].val = node[id][2 * idx].val + node[id][2 * idx + 1].val;
    node[id][idx].max = max(node[id][2 * idx].max, node[id][2 * idx + 1].max);
}

void updateCol(int id, int idx, int l, int r, int index, int val) {

    if (l == r) {
        node[id][idx].val += val;
        node[id][idx].max = node[id][idx].val;
        return;
    }
    int mid = l + r >> 1;
    if (index <= mid) {
        updateCol(id, idx * 2, l, mid, index, val);
    }
    else {
        updateCol(id, idx * 2 + 1, mid + 1, r, index, val);
    }
    node[id][idx].val = node[id][idx * 2].val + node[id][idx * 2 + 1].val;
    node[id][idx].max = max(node[id][idx * 2].max, node[id][idx * 2 + 1].max);
}

int get(int id, int idx, int l, int r, int u, int v) {
    if (l > v || r < u) return -1;
    if (l >= u && r <= v) return node[id][idx].max;
    int mid = l + r >> 1;
    return max(get(id, idx * 2, l, mid, u, v), get(id, idx * 2 + 1, mid + 1, r,u, v)); 
}

signed main() {

    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        node[i].resize(4*m + 5);
    }
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int row, val;
            cin >> row >> val;
            updateRow(row, 1, 1, m, val);
        }
        else if (type == 2) {
            int col, val;
            cin >> col >> val;
            for (int i = 1; i <= n; i++) {
                updateCol(i, 1, 1, m, col, val);
            }
        }
        else {
            int ans = 0;
            int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
            for (int x = x1; x <= x2; x++) {
                ans = max(ans, get(x, 1, 1, m, y1, y2));
            }
            cout << ans << endl;
        }
    }
    return 0;
}