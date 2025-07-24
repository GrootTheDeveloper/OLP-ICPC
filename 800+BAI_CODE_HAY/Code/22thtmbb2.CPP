#include <bits/stdc++.h>
using namespace std;
const long long base = 311;
const int mode = 1e9 + 7;
int n;
int a[10], f[100000][10];
unordered_map<long long, int> dp;
void input(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++){
		int x = a[i];
		while(x){
			if (x & 1){
				f[(x - 1) / 2][i] = 2;
				x = (x - 1) / 2;
			}
			else{
				f[x / 2][i] = 1;
				x = x / 2;
			}
		}
	}
}
long long Hash(vector<int> &b){
	long long ans = 0;
	for (int &c : b){
		ans = ans * base + 1ll * (c + 1);
	}
	return ans;
}
void add(int &a, int b){
	a += b;
	if (a >= mode)
		a -= mode;
}
int calc(vector<int> b){
	long long mask = Hash(b);
	if (dp.find(mask) != dp.end())
		return dp[mask];
	int ans = 0;
	for (int i = 0; i < n; i++){
		int type = f[b[i]][i + 1];
		if (type == 0) continue;
		if (type == 1){
			vector<int> List = (b);
			List[i] *= 2;
			add(ans, calc(List));
		} else
		{
			int id = (i == n - 1? 0 : i + 1);
			if (f[b[id]][id + 1] == 2){
				vector<int> List = (b);
				List[i] = List[i] * 2 + 1;
				List[id] = List[id] * 2 + 1;
				add(ans, calc(List));
			}
		}
	}
	return dp[mask] = ans;
}
void solve(){
	vector<int> b;
	for (int i = 1; i <= n; i++)
		b.push_back(a[i]);
	long long MASK = Hash(b);
	dp[MASK] = 1;
	vector<int> List(n, 0);
	cout << calc(List);
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}