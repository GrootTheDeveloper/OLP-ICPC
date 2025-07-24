#include <bits/stdc++.h>
using namespace std;
#define int long long
int lim, a[500005];
vector<int> d[1000006];
bool prime[1000006];
void init()
{
    for (int i = 2; i <= lim; i++)
        if (!prime[i])
         {
             d[i].push_back(i);
             for (int j = i * 2; j <= lim; j += i) d[j].push_back(i), prime[j] = true;
         }
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q; cin >> q;
    for (int i = 1; i <= q; i++) cin >> a[i], lim = max(lim, a[i]);
    init();
    for (int i = 1; i <= q; i++)
    {
        for (int &x : d[a[i]]) cout << x << ' ';
        cout << '\n';
    }
}
