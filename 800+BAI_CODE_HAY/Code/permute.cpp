#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[400005];
bool mark[400005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("permute.inp","r",stdin);
    freopen("permute.out","w",stdout);
    int o; cin >> o;
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != -1) mark[a[i]] = 1;
    }
    vector<int> v;
    for (int i = n; i >= 1; i--)
        if (!mark[i]) v.push_back(i);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != -1) cout << a[i];
        else cout << v.back(), v.pop_back();
        cout << ' ';
    }
}
