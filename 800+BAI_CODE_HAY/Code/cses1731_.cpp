#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6 + 6;
const int mode = 1e9 + 7;


struct node
{
	vector <int> child;
	int exits;
}nodes[N];
int cur;
int new_node()
{
	cur++;
	nodes[cur].child.assign(26, -1);
	nodes[cur].exits = 0;
	return cur;
}
void add_string(string &s)
{
	int pos = 0;
	for (char f : s)
	{
		int c = f - 'a';
		if (nodes[pos].child[c] == -1) 
			nodes[pos].child[c] = new_node();
		pos = nodes[pos].child[c];
	}
	nodes[pos].exits++;
}


int dp[5555];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	nodes[0].child.assign(26, -1);
	nodes[0].exits = 0;
	for (int i = 1; i <= n; i++)
	{
		string s; cin >> s;
		sort(s.begin(), s.end());
		add_string(s);
	}
	cout << cur + 1;
}