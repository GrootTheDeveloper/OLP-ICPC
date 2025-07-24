#include <bits/stdc++.h>
using namespace std; 
const int N = 1e5 + 5;
string a[N];

struct Trie
{
	struct node
	{
		vector<int> child;
		int cnt = 0, exits = 0;
	}nodes[N];
	int cur;
	Trie(){
		cur = 0;
		nodes[0].child.assign(26, -1);
		nodes[0].cnt = nodes[0].exits = 0;
	}
	int new_node()
	{
		cur++;
		nodes[cur].child.assign(26, -1);
		nodes[cur].cnt = nodes[cur].exits = 0;
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
		}
		nodes[pos].exits++;
	}
	bool find(string &s)
	{
		int pos = 0;
		for (char f : s)
		{
			int c = f - 'a';
			if (nodes[pos].child[c] == -1) return false;
			pos = nodes[pos].child[c];
		}
		return (nodes[pos].exits != 0);
	}
};
Trie T;

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, [](string a, string b)
	{
		return a.size() < b.size();
	});
	
	for (int i = 1; i <= n; i++)
	{
		string st = "";
		for (char c : a[i])
		{
			st.push_back(c);
			if (T.find(st) == true) return cout << "YES", 0;
		}
		T.add_string(a[i]);
		
	}
	cout << "NO";


}