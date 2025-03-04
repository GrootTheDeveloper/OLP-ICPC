#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;
	if (n <= 0) {
		n = -n;
		cout << -n * (n + 1) / 2 + 1;
	}
	else {
		cout << n * (n + 1) / 2;
	}
}