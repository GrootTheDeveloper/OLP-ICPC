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
const int mode=1e9+7,N=1e6+7;
void fastIO(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int n,m,q;
int cnt[1000006],pos[1000006];
struct dta{
	int si;
	vector <int> v;
}d[1000000];

void calc(int k)
{
	if (k>cnt[n]) return cout << "0 0" << '\n',void();
	int x=lower_bound(cnt+1,cnt+n+1,k)-cnt;
	//if (x==n+1) return cout << "0 0" << '\n',void();
	cout << x << ' ';
	k-=cnt[x-1];
	int N=pos[x];
	int first=lower_bound(d[N].v.begin(),d[N].v.end(),x)-d[N].v.begin();
	for (int i=first;i<d[N].si;i++)
	{
		if (k<=d[N].v[i+1]-d[N].v[i]-1) return cout << d[N].v[i]+k << '\n',void();
		else k-=d[N].v[i+1]-d[N].v[i]-1;
	}

}
void solve()
{
	int k;
	while (q--)
	{
		cin >> k;
		calc(k);
	}             	   
}
void ReadText()
{
	freopen("UNITE.INP","r",stdin);
	freopen("UNITE.OUT","w",stdout);
	cin >> n >> m >> q;
	int x;
	for (int i=1;i<=m;i++)
	{
		cin >> d[i].si;
		for (int j=1;j<=d[i].si;j++)
		{
			cin >> x; 
			pos[x]=i;
			d[i].v.push_back(x);
		}
		
		sort(d[i].v.begin(),d[i].v.end());
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=0;j<d[i].si;j++)
			cnt[d[i].v[j]]=(n-d[i].si)-d[i].v[j]+1+j;
		d[i].v.push_back(n+1);
	}
	cnt[0]=0;
	for (int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
	cout << cnt[n] << '\n';
	//for (int i=1;i<=m;i++) sort(d[i].v.begin(),d[i].v.end());
}

signed main()
{
	fastIO();
	ReadText();
	solve();
}