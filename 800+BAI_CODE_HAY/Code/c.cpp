#include <bits/stdc++.h>
using namespace std;
#define int long long 

multiset <int> s;
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	priority_queue <pair<int,int>> q;
	q.push({1,2});
	q.push({2,1});
	cout << q.top().second;
}