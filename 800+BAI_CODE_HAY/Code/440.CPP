#include <bits/stdc++.h>
using namespace std;
int n, k;
double a[100005], b[100005], List[100005];
void input(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
}
bool check(double x){
	for (int i = 1; i <= n; i++)
		List[i] = a[i] - x * b[i];
	sort(List + 1, List + n + 1, greater<double>());
	double sum = 0;
	for (int i = 1; i <= k; i++)
		sum += List[i];
	return sum >= 0;
}
void solve(){
	double l = 0, r = 1e15;
	while (r - l >= 0.0001){
		double mid = (l + r) / 2.0;
		if (check(mid)) l = mid;
		else r = mid;
	}	
	cout << fixed << setprecision(4) << l;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}