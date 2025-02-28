#include<bits/stdc++.h>
using namespace std;
int main() {

	int n; cin >> n;
	vector<long long> b(n + 1), a(n + 1);
	long long val = 0;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	a[1] = b[1];
	val = a[1];
	for (int i = 2; i <= n; i++) {
		long long temp = b[i] * i;
		a[i] = temp - val;
		val += a[i];
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
}
