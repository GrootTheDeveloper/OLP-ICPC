#include <bits/stdc++.h>
#define int long long

const int oo = 1e9 + 7;
using namespace std;

int mul(int a, int b, int c) {
    int num = 1;
    for (int i = 0; i < a; i++) {
        if (num > 1e18 / 2) return -1;
        num *= 2;
    }
    for (int i = 0; i < b; i++) {
        if (num > 1e18 / 3) return -1;
        num *= 3;
    }
    for (int i = 0; i < c; i++) {
        if (num > 1e18 / 5) return -1;
        num *= 5;
    }
    return num;
}

signed main() {
    vector<int> a;
    for (int i = 0; i < 63; i++) {
        for (int j = 0; j < 60; j++) {
            for (int k = 0; k < 60; k++) {
                int num = mul(i,j,k);
                if (num != -1) {
                    a.push_back(num);
                }
            }
        }
    }
    sort(a.begin(), a.end());
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        int num = -1;
        int l = 0, r = a.size() - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (a[mid] == x) {
                num = mid;
                break;
            } 
            else if (a[mid] > x) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if (num == -1) cout << num;
        else cout << num + 1;
        cout << endl;
    }
}