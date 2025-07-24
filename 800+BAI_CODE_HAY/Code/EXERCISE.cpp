#include <bits/stdc++.h>
using namespace std;
ifstream fi ("input.txt");
ofstream fo ("output.txt");
int main()
{
 int n;
 fi >> n;
 vector<int> a(n);
 int z = 0;
 for (int i = 0; i < n; i++)
 fi >> a[i], z += (a[i] == 0);
 fo << (((1 << (n - z)) - 1) << z) << '\n';
 int bz = 0;
 for (int i = 0; i < n; i++)
 if (a[i] == 0)
 fo << (1 << bz++) << ' ';
 else
 fo << (1 << (i - bz + z)) * a[i] << ' ';
 fo<<"\nTime: "<<clock()/(double)1000<<" sec"; }
