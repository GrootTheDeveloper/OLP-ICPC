#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 31 + 01 + 2007;
int a[N], bit[N];
vector<int> zip;
int LIM, n;
long long cur_couple, k;

void input(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
void zip_handle(){
	for (int i = 1; i <= n; i++)
		zip.push_back(a[i]);
	sort(begin(zip), end(zip));
	zip.erase(unique(begin(zip), end(zip)), zip.end());
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(zip.begin(), end(zip), a[i]) - zip.begin() + 1;
	LIM = zip.size() + 5;
}
void update(int idx, int val){
	for (; idx <= LIM; idx += idx & - idx)
		bit[idx] += val;
}
int get(int l, int r){
	int ans = 0;
	for (; r; r -= r & -r)
		ans += bit[r];
	--l;
	for (; l; l -= l & -l)
		ans -= bit[l];
	return ans;
}
void add(int val){
	update(val, 1);
	cur_couple += 1ll * get(val + 1, LIM);
}
void del(int val){
	update(val, -1);
	cur_couple -= 1ll * get(1, val - 1);
}
void handle_return_ans(){
	int id = 1;
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		add(a[i]);
		while (cur_couple >= k && id <= n){
			ans += 1ll * (n - i + 1);
			del(a[id++]);
		}
	}
	cout << (k == 0? 1ll * n * (n + 1) >> 1ll : ans);
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	zip_handle();
	handle_return_ans();
}