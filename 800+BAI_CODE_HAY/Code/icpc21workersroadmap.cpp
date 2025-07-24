/*
________________________________________________________________________________________________________________
|Name : HuỳnhTấn Đức| ~ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = | Backspace|                            |
|Class: A5K7        |--------------------------------------------------------------|     ++++++                 |
|THPT Đỗ Đăng Tuyển |TAB| Q | W | E | R | T | Y | U | I | O | P | [ | ] | Lovely   |   ++++++++++               |
|Quảng Nam          |--------------------------------------------------------------|  ++++      +               |
|___________________|CapsLK | A | S | D | F | G | H | J | K | L | ; | " | ENTER    |  ++++           *     *    |
|         |(\/)     |--------------------------------------------------------------|  ++++         ***** *****  |
|*=====   |('.')    |   SHIFT   | Z | X | C | V | B | N | M | < | > | ? | SHIFT    |  ++++           *     *    |
|||   "   |(>>T.Đức |--------------------------------------------------------------|  ++++      +               |
|||    ++ |_________|Ctrl|Fn|Win|ALT|         SPACE         |ALT|Ctrl| <- | ^ | -> |   ++++++++++               |
|||       |     (\/)|--------------------------------------------------------------|     ++++++                 |
|*===="   | ***('.')| H | U | Ỳ | N | H | * | T | Ấ  | N | * | Đ | Ứ | C |---------|   Flower in Prison         |
|         | \___/<<)|-------------------------------------------------------------------------------------------|
|       Thanh.Tuyền |   I LOVE COMPETITIVE PROGRAMMING  | I WILL DISCIPLINE MYSELF TO BECOME MORE SUCCESSFUL    |
|_________|_________|___________________________________________________________________________________________|
 
*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*/
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define pii pair<int,int>
#define N 1000006
#define inf 1e18
int n,m,s,b[N];
pii a[N];
vector<int>st;
int pos[N],p[N];

int bs(int t){
	int l=0,r=n,ans=0;
	while(l <= r){
		int mid = (l + r) / 2;
		//cout<<"("<<mid<<","<<b[mid]<<","<<t<<") ";
		if(b[mid] < t){
			//cout<<mid<<" ";
			ans = mid;
			l = mid+1;
		}else r = mid - 1;
	}
	return ans;
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].first;
	FOR(i, 1, n) cin>>a[i].second,p[i]=p[i-1]+a[i].second;
	sort(a+1,a+n+1);
	//FOR(i,1,n) cout<<b[i]<<" ";
	//cout<<"\n";
	FOR(i,1,n){
        while (a[st.back()].second<a[i].second) st.pop_back();
        pos[i]=st.back();
        st.push_back(i);
    }
    FOR(i,1,n){
    	b[i]=b[pos[i]]+a[i].second*(a[i].first-a[pos[i]].first-1)-(p[i-1]-p[pos[i]]);
    }
	cin >> m;
	while(m--){
		int x; cin >> x;
		int ans = upper_bound(b+1,b+n+1,x)-b-1;
		cout<<ans<<"\n";
	}
	
}