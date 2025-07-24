#include <bits/stdc++.h>
using namespace std;
int arr[100005], brr[100005];
int len1, len2;

bool check(string &s)
{
	for (char c : s)
		if (c == '.') return true;
	return false;
}
void ex1(string &s, int* a, int &len)
{
	int A = 0, B = 0;
	int id = 0;
	while (s[id] != '.')
	{
		if (s[id] >= '0' && s[id] <= '9')
			A = A * 10 + (s[id] - '0');
		id++; 
	}
	while (s[id] != ']')
	{
		if (s[id] >= '0' && s[id] <= '9')
			B = B * 10 + (s[id] - '0');
		id++;
	}
	for (int i = A; i <= B; i++)
		a[++len] = i;
}
void ex2(string &s, int *a, int &len)
{
	int id = 0, value = 0;
	for (; s[id] != ']'; id++)
	{
		if (s[id] >= '0' && s[id] <= '9')
			value = value * 10 + (s[id] - '0');
		if (s[id] == ',')
			a[++len] = value, value = 0;
	}
	a[++len] = value;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; getline(cin, s);
	int X = 0, Y = 0;
	char sign1 = '+', sign2 = '+';
	int id = 0;
	for (; s[id] != ','; id++)
	{
		if (s[id] == '*' || s[id] == '+' || s[id] == '-')
			sign1 = s[id];
		if (s[id] >= '0' && s[id] <= '9')
			X = X * 10 + (s[id] - '0');
	}
	for (; s[id] != ')'; id++)
	{
		if (s[id] == '*' || s[id] == '+' || s[id] == '-')
			sign2 = s[id];
		if (s[id] >= '0' && s[id] <= '9')
			Y = Y * 10 + (s[id] - '0');
	}


	string st1 = "", st2 = "";
	for (; s[id] != ']'; id++)
		st1.push_back(s[id]);
	st1.push_back(s[id++]);
	while (s[id] != '[')
		id++;
	for (; s[id] != ']'; id++)
		st2.push_back(s[id]);
	st2.push_back(s[id++]);
	
	//cout << st1 << '\n' << st2 << ' ';
	
	if (check(st1))
		ex1(st1, arr, len1);
	else
		ex2(st1, arr, len1);

	if (check(st2))
		ex1(st2, brr, len2);
	else
		ex2(st2, brr, len2);

	cout << '[';
	for (int i = 1; i <= len1; i++)
	for (int j = 1; j <= len2; j++)
	{
		int a = arr[i], b = brr[j];
		if (sign1 == '+')
			a += X;
		else if (sign1 == '-')
			a -= X;
		else
			a *= X;

		if (sign2 == '+')
			b += Y;
		else if (sign2 == '-')
			b -= Y;
		else
			b *= Y;

		cout << '(' << a << ',' << b << ')';
		if (i * j != len1 * len2) 
			cout << ',' << ' ';
	}
	cout << ']';

	

}