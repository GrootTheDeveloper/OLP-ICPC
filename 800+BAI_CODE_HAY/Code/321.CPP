#include <bits/stdc++.h>
using namespace std;

long long x[100005], y[100005], sumx[100005], sumy[100005];
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	sort(x + 1, x + n + 1);
	sort(y + 1, y + n + 1);
	for (int i = 1; i <= n; i++){
		sumx[i] = x[i] + sumx[i - 1];
		sumy[i] = y[i] + sumy[i - 1];
	}
	long long X = 1e18, Y = 1e18;
	for (int i = 1; i <= n; i++){
		X = min(X, (x[i] * i - sumx[i]) + (sumx[n] - sumx[i]) - x[i] * (n - i));
		Y = min(Y, (y[i] * i - sumy[i]) + (sumy[n] - sumy[i]) - y[i] * (n - i));	
	}
	cout << X + Y;
}