#include <bits/stdc++.h>
using namespace std;
struct node{
	long long val, id;
	node(): val(0), id(0){};
	node(long long a, long long b) : val(a), id(b){};
	bool operator < (const node &other) const{
		return (val == other.val? id > other.id : val < other.val);
	}
};
node a[100005];
long long bit[100005];
int n;

void input(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		int r, h; cin >> r >> h;
		a[i] = node(1ll * r * r * h, i);
	}
}
void update(int idx, long long val){
	for (; idx <= n; idx += idx & -idx)
		bit[idx] = max(bit[idx], val);
}
long long get(int idx){
	long long ans = 0;
	for (; idx; idx -= idx & -idx){
		ans = max(ans, bit[idx]);
	}
	return ans;
}
void solve(){
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++){
		update(a[i].id, get(a[i].id - 1) + a[i].val);
	}
	cout << get(n);
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}