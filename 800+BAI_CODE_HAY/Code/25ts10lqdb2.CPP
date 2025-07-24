#include <bits/stdc++.h>
using namespace std;

string s;
void input(){
	cin >> s;
}
void solve(){
	deque<char> dq;
	int id = 0;
	for (char c : s){
		++id;
		if (id & 1)
			dq.push_front(c);
		else
			dq.push_back(c);
	}
	if ((int)s.size() % 2 == 0)
		reverse(dq.begin(), dq.end());
	for (char c : dq)
		cout << c;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("MAHOA.INP","r",stdin);
	freopen("MAHOA.OUT","w",stdout);
	input();
	solve();
}