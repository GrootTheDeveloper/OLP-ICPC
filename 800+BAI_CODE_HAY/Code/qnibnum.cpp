#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int lim=1e6+1;
vector <int> vi;
bool prime[lim];
int n;

void sang()
{
	for (int i=2;i<lim;i++)
		if (!prime[i])
		{
			vi.push_back(i);
			for (int j=i*i;j<lim;j+=i) prime[j]=true;
		}
}

main()
{
	cin >> n;
	int res=1;
	sang();
	for (int i : vi) 
		if (n%i==0) 
		{
			res*=i;
			while (n%i==0) n/=i;
		}
		else if (n==0) break;
	res*=n;
	cout << res;
}