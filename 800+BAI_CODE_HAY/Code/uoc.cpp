#include <bits/stdc++.h>
using namespace std;
#define int long long
int mul(int a, int b, int mode)
{
    int res=0;
    while (b)
    {
        if (b&1) res=(res+a)%mode;
        a=(a+a)%mode;
        b/=2;
    }
    return res;
}
int power(int a, int b, int mode)
{
    int res=1;
    while (b)
    {
        if (b&1) res=mul(res,a,mode);
        a=mul(a,a,mode);
        b/=2;
    }
    return res;
}
bool nt(int n)
{
    if (n<4) return n==2 || n==3;
    if (n!=2 && n%2==0) return false;
    for (int i=1;i<=10;i++)
    {
        int x=2+rand()%(n-3);
        if (power(x,n-1,n)!=1) return false;
    }
    return true;
}
vector<int> pr;
bool prime[1000006];
void sie()
{
    int N=trunc(sqrt(1e6+5));
    for (int i=2;i<=N;i++)
    if (!prime[i]) for (int j=i*i;j<=1e6;j+=i) prime[j]=true;
    for (int i=2;i<=1e6;i++) if (!prime[i]) pr.push_back(i);
}
int sol(int n)
{

    int res=1;
    for (int p : pr)
    {
        if (p*p*p>n) break;
        int cnt=0;
        while (n%p==0)
        {
            n/=p;
            cnt++;
        }
        res*=(cnt+1);
    }
    if (nt(n)) res=res*2;
    else
    {
        int rot=trunc(sqrt(n));
        if (rot*rot==n && nt(rot)) res*=3;
        else if (n!=1) res*=4;
    }
    return res;

}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("t.out","w",stdout);
    sie();
    for (int i=1;i<=1000;i++) cout << i*i << ' ' << sol(i*i) << endl;
    
}


