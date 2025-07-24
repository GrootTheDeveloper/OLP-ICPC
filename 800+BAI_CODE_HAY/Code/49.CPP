#include <bits/stdc++.h>
using namespace std;

int cnt[10];
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	for (char c : s)
		cnt[c - '0']++;
	for (int i = 1; i <= 9; i++){
		while (cnt[i]){
			cout << i;
			cnt[i]--;
			while (cnt[0])
				cout << 0, cnt[0]--;
		}
	}
}