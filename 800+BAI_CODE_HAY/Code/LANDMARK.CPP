#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define lef first
#define rig second
const int N = 5e5 + 5;
ii Pair[N], eg[N];
bool del[N];
int pos[1000006], n, m;

struct node{
	int lef, rig, id, dis;
	node(): lef(0), rig(0), id(0), dis(0){};
	node(int a, int b, int c, int d): lef(a), rig(b), id(c), dis(d){};
	bool operator < (const node &oth) const{
		return (dis == oth.dis? id > oth.id : dis < oth.dis);
	}
};
priority_queue<node> q;
int cur = 0;
int calc_dis(int a, int b){
	if (a == 0 && b == n + 1)
		return n;
	if (a != 0 && b == n + 1)
		return n - a;
	if (a == 0 && b != n + 1)
		return b - 1;
	int mid = (a + b) >> 1;
	return min(mid - a, b - mid);

}
int add(int a, int b){
	q.push(node(a, b, ++cur, calc_dis(a, b)));
	return cur;
}
int location(int a, int b){
	if (a == 0 && b == n + 1)
		return 1;
	if (a != 0 && b == n + 1)
		return n;
	if (a == 0 && b != n + 1)
		return 1;
	return (a + b) >> 1;
}
node get(){
	node ans;
	while (true){
		ans = q.top(); q.pop();
		if (!del[ans.id])
			break;
	}
	del[ans.id] = true;
	return ans;
}
void out(int id){
	cout << id << "<-(" << Pair[eg[id].lef].lef << ' ' << Pair[eg[id].rig].rig << ')' << "    ";
}
void solve(){
	cin >> n >> m;
	add(0, n + 1);
	add(0, 0);
	add(n + 1, n + 1);
	eg[0] = {2, 1};
	eg[n + 1] = {1, 3};
	Pair[1] = {0, n + 1};
	Pair[2] = {0, 0};
	Pair[3] = {n + 1, n + 1};
	while (m--){
		int type, x; cin >> type >> x;
		if (type == 1){
			node top = get();
			int mid = location(top.lef, top.rig);
			pos[x] = mid;
			cout << mid << '\n';
			int id1 = add(top.lef, mid), id2 = add(mid, top.rig);
			eg[mid] = {id1, id2};
			eg[top.lef].rig = id1;
			eg[top.rig].lef = id2;
			Pair[id1] = {top.lef, mid};
			Pair[id2] = {mid, top.rig};
			//cout << "(" << top.lef << ' ' << top.rig  << ")" << '\n';
			// out(top.lef);
			// out(top.rig);
			// out(mid);
			// cout << '\n';
		}
		if (type == 2){
			int mid = pos[x];
			// cout << "|||||";
			// out(mid);
			int id1 = eg[mid].lef, id2 = eg[mid].rig;
			eg[mid] = {0,0};
			del[id1] = del[id2] = true;
			int LEF = Pair[id1].lef, RIG = Pair[id2].rig;
			int id = add(LEF, RIG);
			Pair[id] = {LEF, RIG};
			eg[LEF].rig = eg[RIG].lef = id;
			// cout << "(" << LEF << ' ' << RIG << ")" << "    ";
			// out(LEF);
			// out(RIG);
			// cout << '\n';
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	solve();

}