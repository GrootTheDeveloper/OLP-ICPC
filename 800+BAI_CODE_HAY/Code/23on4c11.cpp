//https://lqdoj.edu.vn/problem/23on4c11
#include <bits/stdc++.h>
using namespace std;
#define maxn 1000005

int t,n,a[maxn],ma=0,ai;

int main()
{

    cin >> t;
    vector <int> test;
    for (int i=1;i<=t;i++){
        cin >> ai;
        test.push_back(ai);
        ma=max(ma,ai);
    }
    for (int i=1;i<=ma;i++)
    {
        int k=i;
        while (k<=ma)
        {
            int l=i;
            while (l>0 && k<=ma)
            {
                a[k]+=1;
                l-=1;
                k+=1;
            }
            k+=i;


        }
    }
    for (auto it=test.begin();it!=test.end();it++)
        cout << a[*it] << endl;
    return 0;
}
