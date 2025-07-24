#include <bits/stdc++.h>
using namespace std;
#define int long long 

string s;
char k[50];
int a[10][10],
	dx[4]={1,-1,0,0},
	dy[4]={0,0,-1,1};
char type[4]={'D','U','L','R'};
int res,ans;
vector <char> V;
void check()
{
	for (int i=1;i<=48;i++)
		if (k[i]!='?')
		{
			if (k[i]!=V[i-1]) return;
		}
	res++;
}
void Try(int x, int y, int cnt)
{
	if (cnt==49) return ans++,check(),void();
	for (int i=0;i<4;i++)
	{
		if (a[x+dx[i]][y+dy[i]]==0)
		{
			a[x+dx[i]][y+dy[i]]=-1;
			V.push_back(type[i]);
			Try(x+dx[i],y+dy[i],cnt+1);
			V.pop_back();
			a[x+dx[i]][y+dy[i]]=0;
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> s;
	for (int i=1;i<=48;i++) k[i]=s[i-1];
	memset(a,-1,sizeof(a));
	for (int i=1;i<=7;i++) for (int j=1;j<=7;j++) a[i][j]=0;
	Try(1,1,1);	
	cout << ans;
}