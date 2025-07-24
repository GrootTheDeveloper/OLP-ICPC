#include <bits/stdc++.h>
using namespace std;

vector<int> b[27];
int n, m, q, a[100005];
bool mark[30], del[100005];
void input(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		string s; cin >> s;
		for (char c : s){
			b[c - 'a'].push_back(i);
		}
	}
}
void solve(){
	int cur = 0;
	while (q--){
		char x; cin >> x;
		if (!mark[x - 'a']){
			mark[x - 'a'] = true;
			for (int &id : b[x - 'a']){
				cur += (del[id] == false);
				del[id] = true;
			}
		}
		cout << n - cur << '\n';
	}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}