#include <bits/stdc++.h>
using namespace std;
#define int long long
int A,B,x1,x2,n,t;
int calc(int k)
{
    int a,b,c,x,res=0;
    cin >> a >> b >> c >> x;
    if (k==1) x1=x; else x2=x;
    int temp=n;
    if (temp) temp--,res+=a;
    if (n<=50) return res+temp*b;
    else return res+49*b+(n-50)*c;
}
 main()
 {
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> t;
    A=calc(1);
    B=calc(2);
    while (t--)
    {
        int m1,m2;
        cin >> m1 >> m2;
        A+=x1*(m2-m1+1);
        B+=x2*(m2-m1+1);
    }
    cout << ((A<=B)? 'A':'B') << '\n';
    cout << min(A,B);

 }
