#include <bits/stdc++.h>
using namespace std;


struct node
{
	int w, u;
	node() : w(0), u(0) {};
	node(int a, int b) : w(a), u(b) {};

	bool operator < (const node &other) const
	{
		return (w < other.w);
	}

	node operator + (const node &other)
	{
		return node(w + other.w, u + other.u);
	}


};

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	priority_queue<node> q;


}