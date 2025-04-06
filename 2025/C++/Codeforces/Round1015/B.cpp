#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int m = *min_element(a.begin(), a.end());
		vector<int> new_a;
		for (auto& x : a) {
			if (x % m == 0) {
				new_a.push_back(x);
			}
		}
		if (new_a.size() < 2) {
			cout << "no" << endl;
			continue;
		}
		bool check = false;
		vector<int> X;
		for (auto x : new_a) {
			if (!check && x == m) {
				check = true;
			}
			else {
				X.push_back(x);
			}
		}
		int g = 0;
		for (auto c : X) {
			g = gcd(c, g);
		}
		if (g == m) {
			cout << "yes";
		}
		else cout << "no";
		cout << endl;
	}
}