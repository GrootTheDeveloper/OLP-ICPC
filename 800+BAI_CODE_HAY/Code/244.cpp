#include <bits/stdc++.h>
using namespace std; 

string a[100005];

struct Trie
{
	struct node
	{
		vector <int> child;
		int exist, cnt;
	}nodes[100005];
	int cur;

	Trie()
	{
		cur = 0;
		nodes[0].child.assign(26, -1);
		nodes[0].exist = nodes[0].cnt = 0;
	}
	int new_node()
	{
		cur++;
		nodes[cur].chid.assign(26, -1);
		nodes[cur].cnt = nodes[cur].exist = 0;
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
			nodes[]
		}
	}

};


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n; 
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, [](string a, string b)
	{
		return a.size() < b.size();
	});
}