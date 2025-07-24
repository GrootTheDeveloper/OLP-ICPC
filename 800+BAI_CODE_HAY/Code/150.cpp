#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int f[555][555];

int cut(int a, int b)
{
    if (a > b) swap(a,b);
    if (f[a][b] != inf) return f[a][b];
    if (b % a == 0) return f[a][b] = b/a - 1;
    int ans = inf;
    for (int i = 1; i < b/2 + 1; i++)
        ans = min(ans, cut(a, i) + cut(a, b - i) + 1);
    f[a][b] = ans;
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a,b; cin >> a >> b;
    if (a > b) swap(a,b);
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++) f[i][j] = inf;
    for (int i = 1; i <= b; i++) f[i][i] = 0;
    cout << cut(a, b);
}
