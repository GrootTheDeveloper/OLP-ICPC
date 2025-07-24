#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int sum,kq;
unordered_map<int,int> dem;
main()
{
	cin >> s;
	int n=s.size();
	s=" "+s;
	dem[0]=1;
	for (int i=1; i<=n; i++)
		{
			if (s[i]=='0') sum+=-1;
			else sum+=1;
			kq+=dem[sum];
			dem[sum]++;
		}
	cout << kq;

}