#include <bits/stdc++.h>
using namespace std;
int n, k;
bool us[10000007];
void input(){
	cin >> n >> k;
}
void solve(){
	for (int i = 2; i <= n; i++){
		if (!us[i]){
			for (int j = i; j <= n; j += i){
				k -= (!us[j]);
				us[j] = true;
				if (k == 0)
					return cout << j, void();
			}
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}