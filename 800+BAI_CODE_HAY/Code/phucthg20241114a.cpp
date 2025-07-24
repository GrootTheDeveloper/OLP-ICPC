#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[100005], pre[100005];
int S(int l, int r)
{
    return pre[r] - pre[l - 1];
}
int Find(int u, int v)
{
   int ans = u, res = abs(S(u, u) - S(u + 1, v));
   int l = u, r = v;
   while (l <= r)
   {
       int mid = (l + r) >> 1;
       if (abs(S(u, mid) - S(mid + 1, v)) < res)
       {
           res = abs(S(u, mid) - S(mid + 1, v));
           ans = mid;
       }
       if (S(u, mid) > S(mid + 1, v)) r = mid - 1;
       else l = mid + 1;
       //cout << mid << ' ';
   }
   return ans;
}
void trau(int n)
{
    int x, y, z, ans = 1e15;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++)
            {
                int mx = max({pre[i], pre[j] - pre[i], pre[k] - pre[j], pre[n] - pre[k]});
                int mi = min({pre[i], pre[j] - pre[i], pre[k] - pre[j], pre[n] - pre[k]});
                if (mx - mi < ans)
                {
                    x = i, y = j, z = k;
                    ans = mx - mi;
                }
            }
    cout << ans << '\n' << x << ' ' << y << ' ' << z;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    int x, y, z, ans = 1e15;
    for (int l = 2; l <= n - 1; l++)
    {
        int lef = Find(1, l);
        int rig = Find(l + 1, n);
        int mx = max({S(1, lef), S(lef + 1, l), S(l + 1, rig), S(rig + 1, n)});
        int mi = min({S(1, lef), S(lef + 1, l), S(l + 1, rig), S(rig + 1, n)});
        if (mx - mi < ans)
        {
            ans = mx - mi;
            x = lef, y = l, z = rig;
        }
    }
    cout << ans << '\n' << x << ' ' << y << ' ' << z;
    //trau(n);
}
