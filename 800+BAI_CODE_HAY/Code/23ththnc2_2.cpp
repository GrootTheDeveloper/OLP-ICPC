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
|_________|_________|___________________________________________________________________________________________|*/
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int,int>
#define fi first
#define se second
const int mode=1e9+7,N=1e6+7;
void fastIO(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int a[20],dp[20][200],n;
bool prime[200];
void sie()
{
	prime[0]=prime[1]=1;
	for (int i=2;i<=sqrt(170);i++)
		if (!prime[i]) for (int j=i*i;j<=170;j+=i) prime[j]=true;
}

int calc(int pos, bool lim, int sum)
{
	if (pos==0) return !prime[sum];
	if (!lim && dp[pos][sum]!=-1) return dp[pos][sum];
	int mx=(lim? a[pos]:9);
	int res=0;
	for (int c=0;c<=mx;c++)
		res+=calc(pos-1,lim && c==mx,sum+c);
	if (!lim) dp[pos][sum]=res;
	return res;
}
int g(int x)
{
	n=0;
	while (x)
	{
		a[++n]=x%10;
		x/=10;
	}
	return calc(n,true,0);
}
void solve(int n)
{
	int l=1,r=(int)1e17;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (g(mid) > n) r=mid-1;
		else l=mid+1;
	} 	   
	while (g(l)<n) l++;
	while (g(l-1)>=n) l--;
	cout << l << '\n';
}
void ReadText()
{
	int t; cin >> t;
	sie();
	memset(dp,-1,sizeof(dp));
	while (t--)
	{
		int k; cin >> k;
		solve(k);
	}
}

signed main()
{

	freopen("input.inp","w",stdin);
	freopen("input.out","w",stdout);

	//fastIO();
//	ReadText();
	//solve();
}