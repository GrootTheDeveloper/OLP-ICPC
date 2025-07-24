/*
________________________________________________________________________________________________________________
|Name : HuỳnhTấn Đức| ~ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = | Backspace|                            |
|Class: A5K7        |--------------------------------------------------------------|     ++++++                 |
|THPT Đỗ Đăng Tuyển |TAB| Q | W | E | R | T | Y | U | I | O | P | [ | ] | Lovely   |   ++++++++++               |
|Quảng Nam          |--------------------------------------------------------------|  ++++      +               |
|___________________|CapsLK | A | S | D | F | G | H | J | K | L | ; | " | ENTER    |  ++++           *     *    |
|         |(\/)     |--------------------------------------------------------------|  ++++         ***** *****  |
|*=====   |('.')    |   SHIFT   | Z | X | C | V | B | N | M | < | > | ? | SHIFT    |  ++++           *     *    |
|||   "   |(>> 🤍🤍|--------------------------------------------------------------|  ++++      +               |
|||    ++ |_________|Ctrl|Fn|Win|ALT|         SPACE         |ALT|Ctrl| <- | ^ | -> |   ++++++++++               |
|||       |     (\/)|--------------------------------------------------------------|     ++++++                 |
|*===="   | ***('.')| H | U | Ỳ | N | H  |🤍| T | Ấ  | N |🤍 | Đ | Ứ | C | -------|   Flower in Prison         |
|         | \___/<<)|-------------------------------------------------------------------------------------------|
|         | T.Tuyền |   I LOVE COMPETITIVE PROGRAMMING  | I WILL DISCIPLINE MYSELF TO BECOME MORE SUCCESSFUL    |
|_________|_________|___________________________________________________________________________________________|

*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*/
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int,int>
#define fi first
#define se second
const int mode=1e9+7,N=1e5+7;
void fastIO(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int n,q;
int a[100006],tree[N*4],pre[100005];

void build(int id, int l, int r)
{
	if (l==r) return tree[id]=a[l],void();
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	tree[id]=__gcd(tree[id*2],tree[id*2+1]);
}
int get(int id, int l, int r, int u, int v)
{
	if (u>r || l>v) return 0;
	if (u<=l && r<=v) return tree[id];
	int mid=(l+r)/2;
	return __gcd(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int f[1001][1001],ans[1001][1001];
int calc(int l, int r)
{
	int res=0;
	for (int i=l;i<=r;i++) for (int j=i;j<=r;j++) res=max(res,f[i][j]);
	return res;
}
void sub1()
{
	for (int i=1;i<=n;i++) for (int j=i;j<=n;j++) f[i][j]=(pre[j]-pre[i-1])*get(1,1,n,i,j);
	//for (int i=1;i<=n;i++) for (int j=i;j<=n;j++) ans[i][j]=calc(i,j);
	int u,v;
	while (q--)
	{
		cin >> u >> v;
		cout << calc(u,v) << '\n';
	}                  	   
}
void ReadText()
{
	freopen("SQ.INP","r",stdin);
	freopen("SQ.out","w",stdout);
	cin >> n >> q;
	for (int i=1;i<=n;i++) cin >> a[i],pre[i]=pre[i-1]+a[i];
	build(1,1,n);
	if (n<=1000) sub1();

}

signed main()
{
	fastIO();
	ReadText();
	//solve();
}
