#include <bits/stdc++.h>
using namespace std;
#define int long long 
int L[10000007],D[10000007],Q[10000007];
int l,q,d,node;
int n,k; 
string s;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	cin >> s;
	for (int i=1;i<=n;i++)
	{
		if (s[i-1]=='L') l++,L[l]=i;
		if (s[i-1]=='Q') q++,Q[q]=i;
		if (s[i-1]=='D') d++,D[d]=i;
	}
	int res=INT_MAX;
	for (int i=1;i<=l-k+1;i++)
	{
		node=i+k-1;
		if (node>l) break;
		node=upper_bound(Q+1,Q+q+1,L[node])-Q;
		node=node+k-1;
		if (node>q) break;
		node=upper_bound(D+1,D+d+1,Q[node])-D;
		node=node+k-1;
		if (node>d) break;
		res=min(res,D[node]-L[i]+1LL-3*k);	
	}
	if (res==INT_MAX) res=-1;
	cout << res;
}