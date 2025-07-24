#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e5 + 5;
struct Trie
{
	struct node
	{
		int child[26];
		int exits, cnt;
	}nodes[N];
	int cur;
	Trie() : cur(0){
		memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
		nodes[cur].cnt = nodes[cur].cnt = 0;
	}

	int new_node()
	{
		cur++;
		memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
		nodes[cur].cnt = nodes[cur].exits = 0;
		return cur;
	}
	void add_string(string &s)
	{
		int pos = 0;
		for (int f : s)
		{
			int c = f - 'a';
			if (nodes[pos].child[c] == -1)
				nodes[pos].child[c] = new_node();
			pos = nodes[pos].child[c];
			nodes[pos].cnt++;
		}
		nodes[pos].exits++;
	}
	bool Del(int pos, string &s, int i)
	{
		if (i != s.size())
		{
			int c = s[i] - 'a';
			bool is = Del(nodes[pos].child[c], s, i + 1);
			if (is) nodes[pos].child[c] = -1;
		}
		else nodes[pos].exits--;
		if (pos != 0)
		{
			nodes[pos].cnt--;
			if (nodes[pos].cnt == 0) return true;
		}
		return false;
	}
	void delete_string(string &s)
	{
		if (find_string(s) == false) return;
		Del(0, s, 0);
	}
	bool find_string(string &s)
	{
		int pos = 0;
		for (int f : s)
		{
			int c = f - 'a';
			if (nodes[pos].child[c] == -1) return false;
			pos = nodes[pos].child[c];
		}
		return (nodes[pos].exits != 0);
	}
};


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

}