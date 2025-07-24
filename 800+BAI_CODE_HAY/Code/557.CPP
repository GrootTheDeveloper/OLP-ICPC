#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
ii a[100005];
bool cmp(ii x, ii y){
	return x.se < y.se;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1, cmp);
	int last = 0, ans = 0;
	for (int i = 1; i <= n; i++){
		if (a[i].fi > last){
			ans++;
			last = a[i].se;
		}
	}
	cout << ans;
}	