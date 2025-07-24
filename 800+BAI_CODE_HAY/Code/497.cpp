#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> d[1000006], p[1000006];
int res[100005];
bool prime[1000006];
void calc(int x, int y)
{
    if (abs(res[y] - y) >= y - x) res[y] = x;
    if (abs(res[x] - x) > y - x)  res[x] = y;
}
void sie(int lim)
{
    vector <int> vec;
    for (int i = 2; i <= lim; i++)
        if (!prime[i])
         {
             vec.push_back(i);
             for (int j = i * i; j <= lim; j += i) prime[j] = true;
         }
    for (auto x : vec)
    {
        for (int i = x; i <= lim; i += x)
            for (int j : d[i]) p[x].push_back(j);
        sort(p[x].begin(), p[x].end());
    }
    for (int x : vec)
        for (int i = 1; i < p[x].size(); i++) calc(p[x][i - 1], p[x][i]);
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int lim = 0;
    for (int i = 1; i <= n; i++)
    {
        int ai; cin >> ai;
        lim = max(lim,ai);
        d[ai].push_back(i);
        res[i] = 1e9;
    }
    sie(lim);
    for (int i = 1; i <= n; i++) cout << ((res[i] != 1e9)? res[i] : -1) << ' ';

}
