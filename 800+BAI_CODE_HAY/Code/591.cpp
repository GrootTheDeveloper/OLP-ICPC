#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int,int>
#define val first
#define idx second
ii a[1000006];
int cnt[1001], dif;
void add(int val) {dif += (++cnt[val] == 1);}
void del(int val) {dif -= (--cnt[val] == 0);}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m; cin >> n >> m;
    int lim = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int ai; cin >> ai;
            a[++lim].val = ai;
            a[lim].idx = i;
        }
    sort(a + 1, a + lim + 1);
    int l = 1, res = 1e12;
    for (int i = 1; i <= lim; i++)
    {
        add(a[i].idx);
        while (dif == n)
        {
            res = min(res, a[i].val - a[l].val);
            del(a[l++].idx);
        }
    }
    cout << res;

}
