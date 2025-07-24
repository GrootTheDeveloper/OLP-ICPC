#include <bits/stdc++.h>
using namespace std;
#define ii pair<long long, long long>
#define fi first
#define se second 

ii a[5][1111], b[1000006];
long long dp[1000006], last[1000006];
int n, m;
void solve(){
	cin >> n >> m;
	for (int k = 1; k <= 4; k++)
	for (int i = 1; i <= n; i++){
		cin >> a[k][i].fi >> a[k][i].se;
	}
	
	int lim = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			b[++lim] = {a[1][i].fi + a[2][j].fi, a[1][i].se + a[2][j].se};
	sort(b + 1, b + lim + 1);
	for (int i = 1; i <= lim; i++)
		dp[i] = max(dp[i - 1], b[i].se), last[i] = b[i].fi;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++){
		if (a[3][i].fi + a[4][j].fi > m) 
			continue;
		int pos = upper_bound(last + 1, last + lim + 1, m - (a[3][i].fi + a[4][j].fi)) - last - 1;
		ans = max(ans, a[3][i].se + a[4][j].se + dp[pos]);
	}
	cout << ans;

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("CAUHINH.INP","r",stdin);
	freopen("CAUHINH.OUT","w",stdout);
	solve();
}