#include <bits/stdc++.h>
using namespace std;


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		if (n > m || m % n != 0 || (n == 1 && m != 1)){
			cout << -1 << '\n';
			continue;
		}
		int cnt = 0, x = m / n;
		vector<int> b;
		bool Is = true;
		while (x != 1){
			++cnt;
			int tmp = __gcd(n, x);
			if (tmp == 1){
				cout << -1 << '\n';
				Is = false;
				break;
			}
			n *= tmp;
			b.push_back(x);
			x /= tmp;
		}
		if (!Is) continue;
		cout << cnt << ' ';
		for (int &c : b)
			cout << c << ' ';
		cout << '\n';
	}
}