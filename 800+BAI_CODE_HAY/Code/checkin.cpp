#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m, a[100005];

bool check(int x)
{
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        cur += x / a[i];
        if (cur >= m) return true;
    }
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = 1e15;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    while (check(l - 1)) l--;
    while (!check(l)) l++;
    cout << l;
}
