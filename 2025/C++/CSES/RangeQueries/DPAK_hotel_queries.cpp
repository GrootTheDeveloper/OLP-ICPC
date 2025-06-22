#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, q; 
vector<int> a;
vector<int> node;
vector<int> lazy;

signed main(){
    cin >> n >> q;
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }

    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + (s[i][j] == '*' ? 1 : 0);
        }
    }

    while(q--) {
        int y1,x1,y2,x2;
        cin >>y1 >> x1 >>y2>>x2;
        int ans = f[y2][x2] - f[y1-1][x2] - f[y2][x1-1] + f[y1-1][x1-1];
        cout << ans << endl;
    }
}