#include <bits/stdc++.h>
using namespace std;
#define int long long 

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int cntu=0,cntc=0,res=0; 
	for (char c : s)
	if (c=='c') cntc++;
	else if (c=='u') res+=cntc,cntu++;
	cout << max(res+cntu,res+cntc);
}