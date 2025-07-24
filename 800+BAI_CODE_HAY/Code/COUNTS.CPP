#include <bits/stdc++.h>
using namespace std;
const int base = 256, N = 1e5 + 5;
long long HashA[N], HashB[N], Pow[N];
int n, m, k;
string A, B;
void input(){
	cin >> k;
	cin >> A;
	cin >> B;
	n = A.size();
	m = B.size();
	A = "!" + A;
	B = "?" + B;
}
bool compare(int l, int r, int a, int b){
	return HashA[r] - HashA[l - 1] * Pow[r - l + 1] == HashB[b] - HashB[a - 1] * Pow[b - a + 1];
}
void init(){
	for (int i = 1; i <= n; i++)
		HashA[i] = 1ll * HashA[i - 1] * base + A[i];
	for (int i = 1; i <= m; i++)
		HashB[i] = 1ll * HashB[i - 1] * base + B[i];
	Pow[0] = 1;
	for (int i = 1; i <= m; i++)
		Pow[i] = Pow[i - 1] * base;
}
bool check_sub_string(int L, int R){
	int pos = L;
	for (int i = 1; i <= k + 1; i++){
		int nxt = R + 1, l = pos, r = R;
		while (l <= r){
			int mid = (l + r) >> 1;
			if (!compare(pos - L + 1, mid - L + 1, pos, mid))
				nxt = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		if (nxt == R + 1)
			return true;
		else
			pos = nxt + 1;
	}
	return false;
}
void solve(){
	init();
	int ans = 0;
	for (int i = 1; i <= m - n + 1; i++)
		ans += (check_sub_string(i, i + n - 1));
	cout << ans;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}