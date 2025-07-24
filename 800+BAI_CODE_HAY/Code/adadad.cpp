#include <bits/stdc++.h>
using namespace std;


signed main(){
	int ans = 1000000;
	for (int x = 1; x <= 10; x++){
		vector<int> dp(66, 1000000);
		dp[0] = 0;
		for (int i = 3; i <= 60; i++){
			for (int j = 1; j <= x; j++){
				if (j * 3 <= i){
					dp[i] = min(dp[i], dp[i - j * 3] + 15 * (2 * j + 5));
				}
			}
		}
		ans = min(ans, dp[60] + x * 100);
	}
	cout << ans;
}