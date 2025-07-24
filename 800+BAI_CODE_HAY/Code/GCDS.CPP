#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5e5 + 5;
const int mode = 1e9 + 7;
int sum[N], fsum[N], a[N], id[N], value[N];
vector<int> List[N];
bool mark[N];
int n, q, ans;
void load_file(){
	freopen("GCDS.INP","r",stdin);
	freopen("GCDS.OUT","w",stdout);
}
void input(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i], mark[a[i]] = true;
	for (int i = 1; i <= q; i++){
		cin >> id[i] >> value[i];
		mark[value[i]] = true;
	}
}
void inc(int &a, int val){
	a += val;
	if (a >= mode)
		a -= mode;
}
void dec(int &a, int val){
	a = (a - val) + mode;
	if (a >= mode) a -= mode;
}
void add(int &x){
	for (int &item : List[x]){
		ans = (ans - fsum[item] + mode) % mode;
		fsum[item] = (fsum[item] + 1ll * sum[item]  * (x / item) % mode) % mode; 
		sum[item] = (sum[item] + x / item) % mode;	
		ans = (ans + fsum[item]) % mode;
	}
}
void init(){
	for (int i = 1; i <= 5e5; i++){
		for (int j = i; j <= 5e5; j += i)
		if (mark[j]) List[j].push_back(i);
	}
}
void solve(){
	init();
	for (int i = 1; i <= n; i++)
		add(a[i]);
	cout << ans << '\n';
	for (int i = 1; i <= q; i++){
		int &x = a[id[i]];
		for (int &item : List[x]){
			ans = (ans - fsum[item] + mode) % mode;
			fsum[item] = (fsum[item] - 1ll * (sum[item] - x / item) * (x / item) % mode + mode) % mode;
			sum[item] = (sum[item] - x / item + mode) % mode; 
			ans = (ans + fsum[item]) % mode;
		}
		x = value[i];
		for (int &item : List[value[i]]){
			ans = (ans - fsum[item] + mode) % mode;
			fsum[item] = (fsum[item] + 1ll * sum[item]  * (x / item) % mode) % mode; 
			sum[item] = (sum[item] + x / item) % mode;	
			ans = (ans + fsum[item]) % mode;
		}
		a[id[i]] = value[i];
		cout << ans << '\n';
	}

}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	load_file();
	input();
	solve();
}