#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,res=INT_MAX;
string s;
vector <int> L,Q,D;


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> n >> k;
	cin >> s;
	for (int i=0;i<(int)s.size();i++)
	{
		if (s[i]=='L') L.push_back(i+1);
		else if (s[i]=='Q') Q.push_back(i+1);
		else D.push_back(i+1);
	}
	for (int i=k-1;i<L.size();i++)
	{
		int it=upper_bound(Q.begin(),Q.end(),L[i])-Q.begin();
		it+=k-1;
		if (it<Q.size())
        {
            int it2=upper_bound(D.begin(),D.end(),Q[it])-D.begin();
            it2+=k-1;
            if (it2<D.size()) res=min(res,D[it2]-L[i-k+1]+1-3*k);
        }
        else continue;

	}
	if (res==INT_MAX) res=-1;
	cout << res;
}
