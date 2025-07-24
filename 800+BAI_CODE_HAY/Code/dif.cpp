#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[400005];

void sub1()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int mx = a[i], mi = a[i];
        for (int j = i + 1; j <= n; j++)
        {
            mx = max(mx, a[j]);
            mi = min(mi, a[j]);
            res += (mx - mi);
        }
    }
    cout << res;
}
const int maxn = 4e5 + 5;
int Rmax[maxn], Rmin[maxn], Lmax[maxn], Lmin[maxn];
void fulltask()
{
    vector <int> rmax, rmin;
    for (int i = 1; i <= n; i++)
    {
        while (true)
        {
            if (rmax.size() == 0) {Rmax[i] = 0; rmax.push_back(i); break;}
            if (a[rmax.back()] >= a[i])
            {
                Rmax[i] = rmax.back();
                rmax.push_back(i);
                break;
            } else rmax.pop_back();
        }
        while (true)
        {
            if (rmin.size() == 0) {Rmin[i] = 0; rmin.push_back(i); break;}
            if (a[rmin.back()] <= a[i])
            {
                Rmin[i] = rmin.back();
                rmin.push_back(i);
                break;
            } else rmin.pop_back();
        }
    }
    vector <int> lmax, lmin;
    for (int i = n; i >= 1; i--)
    {
        while (true)
        {
            if (lmax.size() == 0) {Lmax[i] = n + 1; lmax.push_back(i); break;}
            if (a[lmax.back()] > a[i])
            {
                Lmax[i] = lmax.back();
                lmax.push_back(i);
                break;
            } else lmax.pop_back();
        }
        while (true)
        {
            if (lmin.size() == 0) {Lmin[i] = n + 1; lmin.push_back(i); break;}
            if (a[lmin.back()] < a[i])
            {
                Lmin[i] = lmin.back();
                lmin.push_back(i);
                break;
            } else lmin.pop_back();
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += a[i] * (i - Rmax[i]) * (Lmax[i] - i);
        res -= a[i] * (i - Rmin[i]) * (Lmin[i] - i);
    }
    cout << res;

}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n <= 5000) sub1();
    else fulltask();
}
