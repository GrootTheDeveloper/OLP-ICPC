#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> p;
bool prime[1000006];
void sie(int lim)
{
    prime[1] = true;
    for (int i = 2; i <= lim; i++)
        if (!prime[i])
        {
            p.push_back(i);
            for (int j = i * i; j <= lim; j += i) prime[j] = true;
        }
}
void solve(int &l, int &r)
{
    int res = 0;
    for (int x : p)
    {
        int val = x;
        for (int i = 2; val <= r; i++)
        {
            val *= x;
            if (val >= l && val <= r && !prime[i + 1]) res++;
        }
    }
    cout << res;
}
int cnt[100005];
void init()
{
    for (int i = 1; i <= 1e5; i++)
        for (int j = i; j <= 1e5; j += i)
            cnt[j]++;
}
void check(int l, int r)
{
    cout << '\n';
    int res = 0;
    for (int i = l; i <= r; i++) res += (!prime[cnt[i]] && prime[i]);
    cout << res;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int l, r; cin >> l >> r;
    sie(sqrt(r));
    solve(l, r);

}
