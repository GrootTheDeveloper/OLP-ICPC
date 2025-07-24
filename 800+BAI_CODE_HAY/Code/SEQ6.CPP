#include <bits/stdc++.h>
using namespace std;
int heso[100005];
void sie(int N){
	for (int i = 1; i <= N; i++)
		for (int j = i; j <= N; j += i)
			heso[j]++;
	// for (int i = 1; i <= N; i++)
	// 	for (int j = i * 2; j <= N; j += i)
	// 		heso[j] += heso[i];
	int ans = 0;
	for (int i = 1; i <= N; i++)
		ans += heso[i];
	cout << ans;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	sie(100000);
}