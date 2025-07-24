#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, mid, k;
bool ans, mark[50];
int a[50];
unordered_map <int, bool> f;
void check(int lim)
{
    int bg = (lim == mid)? 1 : mid + 1;
    int sum = 0;
    for (int i = bg; i <= lim; i++) sum += mark[i] * a[i];
    if (lim == mid) f.insert({sum, true});
    else if (f.find(k - sum) != f.end()) ans = true;
}

void Try(int i, int lim)
{
    if (ans) return;
    if (i == lim + 1) return check(lim), void();
    mark[i] = 1;
    if (!ans) Try(i + 1, lim);
    mark[i] = 0;
    if (!ans) Try(i + 1, lim);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    f.insert({0, true});
    mid = n/2;
    Try(1, mid);
    Try(mid + 1, n);
    cout << (ans ? "YES" : "NO");

}
