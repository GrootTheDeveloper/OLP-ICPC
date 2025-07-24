#include <bits/stdc++.h>
using namespace std;

bool mask[222];
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int ans = 5;
	int omega = 420;
	for (int i = 80; i <= 100; i += 5)
		mask[i] = true;
	for (int i = 180; i <= 200; i += 5)
		mask[i] = true;
	for (int i = 5; i <= 100; i += 5)
	for (int j = 5; j <= 100; j += 5)
		ans += mask[i + j];

	cout << (double)ans / omega;
}