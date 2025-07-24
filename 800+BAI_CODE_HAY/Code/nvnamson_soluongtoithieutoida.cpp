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
#define int long long int 
#define pii pair <int,int>
#define fi first
#define se second
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
const int mode=1e9+7,N=1e6+7;
void fastIO(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int n,m;
int a[N],b[N],h[N],c[N],cnt;
int mp[N];
pair<int,int>p[N];
vector<int>nen;

signed main()
{//-5621978197074766663
	fastIO();
	h[0] = 1;
	FOR(i,1,N-1) h[i]=(h[i-1]*317);
	cin>>n>>m;
	FOR(i,1,m)cin>>a[i]>>b[i], p[i].first = a[i],p[i].second=b[i], a[i] = h[a[i]], b[i] = h[b[i]], nen.push_back(a[i]), nen.push_back(b[i]);
	FOR(i,1,n)c[i] = h[i], nen.push_back(h[i]);
	nen.erase(unique(nen.begin(),nen.end()),nen.end());
	sort(nen.begin(),nen.end());
	FOR(i,1,m) a[i] = lower_bound(nen.begin(), nen.end(), a[i]) - nen.begin() +1, b[i] = lower_bound(nen.begin(), nen.end(), b[i]) - nen.begin() +1;
	FOR(i,1,n) c[i] = lower_bound(nen.begin(), nen.end(), c[i]) - nen.begin() +1;
	//int ans1=h[100001]+h[99999]+h[99997],ans2=h[100000]+h[99999]+h[99998];
	//cout<<ans1<<" "<<ans2<<"\n";
	int total = n*(n-1)*(n-2)/6;
	FOR(i,1,m){
		int tmp=a[i]+b[i];
		FOR(j,1,n){
			if(c[j] != a[i] and c[j] != b[i]){
				tmp+=c[j];
			 	if(mp[tmp] == 0) {
			 		cnt++; 
					mp[tmp] = 1;
				}
				tmp-=c[j];
			}
		} 
	}
	cout<<total-cnt;
}