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
int n;
map <ii,int> pos;
ii a[100005];
void solve()
{          	   
}
int dx[12]={-1,-1,-1,0,0,0,0,0,1,1,1,2};
int dy[12]={-1,0,1,-2,-1,0,1,2,-1,0,1,0};
void ReadText()
{
	cin >> n;
	int w;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i].fi >> a[i].se >> w;
		pos.insert({{a[i].fi,a[i].se},w});
	}
	int res=0;
	for (int i=1;i<=n;i++)
	{
		int ans=0;
		for (int j=0;j<12;j++)
			if (pos.find({a[i].fi+dx[j],a[i].se+dy[j]})!=pos.end()) 
				ans+=pos[{a[i].fi+dx[j],a[i].se+dy[j]}];
		res=max(res,ans);
	}
	cout << res;
}

signed main()
{
	fastIO();
	ReadText();
	solve();
}