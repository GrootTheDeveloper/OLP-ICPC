#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	string s; cin >> s;

	vector<string> id;

	for (int i = 0; i < m; i++) {
		string temp; cin >> temp;
		sort(temp.begin(), temp.end());
		id.push_back(temp);
	}
	vector<char> fill;
	vector<int>blocks;
	

	// blocks[m]  = k ^ (m - 1) ; m : 1 -> M

	for (int M = 1; M <= m; M++) {
		blocks.push_back(pow(k, M - 1));
	}

	reverse(blocks.begin(), blocks.end());

	for (int level = 0; level < m; level++) {

		int val = 0;
		int le = 0;
		for (int mul = 0; mul < 100; mul++) {
			if (blocks[level] * mul >= x) {
				le = mul - 1;
				break;
			}
		}

		fill.push_back(id[level][le]);
		x -= blocks[level] * le;

	}
	int idx = 0;
	for (auto &c : s) {
		if (c == '#') {
			c = fill[idx++];
		}
	}
	cout << s;
}