#include <bits/stdc++.h>
using namespace std;
char a[200005];
int color[30], last[30], Begin[30], End[30], n;
void input(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
void solve(){
	for (int i = 0; i <= 26; i++)
		Begin[i] = n + 1;
	for (int i = 1; i <= n; i++){
		int id = a[i] - 'a';
		Begin[id] = min(Begin[id], i);
		End[id] = max(End[id], i);
	}
	int ans = 0;
	for (int i = 0; i <= 26; i++){
		if (Begin[i] != n + 1){
			for (int id = 1; id <= 26; id++){
				if (last[id] < Begin[i]){
					last[id] = End[i];
					ans = max(ans, id);
					color[i] = id;
					break;
				}
			}
		}
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++)
		cout << color[a[i] - 'a'] << ' ';
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}