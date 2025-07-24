/*
_______________________________________________________________________________________________
|Name : Minh Thư    | ~ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = | Backspace|          |
|Class: A4K7        |--------------------------------------------------------------|          |
|THPT Đỗ Đăng Tuyển |TAB| Q | W | E | R | T | Y | U | I | O | P | [ | ] | Lovely   |          |
|Quảng Nam          |--------------------------------------------------------------|          |
|___________________|CapsLK | A | S | D | F | G | H | J | K | L | ; | " | ENTER    |          |
|         |(\/)     |--------------------------------------------------------------|          |
|*=====   |('.')    |   SHIFT   | Z | X | C | V | B | N | M | < | > | ? | SHIFT    |          |
|||   "   |(>> 🤍🤍|--------------------------------------------------------------|          |
|||    ++ |_________|Ctrl|Fn|Win|ALT|       SPACE           |ALT|Ctrl| <- | ^ | -> |          |
|||       |     (\/)|--------------------------------------------------------------|          |
|*===="   | ***('.')| M | I | N | H |🤍| T | H  | Ư |🤍 |-------------------------|
|         | \___/<<)|-------------------------------------------------------------------------|
|         |         |             I LOVE COMPETITIVE PROGRAMMING                              |
|_________|_________|_________________________________________________________________________|
*/
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
	int t; cin >> t;
    while (t--)
    {
        cin >> n;
        int x=INT_MAX,sum=0;
        for (int i=1;i<=n;i++) cin >> a[i],x=min(x,a[i]),sum+=a[i];
        cout << sum-x*n << '\n';
    }
                  	   
}
void ReadText()
{

}

signed main()
{
	fastIO();
	ReadText();
	solve();
}