#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct base{
	int fi = 0, last = 0;
} odd[11],even[11];
int a,pos;
void init()
{
	odd[1].fi = 1; odd[1].last = 9; 
	even[1].fi = 0; even[1].last = 8;
	odd[2].fi = 11; odd[2].last = 99; 
	even[2].fi = 10; even[2].last = 98;
	for (int i = 3; i <= 10; i++)
	{
		odd[i].fi = even[i-1].fi*10 + 1; odd[i].last = odd[i-1].last * 10 + 9; 
		even[i].fi = odd[i].fi - 1; even[i].last = odd[i].last - 1;
	}
}
void solodd()
{
	int loc = 0;
	for (int i = 1; i <= 10 && !loc; i++)
		if (a >= odd[i].fi && a <= odd[i].last) loc = i;
	while (((odd[loc].last - a) / 2 +1) * loc < pos)
	{
		pos -= loc * ((odd[loc].last - a) / 2 +1);
		loc ++;
		a = odd[loc].fi;
	}
	int k = pos / loc + (pos % loc != 0);
	a += (k-1)*2;
	k = ((pos % loc == 0)? loc : pos % loc);
	while (loc > k) loc--, a/=10;
	cout << a%10;
}
void soleven()
{
	int loc = 0;
	for (int i = 1; i <= 10 && !loc; i++)
		if (a >= even[i].fi && a <= even[i].last) loc = i;
	while (loc * ((even[loc].last - a) / 2 +1) < pos)
	{
		pos -= ((even[loc].last - a) / 2 +1) * loc;
		loc ++;
		a = even[loc].fi;
	}
	int k = pos / loc + (pos % loc != 0);
	a += (k-1)*2;
	k = ((pos % loc == 0)? loc : pos % loc);
	while (loc > k) loc--, a/=10;
	cout <<  a%10;
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	init();
	cin >> a >> pos;
	if (a&1) solodd();
	else soleven();

}