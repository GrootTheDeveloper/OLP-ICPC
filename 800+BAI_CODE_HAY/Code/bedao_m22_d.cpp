#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e15;
int a[555][555], d[555][555];
int n,s;
void solve()
{
    int res = inf;
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
            if (d[i][j] > d[i][k] + d[k][i])
                d[i][j] = d[i][k] + d[k][j];
    for (int k = 1; k <= n; k++)
        for (int i = 1; i < k; i++)
            for (int j = 1; j < i; j++)
                res = min(res, d[i][j] + a[i][k] + a[k][j]);
    cout << s - res;


}

void inp()
{
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> a[i][j], d[i][j] = a[i][j];
}


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	inp();
	solve();
}
