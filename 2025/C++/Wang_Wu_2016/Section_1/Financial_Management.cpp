#include <bits/stdc++.h>
using namespace std;
int main() {

	double ans = 0.0;
	for (int i = 1; i <= 12; i++) {
		double x; cin >> x;
		ans += x / 12.0; 
	}

	cout << "$" << fixed << setprecision(2) << ans;
	return 0;
}