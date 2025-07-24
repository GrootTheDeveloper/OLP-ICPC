#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[555];
void input(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
bool check(int x){
	int cur = 0, cnt = 1;
	for (int i = 1; i <= n; i++){
		if (cur + a[i] <= x)
			cur += a[i];
		else
			++cnt, cur = a[i];
	}
	return cnt <= k;
}
void solve(){
	int l = 1, r = 1e9, ans;
	for (int i = 1; i <= n; i++)
		l = max(l, a[i]);
	while (l <= r){
		int mid = (l + r) >> 1;
		if (check(mid))
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	reverse(a + 1, a + n + 1);
	int cur = 0, human = 0;
	vector<int> b;
	for (int i = 1; i <= n; i++){
		if (cur + a[i] <= ans)
			cur = cur + a[i];
		else
			b.push_back(0), cur = a[i], human++;
		b.push_back(a[i]);
	}
	reverse(b.begin(), b.end());
	vector<int> Output;
	for (int i = 0; i < b.size() - 1; i++){
		Output.push_back(b[i]);
		if (b[i] != 0 && b[i + 1] != 0 && human != k - 1){
			Output.push_back(0);
			human++;
		}
	}
	Output.push_back(b.back());
	cout << '[';
	for (int i = 0; i < Output.size(); i++){
		if (Output[i])
			cout << Output[i];
		else
			cout << '/';
		if (i != Output.size() - 1)
			cout << ' ';
	}
	cout << ']';

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}