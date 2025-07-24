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
struct dta{
	int val=0,tb=0,tc=0;
}da[3333],db[3333],dc[3333];
int n,m;
int a[3333],c[3333],b[3333];
void solve()
{
	for (int i=1;i<=n;i++)
	{
		da[i]=da[i-1];da[i].val+=a[i];
		if (db[i-1].val+a[i]<=da[i].val) da[i]=db[i-1],da[i].val+=a[i];
		if (dc[i-1].val+a[i]<=da[i].val) da[i]=dc[i-1],da[i].val+=a[i];

		db[i].val=db[i-1].val+b[i]-db[i-1].tb;db[i].tb=db[i-1].tb+1;
		if ((db[i].val>da[i-1].val+b[i]-da[i-1].tb) || (db[i].val==da[i-1].val+b[i]-da[i-1].tb && db[i].tb+db[i].tc<=da[i-1].tb+da[i-1].tc))
		{
			db[i]=da[i-1];
			db[i].val+=b[i]-db[i].tb;
			db[i].tb++;
		}
		if ((db[i].val>dc[i-1].val+b[i]-dc[i-1].tb) || (db[i].val==dc[i-1].val+b[i]-dc[i-1].tb && db[i].tb+db[i].tc<=dc[i-1].tb+dc[i-1].tc))
		{
			db[i]=dc[i-1];
			db[i].val+=b[i]-db[i].tb;
			db[i].tb++;
		}

		dc[i]=dc[i-1];dc[i].val+=c[i]-dc[i].tc;dc[i].tc++;
		if ((dc[i].val>da[i-1].val+c[i]-da[i-1].tc) || (dc[i].val==da[i-1].val+c[i]-da[i-1].tc && dc[i].tc+dc[i].tb<=da[i-1].tc+da[i-1].tb))
		{
			dc[i]=da[i-1];
			dc[i].val+=c[i]-dc[i].tc;
			dc[i].tc++;
		}
		if ((dc[i].val>db[i-1].val+c[i]-db[i-1].tc) || (dc[i].val==db[i-1].val+c[i]-db[i-1].tc && dc[i].tc+dc[i].tb<=db[i-1].tc+db[i-1].tb))
		{
			dc[i]=db[i-1];
			dc[i].val+=c[i]-dc[i].tc;
			dc[i].tc++;
		}
		//cout << da[i].val << ' ' << db[i].val << ' ' << dc[i].val << '\n';
	}
	cout << min({da[n].val,db[n].val,dc[n].val});
	
}
void ReadText()
{
	cin >> n; for (int i=1;i<=n;i++) cin >> a[i] >> b[i] >> c[i];
}

signed main()
{
	fastIO();
	ReadText();
	solve();
}