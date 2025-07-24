#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const ll mod = (ll)1e9 + 7;
int cnt[200005];

ll powMod(ll a, ll b, ll m) {
	if(b == 0) {
		return (ll)1;
	}
	ll half = powMod(a, b / 2, m);
	half = (half * half) % m;
	if(b % 2) {
		return (half * (a % m)) % m;
	}
	return half % m;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin >> m;
	vector<int> v;
	while(m--) {
		int x;
		cin >> x;
		if(cnt[x] == 0) {
			v.push_back(x);
		}
		cnt[x]++;
	}
	bool isSquareNum = true;
	ll a1 = 1, a2 = 1, b = 1;
	for(int i = 0; i < (int)v.size(); ++i) {
		a1 = (a1 * powMod(v[i], cnt[v[i]], mod)) % mod;
		if(isSquareNum && cnt[v[i]] % 2){
		isSquareNum = false;
		b = (b * ((cnt[v[i]] + 1) / 2)) % (mod - 1);
	}
	else {
		b = (b * (cnt[v[i]] + 1)) % (mod - 1);
	}
	if(isSquareNum) {
		a2 = (a2 * powMod(v[i], cnt[v[i]] / 2, mod)) % mod;
	}
	}
	ll res;
	if(isSquareNum) {
		res = powMod(a2, b, mod);
	}
	else {
		res = powMod(a1, b, mod);
	}
	cout << res << endl;
	return 0;
}
