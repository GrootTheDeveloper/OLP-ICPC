#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int oo = 1e18 + 7;

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    vector<vector<int>> a(3, vector<int>(n + 2, 0));
    int blocked = 0;
    while (q--) {
        int y, x; cin >> y >> x;
        int adj = 0;
        if (y == 1) { 
            adj = a[2][x - 1] + a[2][x] + a[2][x + 1]; 
        } else {       
            adj = a[1][x - 1] + a[1][x] + a[1][x + 1];
        }

        if (a[y][x] == 0) {   
            blocked += adj;
        } else { 
            blocked -= adj;
        }
        a[y][x] = !a[y][x];

        if (blocked) cout << "NO";
        else cout << "YES";
        cout << endl;
    }   
    return 0;
}