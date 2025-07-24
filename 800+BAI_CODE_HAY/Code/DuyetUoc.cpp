#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> lower;
    vector <int> upper;


    int sqrtn = sqrt(n);
    for (int i = 1; i <= sqrtn; ++i)
        if (n % i == 0)
            lower.push_back(i),
            upper.push_back(n / i);


    /// Tach phan chung khi (n) la so chinh phuong
    if (lower.back() == upper.back()) upper.pop_back();
    reverse(upper.begin(),upper.end());
    /// In ket qua
    for (int x : lower) cout << x << " ";
    for (int x : upper) cout << x << " ";
    return 0;
}
