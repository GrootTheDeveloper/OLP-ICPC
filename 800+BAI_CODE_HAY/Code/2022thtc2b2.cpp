#include <bits/stdc++.h>
using namespace std;
#define int long long
string s,st;
deque <char> q;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("ROBOT.INP","r",stdin);
	freopen("ROBOT.OUT","w",stdout);
	cin >> s;
	cin >> st;
	for (char c : s) q.push_back(c);
	for (char c : st)
	{
		if (c=='L') q.push_back(q.front()),q.pop_front();
		else q.push_front(q.back()),q.pop_back(); 
	}
	while (q.size())
	{
		cout << q.front();
		q.pop_front();
	}
}