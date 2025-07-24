#include <bits/stdc++.h>
using namespace std;
int n, k, dif_num, a[400005], cnt[400005];
void add(int &val){ dif_num += (++cnt[val] == 1);}
void del(int &val){ dif_num -= (--cnt[val] == 0);}
void input(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
}
void solve(){
	vector<int> b;
	for (int i = 1; i <= n; i++)
		b.push_back(a[i]);
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
	int id = 1;
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		add(a[i]);
		while (dif_num >= k){
			ans += n - i + 1;
			del(a[id++]);
		}
	}
	cout << ans;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}