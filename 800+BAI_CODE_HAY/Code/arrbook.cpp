#include <bits/stdc++.h>
using namespace std;
int n,f[1000],ai;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> ai, f[ai]++;
	for (int i=1;i<=100;i++) while (f[i]!=0) cout << i << ' ',f[i]--;
}