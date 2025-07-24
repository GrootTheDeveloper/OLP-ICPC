#include <bits/stdc++.h>
using namespace std;

int a[555][555];
long long col[555][555];
int n, m;
void input(){
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++){
		cin >> a[i][j];
		col[j][i] = col[j][i - 1] + a[i][j];
	}
}
void add(long long &sum, int x, int y, int heso){
	if (x > 0 && x <= m && y > 0 && y <= n)
		sum += heso * a[x][y];
}
void add_col(long long &sum, int id, int x, int y, int heso){
	sum += heso * (col[id][y] - col[id][x - 1]);
}
void solve(){
	long long ans = -1e18;
	for (int x = 1; x <= m; x++)
	for (int y = x; y <= m; y += 2){
		int len = y - x + 1, id = 1;
		long long sum = 0;
		for (int i = 1; i <= n; i++){
			add(sum, (x + y) >> 1, i + 1, 1);
			add(sum, x, i - len / 2, 1);
			add(sum, y, i - len / 2, 1);
			add(sum, (x + y) >> 1, i - len, 1);
			add_col(sum, i, x, y, 1);
			ans = max(ans, sum);

			add(sum, (x + y) >> 1, i + 1, -1);
			add(sum, x, i - len / 2, -1);
			add(sum, y, i - len / 2, -1);
			add(sum, (x + y) >> 1, i - len, -1);
			if (i - id == y - x)
				add_col(sum, id++, x, y, -1);
		}
	}
	cout << ans;	
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
	input();
	solve();
}