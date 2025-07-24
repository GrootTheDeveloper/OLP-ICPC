#include <bits/stdc++.h>
using namespace std;
#define int long long 


main()
{
	string s1,s2;
	cin >> s1 >> s2;
	int n=s1.size(),m=s2.size();
	s1+='A';s2+='A';
	int l=0,r=0;
	while (l<n || r<m)
	{
		if (s1[l]<=s2[r] || r==m) cout << s1[l++];
		else cout << s2[r++];
	}
}