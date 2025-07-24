#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[1000006];
bool mark[10];
int lim, val[10000007];
void Try(int i, int s)
{
    if (i > n) return;
    for (int x = 0; x <= 9; x++)
    {
        if (!mark[x])
        {
            mark[x] = true;
            val[++lim] = s * 10 + x;

        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int q = 0, ai, mx = 0;
    while (cin >> ai)
    {
        a[++q] = ai;
        mx = max(mx, ai);
    }
    string s = to_string(mx);
    n = s.size();
    Try(1);


}
