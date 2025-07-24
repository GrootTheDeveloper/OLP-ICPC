#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define iii pair<int, ii>
#define fi first
#define se second
iii a[100005];
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].fi >> a[i].se.fi >> a[i].se.se;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		cout << a[i].fi << ' ' << a[i].se.fi << ' ' << a[i].se.se << '\n';
}