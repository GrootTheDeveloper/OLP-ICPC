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
const int mode=1e11+7,N=1e6+7;
void fastIO(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
const int base=31;
int n,q,len;
string s;
unordered_map <int,bool> f;
int T[2222],po[2222];
int hash_(string p)
{
	int res=0;
	for (int i=0;i<p.size();i++) res=(res*base +p[i]-'a'+1)%mode;
	return res;
}

int dp[2000];
void solve()
{
	while (q--)
	{
		string st;
		cin >> len >> s;

		vector <ii> v;
		v.push_back({0,-1});
		for (int i=0;i<len;i++)
		{
			int cur=0;
			for (int j=i;j<min(len,i+10);j++)
				{
					cur=(cur*base+s[j]-'a'+1);
					while (cur>=mode) cur-=mode;
					if (f.find(cur)!=f.end()) v.push_back({i,j});
				}
		}

		
		int long_set=v.size()-1;
		for (int i=0;i<=long_set;i++) dp[i]=0;
		int res=0;
		for (int i=1;i<=long_set;i++)
		{
			for (int j=i-1;j>=0;j--)  
				if (v[j].se<v[i].fi) dp[i]=max(dp[i],dp[j]+v[i].se-v[i].fi+1);
			res=max(res,dp[i]);
		}
		cout << res << '\n';


			
	}          	   
}
void ReadText()
{
	freopen("bannedwords.inp","r",stdin);
	freopen("bannedwords.out","w",stdout);
	cin >> n >> q;
	for (int i=1;i<=n;i++)
	{
		cin >> len >> s;
		f[hash_(s)]=true;
	}
	po[0]=1;
	for (int i=1;i<=2000;i++) po[i]=(po[i-1]*base)%mode;
}

signed main()
{
	fastIO();
	ReadText();
	solve();
}