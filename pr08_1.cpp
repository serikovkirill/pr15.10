#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,temp,i,j,max_1,min_1,med,maxv=0,elmax,k=0;
	long double s=0, avg,disp=0;
	cin >> n;
	vector <int> a(n+1);
	vector <int> b(n+10000000); //
	for (i=0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j <= n - 2 - i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n ; i++)
	{
		s += a[i];
	}
	avg = s / n;
	if (n % 2 == 1)
	{
		med = a[n / 2];
	}
	else med = a[(n + 1) / 2];
	for (int i = 0; i < n; i++)
	{
		disp =disp + ((a[i] - avg) * (a[i] - avg) / (n--));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] == a[j])
			{
				b[a[i]]++;
		}
	}
	}
	for (int i = 0; i < n; i++)
	{
		if (b[a[i]] > maxv)
		{
			maxv = b[a[i]];
			elmax = a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (b[a[i]] == maxv)
		{
			k++;
		}
	}
	if (k > 1)
	{
		elmax = med;
	}
	cout << a[0] << ' ' << a[n-1]<<' '<<a[n-1] - a[0]<<' '<<avg<<' '<<med<<' '<<elmax<<' '<<disp;
}