#include <bits/stdc++.h>
using namespace std;
#define ii pair<long long, long long>
#define fi first
#define se second

struct node{
	int come, Time;
	node(): come(0), Time(0){};
	node(int a, int b) : come(a), Time(b){};
	bool operator < (const node &other)const{
		return come < other.come;
	}
};
node a[100005];
void input(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].come >> a[i].Time;
}
void solve(){
	sort(a + 1, a + n + 1);
	long long date = a[1].come, ans = 0;
	int id = 1;
	

}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}