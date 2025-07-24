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
int n,m;
int a[1000006];
void solve()
{
                  	   
}
void ReadText()
{
	int t; cin >> t;
	while (t--)
	{
		int x; cin >> x;
		if (x>16) return;
		unordered_map <int,bool> f;
		f.insert({1,true});
		a[1]=1;
		int n=1;
		while (true)
		{
			n++;
			bool ok=false;
			for (int i=1;i<=x;++i)
			{
				a[n]=i;
				int ans=a[n];
				bool ok2=true;
				vector <int> v;
				for (int j=n-1;j>=1;--j) ans=ans&a[j],v.push_back(ans);
				for (int c : v) if (f.find(c)!=f.end()) {ok2=false;break;}
				if (ok2)
				{
					for (int c : v) f.insert({c,true});
					ok=true;
					break;					
				}
			}
			if (!ok) break; 
		}
		cout << n-1 << '\n';
		for (int i=1;i<=n-1;++i) cout << a[i] << ' ';
		cout << '\n';
	}
}

signed main()
{
	fastIO();
	ReadText();
	solve();
}