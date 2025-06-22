#include <bits/stdc++.h>
 
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
 
int n, x;
int res = 0;
int mid;
 
vector<int>a;
unordered_map<int,int> ma;
 
void backTracking(int i, int total){
	if (total > x) {
		return;
	}
 
	if (i > mid) {
		ma[total]++;		
		return;
	}
 
	backTracking(i + 1, total);
	backTracking(i + 1, total + a[i]);
}
 
void findingNemo(int i, int total) {
	if (total > x) {
		return;
	}
	if (i > n) {
		int left = x - total;
		if (ma.find(left) != ma.end()) {
			res += ma[left];
		}
		return;
	}
 
	findingNemo(i + 1, total);
	findingNemo(i + 1, total + a[i]);
}
 
signed main() {
 
	cin >> n >> x;
	a.resize(n + 1);
	for (int i = 1 ; i <= n; i++) {
		cin >> a[i];
	}
	mid = n / 2;
	backTracking(1,0);
 
	findingNemo(mid + 1, 0);
 
	cout << res;
}