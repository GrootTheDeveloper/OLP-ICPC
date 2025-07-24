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
#define val first
#define cnt second
const int mode = 1e15;
void fastIO(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

ii power(int a, int b)
{
	ii res;
	res.val = 1;
	while (b)
	{
		if (b&1) 
		{
			res.val *= a;
			res.cnt += res.val / mode;
			res.val %= mode;
		} 
		a = a*a % mode;
		b /= 2;
	}
	return res;
}

void solve()
{
                  	   
}
void ReadText()
{
	int a,b; cin >> a >> b;
	ii v1 = power(a,b);
	ii v2 = power(b,a);
	if (v1.cnt == v2.cnt && v1.val == v2.val) return cout << 0,void();
	else if (v1.cnt > v2.cnt || (v1.cnt == v2.cnt && v1.val > v2.val)) return cout << 1,void();
	else cout << 2;
}

signed main()
{
	fastIO();
	ReadText();
	solve();
}