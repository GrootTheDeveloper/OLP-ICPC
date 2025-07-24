#include <bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7, base = 311, N = 1e5 + 5;
int heso[8] = {0, 3, -2, -2, -2, 1, 1, 1};
unordered_map<long long, int> cnt[8];
int n;
int a[N], b[N], c[N];
void input(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i] >> c[i];
}
long long tranf(string s){
	long long Hash = 0;
	for (char c : s){
		Hash = (1ll * Hash * base + c); 
	}
	return Hash;
}
void solve(){
	stack<long long> st;
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		string A = to_string(a[i]), B = to_string(b[i]), C = to_string(c[i]);
		st.push(tranf(A));
		st.push(tranf(B));
		st.push(tranf(C));
		st.push(tranf(A + " " + B));
		st.push(tranf(A + " " + C));
		st.push(tranf(B + " " + C));
		st.push(tranf(A + " " + B + " " + C));																			
		int id = 0;
		while (st.size()){
			id++;
			long long top = st.top(); st.pop();
			ans += 1ll * (cnt[id][top]++) * heso[id];
		}
	}
	cout << ans;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}