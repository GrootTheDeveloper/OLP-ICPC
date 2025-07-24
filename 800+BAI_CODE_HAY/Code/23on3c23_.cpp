#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e6 + 7;
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
string a[50004];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, [](string &a, string &b){
		return a.size() < b.size();
	});
	for (int i = 1; i <= n; i++) trie.add_string(a[i]);
	cout << trie.ans;
}