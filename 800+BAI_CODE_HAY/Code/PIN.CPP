#include <bits/stdc++.h>
using namespace std;
const long long base = 311;
int Mask[16] = {0,1,2,4,8,3,5,6,9,10,12,7,11,13,14,15};
int cnt_bit[16] = {0,1,1,1,1,2,2,2,2,2,2,3,3,3,3,4};
int sta[5] = {0, 1, 5, 11, 15};
char a[50005][5];
void input(){
	cin >> n >> D;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= 4; j++)
		cin >> a[i][j];
	D = 4 - D;
}
long long Hash(string &s){
	long long ans = 0;
	for (char c : s)
		ans = ans * base + c;
	return ans;
}
void solve(){
	                                      
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cout.tie(0);
	input();
	solve();
}