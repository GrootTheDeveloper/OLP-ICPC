#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m, a[10005], b[10005], LIMIT;
int val[30];
bool mark[30];
vector <int> s[20005];
int cnt[10005];
void check()
{
    int lim = 0, pos = 0;
    for (int i = 1; i <= m; i++)
    if (mark[i])
    {
        val[++lim] = b[i];
        auto it = upper_bound(s[b[i]].begin(), end(s[b[i]]), pos);
        if (it == s[b[i]].end()) return;
        pos = *it;
    }
    if (lim % 2 == 0) return;
    for (int i = 2; i < lim; i += 2)
        if (val[i - 1] >= val[i] || val[i + 1] >= val[i]) return;

    cnt[lim]++;
    LIMIT = max(LIMIT, lim);
}

void Try(int i)
{
    if (i > m) return check(), void();
    for (int x = 0; x <= 1; x++)
    {
        mark[i] = x;
        Try(i + 1);
    }
}

void sub1()
{
    for (int i = 1; i <= n; i++) s[a[i]].push_back(i);
    Try(1);
    cout << LIMIT << ' ' << cnt[LIMIT];
}




signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for (int j = 1; j <= m; j++) cin >> b[j];
    if (m <= 20) sub1();
}
