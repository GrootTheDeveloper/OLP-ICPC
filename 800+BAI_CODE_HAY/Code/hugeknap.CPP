#include <bits/stdc++.h>
using namespace std;

int dp[1001], trace[1001], face[1001], w[10001], v[10001];
int n, M;
void input(){
	cin >> n >> M;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
		cin >> v[i];
}
void solve(){
	memset(dp, -1, sizeof(dp));
	memset(trace, 0, sizeof(trace));
	memset(face, 0, sizeof(face));
	dp[0] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = M; j >= w[i]; j--){
			if (dp[j - w[i]] == -1) continue;
			if (dp[j - w[i]] + v[i] > dp[j]){
				dp[j] = dp[j - w[i]] + v[i];
				trace[j] = j - w[i];
				face[j] = i;
			}
		}
	}
	int pos = 0;
	vector<int> vec;
	for (int i = 1; i <= M; i++)
		if (dp[i] > dp[pos])
			pos = i;
	cout << dp[pos] << ' ';
	while (pos != 0){
		vec.push_back(face[pos]);
		pos = trace[pos];
	}
	cout << vec.size() << '\n';
	reverse(vec.begin(), vec.end());
	for (int &x : vec)
		cout << x << ' ';
	cout << '\n';
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
	int T; cin >> T;
	while (T--){
		input();
		solve();
	}
}