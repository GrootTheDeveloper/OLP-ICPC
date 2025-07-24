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
int a[200005],d[11][200005];
void solve()
{
                  	   
}

void sub1()
{
	int l,r; 
	while (m--)
	{
		cin >> l >> r;
		int res=0;
		unordered_map <int,int> cnt;
		for (int i=l;i<=r;i++)
		{
			res+=(i-l)-cnt[a[i]];
			cnt[a[i]]++;
		}
		cout << res << '\n';
	}
}
void sub2()
{
	for (int k=1;k<=n;k++)
		for (int i=1;i<=10;i++) 
			d[i][k]=d[i][k-1]+(a[k]==i);
	int l,r;
	while (m--)
	{
		cin >> l >> r;
		int res=0;
		for (int i=1;i<10;i++) for (int j=i+1;j<=10;j++)
			res+=(d[i][r]-d[i][l-1])*(d[j][r]-d[j][l-1]);
		cout << res << '\n';
	}
}
void ReadText()
{
	freopen("bai4.inp","r",,stdin);
	freopen("bai4.out","w",stdout);
	cin >> n >> m;
	int mx=0;
	for (int i=1;i<=n;i++) cin >> a[i],mx=max(mx,a[i]);
	if (mx<=10) sub2();
	else if (n<=1000) sub1();
	

}

signed main()
{
	fastIO();
	ReadText();
	solve();
}