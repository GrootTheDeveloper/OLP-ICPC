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
int l,r,k;
int a[1000006];

int calc(int n)
{
	int res=0;
	for (int i=1;i*i<=n;i++) res+=(n%(i*i)==0);
	return res;
}
void solve()
{
	int res=0;
	for (int i=l;i<=r;i++) res+=(calc(i)==k);
	cout << res;
}
int cnt[20000007];
void fulltask()
{
	int lim=trunc(sqrt(r));
	for (int i=2;i<=lim;i++) 
	{
		int jum=i*i;
		for (int j=jum;j<=r;j+=jum) cnt[j]++;
	}
	int res=0;
	for (int i=l;i<=r;i++) res+=(cnt[i]+1==k);
	cout << res;
}
void ReadText()
{
	freopen("kdiv.inp","r",stdin);
	freopen("kdiv.out","w",stdout);
	cin >> l >> r >> k;
	if (r<=2000) solve();
	else fulltask();
	//solve();cout << '\n';fulltask();
}

signed main()
{
	fastIO();
	ReadText();
	//solve();
}