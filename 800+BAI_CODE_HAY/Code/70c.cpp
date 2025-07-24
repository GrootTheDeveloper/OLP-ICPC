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
int n,x,k;
int a[1000006];
void sub1()
{
	cout << "YES" << '\n';
	for (int i=1;i<=x;i++) cout << i << ' '; 	   
}
void sub2()
{
	vector <int> cnt[2];
	for (int i=1;i<=n;i++) cnt[a[i]%2].push_back(i);
	vector <int> ans;
	int m=min(x/2*2,(int)cnt[1].size()/2*2);
	for (int i=0;i<m;i++) ans.push_back(cnt[1][i]);
	x-=m;
	if ((int)cnt[0].size()<x) return cout << "NO",void();
	for (int i=0;i<x;i++) ans.push_back(cnt[0][i]);
	sort(ans.begin(),ans.end());
	cout << "YES\n";
	for (int c : ans) cout << c << ' ';
}
bool us[22];
string res="NO";
void check()
{
	int m=0,sum=0;
	for (int i=1;i<=n;i++) if (us[i]) sum+=a[i],m++;
	if (m==x && sum%k==0)
	{
		res="YES";
		cout << "YES" << '\n';
		for (int i=1;i<=n;i++) if (us[i]) cout << i << ' ';
	}
}
void Try(int i)
{
	if (res=="YES") return;
	if (i>n) return check(),void();
	us[i]=1;Try(i+1);
	us[i]=0;Try(i+1);
}

void ReadText()
{
	freopen("div.inp","r",stdin);
	freopen("div.out","w",stdout);
	cin >> n >> x >> k;
	for (int i=1;i<=n;i++) cin >> a[i];
	if (k==1) sub1();
	else if (k==2) sub2();
	else if (n<=20) Try(1);
	
}

signed main()
{
	fastIO();
	ReadText();
	//solve();
}