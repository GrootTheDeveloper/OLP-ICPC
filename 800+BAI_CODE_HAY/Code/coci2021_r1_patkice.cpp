#include <bits/stdc++.h>
using namespace std;
char a[111][111];
int d=0;
bool check(int i, int j)
{
    d++;
    if (a[i][j]=='x') return true;
    if (a[i][j]=='.') return false;
    if (a[i][j]=='v') return check(i+1,j);
    if (a[i][j]=='^') return check(i-1,j);
    if (a[i][j]=='>') return check(i,j+1);
    if (a[i][j]=='<') return check(i,j-1);
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n; cin >> m >> n;
    int x,y;
    for (int i=1;i<=m;i++)
    for (int j=1;j<=n;j++)
    {
        cin >> a[i][j];
        if (a[i][j]=='o') x=i,y=j;
    }
    int t=INT_MAX;
    char k='0';
    if (check(x,y+1)&& d<=t) k='E',t=d,d=0;
    if (check(x,y-1)&& d<=t) k='W',t=d,d=0;
    if (check(x-1,y)&& d<=t) k='N',t=d,d=0;
    if (check(x+1,y)&& d<=t) k='S';
    if (k!='0') return cout << ":)" << endl, cout << k,0;
    return cout << ":(",0;

}
