#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct query{
    int type;
    int x;
};

void ROTATE(vector<int>& a, int l, int r, int offset) {
    int len = r - l + 1;
    if (len <= 1) return; 
    offset = ((offset % len) + len) % len; 
    if (offset == 0) return;
    reverse(a.begin() + l, a.begin() + l + offset);
    reverse(a.begin() + l + offset, a.begin() + r + 1);
    reverse(a.begin() + l, a.begin() + r + 1);
}


int n, k, q; 
signed main() {
    cin >> n >> k >> q;
    vector<query> Q(q + 1);
    for (int i = 1; i <= q; i++) {
        cin >> Q[i].type >> Q[i].x;
    }
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int z = q; z >= 1; z--) {
        int type = Q[z].type;
        int x = Q[z].x;

        if (type == 2) {
            int offset = ((x % n) + n) % n;
            ROTATE(a, 1, n, offset);
        }
        else {
            for (int i = 1; i <= n; i += k) {
                int len = min(k, n - i + 1);
                int offset = ((x % len) + len) % len;
                ROTATE(a, i, i + len - 1, offset);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
}