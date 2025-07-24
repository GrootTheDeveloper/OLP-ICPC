#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, q;
int a[N];
void input(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
int calc(){
	multiset<int> s;
	for (int i = 1; i <= n; i++){
		s.insert(a[i]);
		auto it = s.find(a[i]);
		it++;
		if (it != s.end())
			s.erase(it);
	}
	return s.size();
}
void sub1(){
	while (q--){
		int pos, tmp; cin >> pos >> tmp;
		swap(tmp, a[pos]);
		cout << calc() << '\n';
		swap(tmp, a[pos]);
	}
}
void solve(){
	if (q == 0)
		cout << calc();
	else if (q <= 20)
		sub1();
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}