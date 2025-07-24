#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct Trie
{
	struct node
	{
		vector <int> child;
		int cnt, exist;
	}nodes[N];
	int cur, ans;
	Trie()
	{
		cur = 0, ans = 0;
		nodes[cur].child.assign(26, -1);
		nodes[cur].cnt = nodes[cur].exist = 0;
	}
	int new_node()
	{
		cur++;
		nodes[cur].child.assign(26, -1);
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
			nodes[pos].cnt++;
			ans += nodes[pos].exist;
		}
		nodes[pos].exist++;
	}
};
Trie trie;


signed main()
{
	
}