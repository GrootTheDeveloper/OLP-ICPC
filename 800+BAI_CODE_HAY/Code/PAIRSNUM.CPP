#include <bits/stdc++.h>
using namespace std;
int cnt[2000006];
void init(){
	for (int i = 2; i <= 2e6; i += 2)
	for (int j = i; j <= 2e6; j += i)
		cnt[j]++;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	init();
	int n;
	while (cin >> n){
		cout << cnt[n * 2] << '\n';
	}	
}