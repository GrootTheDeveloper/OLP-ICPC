#include <bits/stdc++.h>
using namespace std;
#define int long long
int d, n;

int pin1(int x)
{
   int k = x / d;
   return x - k * d;
}
int pin2(int x)
{
    int k = x / d;
    int y = x - k * d;
    if (y < 0) y += d;
    return y;
}

int pin(int n)
{
    if (n >= 0) return pin1(n);
    else return pin2(n);
}

int dx[1111], dy[1111], e[1111][1111];
int x[100005], y[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("social-distancing.inp","r",stdin);
    freopen("social-distancing.out","w",stdout);
    cin >> d >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for (int i = 1; i <= n; i++)
    {
        int h = pin(x[i]), k = pin(y[i]);
        dx[h]++, dy[k]++;
        e[h][k]++;
    }
    int ans = 1e9 + 7;
    for (int i = 0; i < d; i++)
    for (int j = 0; j < d; j++)
        ans = min(ans, dx[i] + dy[j] - e[i][j]);
    cout << ans;

}
