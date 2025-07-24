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
const int mode=1e9+7,N=1e6+1;
void fastIO(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int n,m;
int divs[1000006];
bool f[1000006];
void sie(int n)
{
	int lim=trunc(sqrt(n));
	for (int i=2;i<=lim;i++)
		if (!divs[i]) for (int j=i*i;j<=n;j+=i) divs[j]=i;
	divs[2]=2;
	for (int i=3;i<=n;i+=2) if (divs[i]==0) divs[i]=i;
}
void process(int n)
{
	while (n!=1)
	{
		f[divs[n]]=true;
		n/=divs[n];
	}
}
bool orz(int n)
{
	while (n!=1)
	{
		if (f[divs[n]]) return false;
		n/=divs[n];
	}
	return true;
}
void solve()
{
	vector <int> v;
	for (int i=1;i<=m;i++)
	if (orz(i)) v.push_back(i);
	cout << v.size() << '\n';
	for (int i : v) cout << i << '\n';
}
void ReadText()
{
	cin >> n >> m;
	sie(N);
	int ai;
	for (int i=1;i<=n;i++) cin >> ai,process(ai);
}

signed main()
{
	fastIO();
	ReadText();
	solve();
}