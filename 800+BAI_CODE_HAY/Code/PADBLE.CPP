#include <bits/stdc++.h>
using namespace std;

string s;
namespace sub1{
	bool Check[1111][1111], palindrom[1111][1111];
	bool check(){
		return (s.size() <= 1000);
	}
	void work(){
		int n = s.size();
		s = " " + s;
		for (int i = 1; i <= n; i++){
			int cnta = 0, cntb = 0;
			for (int j = i; j <= n; j++){
				cnta += (s[j] == 'a');
				cntb += (s[j] == 'b');
				Check[i][j] = (cnta != 0 && cntb != 0);
			}
		}
		for (int i = 1; i <= n; i++){
			palindrom[i][i] = true;
			if (i < n)
				palindrom[i][i + 1] = (s[i] == s[i + 1]);
		}
		for (int len = 3; len <= n; len++){
			for (int i = 1; i + len - 1 <= n; i++){
				int j = i + len - 1;
				palindrom[i][j] = (s[i] == s[j] && palindrom[i + 1][j - 1]);
			}
		}
		int ans = -1, cnt = 0;
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				if ((j - i + 1) & 1 || !Check[i][j] || (j - i + 1) < ans) continue;
				int mid =  (i + j) >> 1;
				if (palindrom[i][mid] && palindrom[mid + 1][j]){
					if (j - i + 1 > ans)
						ans = j - i + 1, cnt = 1;
					else
						cnt++;
				}
			}
		}
		cout << ans << ' ';
		if (ans != -1)
			cout << cnt;

	}
}
void input(){
	cin >> s;
}
void solve(){
	if (sub1::check())
		sub1::work();
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("PADBLE.INP","r",stdin);
	freopen("PADBLE.OUT","w",stdout);
	input();
	solve();
}