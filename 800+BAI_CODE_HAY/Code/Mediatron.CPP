#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 31 + 01 + 20007;
int n, x;
int a[200005];
namespace sub1{
	bool check(){
		for (int i = 2; i <= n; i++)
			if (a[i] < a[i - 1])
				return false;
		return true;
	}
	void work(){
		int ans = 0;
		for (int i = n; i >= 1; i--){
			int mid = i + (n - i) / 2;
			if (a[mid] >= x) ans = n - i + 1;
		}
		cout << ans;
	}
}
namespace sub2{
	vector<int> b;
	int LIM, bit[N], cnt;
	bool check(){
		return n <= 2000;
	}
	void add(int idx){
		for (; idx <= LIM; idx += idx & -idx)
			bit[idx]++;
	}
	int get(int idx){
		int ans = 0;
		for (; idx; idx -= idx & -idx)
			ans += bit[idx];
		return ans;
	}
	int get_median(){
		int l = 1, r = LIM, ans = 0;
		int k = cnt / 2 + (cnt & 1);
		while (l <= r){
			int mid = (l + r) >> 1;
			if (get(mid) <= k)
				ans = mid, l = mid + 1;
			else
				r = mid - 1;
		}
		return ans;
	}
	void work(){
		b.push_back(x);
		for (int i = 1; i <= n; i++)
			b.push_back(a[i]);
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
		for (int i = 1; i <= n; i++)
			a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
		LIM = b.size();
		int ans = 0;
		for (int i = 1; i <= n; i++){
			fill(bit + 1, bit + LIM + 1, 0);
			cnt = 0;
			for (int j = i; j <= n; j++){
				add(a[j]);
				++cnt;
				if (get_median() >= x)
					ans = max(ans, j - i + 1);
			}
		}
		cout << ans;
	}
}
namespace sub3{
	int pre[N];
	struct node{
		int val, id;
		node() : val(0), id(0){};
		node(int a, int b) : val(a), id(b){};
		bool operator < (const node &other) const{
			return (val == other.val? id > other.id : val < other.val);
		}
	}op[N];

	void work(){
		for (int i = 1; i <= n; i++){
			pre[i] = pre[i - 1] + (a[i] >= x? 1 : -1);
			op[i] = node(pre[i], i);
		}
		op[0] = node(0, 0);
		sort(op, op + n + 1);
		int id = 0, low = n + 1, ans = 0;
		for (int i = 0; i <= n; i++){
			while (op[id].val != op[i].val)
				low = min(low, op[id++].id);
			ans = max(ans, op[i].id - low);
		}
		cout << ans;
	}
}

void input(){
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}

void solve(){
	if (sub1::check())
		sub1::work();
	// else if (sub2::check())
	// 	sub2::work();
	else 
		sub3::work();
}
	
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}