#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

ii d[20];

void init()
{
    d[1].fi = 1; d[1].se = 9;
    for (int i = 2; i <= 17; i++)
    {
        d[i].fi = d[i - 1].fi * 10;
        d[i].se = d[i - 1].se * 10 + 9;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init();
    int k; cin >> k;
    int loc = 1;
    while ((d[loc].se - d[loc].fi + 1) * loc < k)
    {
        k -= (d[loc].se - d[loc].fi + 1) * loc;
        loc ++;
    }
    int idx = k/loc + (k % loc != 0);
    idx = d[loc].fi + idx - 1;
    k %= loc;
    if (k == 0) k = loc;
    while (k != loc) idx/=10, loc --;
    cout << idx % 10;
}
