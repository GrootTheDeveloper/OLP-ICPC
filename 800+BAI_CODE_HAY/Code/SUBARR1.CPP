#include <bits/stdc++.h>
using namespace std;
int n, k, a[400005], cnt[400005];
int acp;
void add(int &val){ acp += (++cnt[val] == k);}
void del(int &val){ acp -= (--cnt[val] == k - 1);}

void input(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
void solve(){
	vector<int> b;
	for (int i = 1; i <= n; i++)
		b.push_back(a[i]);
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), end(b)), end(b));
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(begin(b), end(b), a[i]) - b.begin() + 1;
	int id = 1;
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		add(a[i]);
		while (acp){
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