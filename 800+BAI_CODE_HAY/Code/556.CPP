#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define fi first
#define se second
ii a[1111];
bool mark[1111];
bool cmp(ii x, ii y){
	if (x.se == y.se)
		return x.fi > y.fi;
	else
		return x.se > y.se;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].fi;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i].se, ans += a[i].se;
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++){
		for (int j = a[i].fi; j >= 1; j--)
			if (!mark[j]){
				ans -= a[i].se;
				mark[j] = true;
				break;
			}
	}
	cout << ans;
}