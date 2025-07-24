#include <bits/stdc++.h>
using namespace std;
int n=8,cot[20],d1[20],d2[20],f[20][20],res=0;

void Try(int i)
{
    if (i>n) return void();
    for (int j=1; j<=n; j++)
    {
        if (f[i][j]==1)
        {
            if (cot[j]==0 && d1[i-j+n]==0 && d2[i+j-1]==0)
            {
                cot[j]=d1[i-j+n]=d2[i+j-1]=1;
                if (i==n) res+=1;
                else Try(i+1);
                cot[j]=d1[i-j+n]=d2[i+j-1]=0;
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i=1; i<=8; i++)
        for (int j=1; j<=8; j++)
        {
            char x;
            cin >> x;
            if (x=='.')
                f[i][j]=1;
            else
                f[i][j]=0;
        }
    Try(1);
    cout << res;

}
