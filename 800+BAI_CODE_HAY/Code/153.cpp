#include <bits/stdc++.h>
using namespace std;
#define int long long

bool ans[2222][2222];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    s = "#" + s;
    int n = s.size() - 1;
    for (int i = 1; i <= n; i++) ans[i][i] = true;
    for (int len = 2; len <= n; len ++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            if (len == 2) ans[i][i + 1] = (s[i] == s[i + 1]);
            else ans[i][i + len - 1] = (s[i] == s[i + len - 1] && ans[i + 1][i + len - 2]);
        }
    }
    int q; cin >> q;
    while (q--)
    {
        int x,y; cin >> x >> y;
        cout << (ans[x][y]? "YES" : "NO") << '\n';
    }
}
