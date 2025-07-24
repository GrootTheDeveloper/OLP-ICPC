#include <bits/stdc++.h>
using namespace std;
int n;
int a[300005], last[300005];
bool mark[300005];
void input(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
void solve(){
	a[0] = -1;
	last[1] = 0;
	for (int i = 1; i <= n; i++){
		int id = i, step = 1;
		while (a[last[id]] == a[i] && step < 3){
			id = last[id];
			++step;
		}
		id = i;
		if (step == 3){
			for (int _ = 1; _ <= 3; _++){
				mark[id] = true;
				id = last[id];
			}
		}
		last[i + 1] = id;
	}
	for (int i = 1; i <= n; i++)
		if (!mark[i])
			cout << a[i] << ' ';
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("TINHIEU.INP","r",stdin);
	freopen("TINHIEU.OUT","w",stdout);
	input();
	solve();
}