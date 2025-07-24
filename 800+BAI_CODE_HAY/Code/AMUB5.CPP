#include <bits/stdc++.h>
using namespace std;

string a, b;
int T[10], value[10][4];
void input(){
	cin >> a >> b;
}
void init(){
	for (int i = 0; i <= 9; i++){
		int cur = i;
		value[i][0] = i;
		while ((cur * i) % 10 != i){
			cur = cur * i % 10;
			T[i]++;
			value[i][T[i]] = cur;
		}
		T[i]++;
	}
}
void solve(){
	init();
	if (b.size() == 1)
		b = "0" + b;
	int A = a.back() - '0';
	int B = (b[b.size() - 2] - '0') * 10 + (b.back() - '0') - 1 + T[A];
	cout << value[A][B % T[A]];

}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();

}