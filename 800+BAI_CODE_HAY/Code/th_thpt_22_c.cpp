#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[10];


main()
{

	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("matma.inp","r",stdin);
	freopen("matma.out","w",stdout);
	string s; cin >> s;
	int sum=0;
	for (char c : s) sum+=(c-'0'),a[(int)(c-'0')]++;
	if (sum%3!=0 || a[0]==0) {cout << -1;exit(0);}
	for (int i=9;i>=0;i--) while (a[i]) cout << i,a[i]--;	
}