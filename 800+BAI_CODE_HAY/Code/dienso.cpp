#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000006];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    s = ">" + s + "<";
    int mi = 0;
    a[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '<') a[i + 1] = a[i] + 1;
        else a[i + 1] = a[i] - 1;
        mi = min(mi, a[i + 1]);
    }
    int res = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        a[i] += abs(mi);
        res += a[i];
    }
    if (s[1] == '<') res -= a[1];
    if (s[n] == '>') res -= a[n + 1];
    cout << res;
}
