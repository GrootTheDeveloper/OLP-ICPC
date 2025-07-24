#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int du[N], di[N];
void solve(string &s){
	int n = s.size();
	s = " " + s;
	fill(du, du + n + 1, 0);
	fill(di, di + n + 1, 0);
	int id = 0;
	int id_u = -1, id_i = -1, lowU = 1e6, lowI = 1e6;
	for (int i = 1; i <= n; i++){
		di[i] = di[i - 1] + (s[i] == 'I'? 1 : -1);
		du[i] = du[i - 1] + (s[i] == 'U'? 1 : -1);
		//cout << '(' << du[i] << ' ' << di[i] << ") ";
		while (s[id + 1] != s[i]){
			if (3 * du[id] - id < lowU){
				lowU = 3 * du[id] - id;
				id_u = id + 1;
			}
			if (3 * di[id] - id < lowI){
				lowI = 3 * di[id] - id;
				id_i = id + 1;
			}
			++id;
			//cout << '(' << lowI << ' ' << id_i << ' ' << lowU << ' ' << id_u << ") ";
		}
		if (id != 0){
			if (3 * du[i] - i >= lowU){
				return cout << "yes" << ' ' << id_u << ' ' << i, void();
			}
			if (3 * di[i] - i >= lowI){
				cout << 3 * di[i] - i << ' ';
				return cout << "yes" << ' ' << id_i << ' ' << i, void();
			}
		}
	}
	cout << "no";

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> q;
	while (q--){
		string s; cin >> s;
		solve(s);
		cout << '\n';
	}
}