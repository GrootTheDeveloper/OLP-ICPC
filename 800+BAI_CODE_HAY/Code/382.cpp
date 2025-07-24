#include <bits/stdc++.h>
using namespace std;
#define int long long 
struct node{
	int val, id;
	node (int x, int y){
		val = x; id = y;
	}
	bool operator<(const node &other) const{
		return (val == other.val? id > other.id : val < other.val);
	}
};

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int n = s.size();
	s = " " + s;
	int k; cin >> k;
	k = n - k;
	int pos = 0;
	priority_queue <node> q;
	for (int i = 1; i <= n; i++){
		q.push(node(s[i] - '0', i));
		if (n - i < k){
			while (q.top().id <= pos) q.pop();
			cout << q.top().val;
			pos = q.top().id;
		}
	}	
}