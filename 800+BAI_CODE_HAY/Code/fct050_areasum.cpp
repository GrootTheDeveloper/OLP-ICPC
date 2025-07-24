#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int s1 = 0, s2 = 0, curx = 0, cury = 0;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        s1 = (s1 + x * (i - 1) - curx) % mode;
        curx += x;
    }
    for (int i = 1; i <= m; i++)
    {
        int y; cin >> y;
        s2 = (s2 + y * (i - 1) - cury) % mode;
        cury += y;
    }
    cout << (s1 % mode) * (s2 % mode) % mode;


}
