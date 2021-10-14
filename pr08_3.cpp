#include <iostream>
using namespace std;
int n, i, j, k;
double d, s;
int main()
{
	cin >> n;
	double** a = new double* [n];
	for (i = 0; i <= n; i++)
	a[i] = new double[n];
	double** a1 = new double* [n];
	for (i = 0; i <= n; i++) //
	a1[i] = new double[n];
	double* b = new double[n];
	double* x = new double[n];
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			a1[i][j] = a[i][j];
		}
		cin >> b[i];
	}
	for (k = 1; k <= n; k++)
	{
		for (j = k + 1; j <= n; j++)
		{
			d = a[j][k] / a[k][k];
			for (i = k; i <= n; i++)
			{
				a[j][i] = a[j][i] - d * a[k][i];
			}

			b[j] = b[j] - d * b[k];
		}
	}
	for (k = n; k >= 1; k--)
	{
		d = 0;
		for (j = k + 1; j <= n; j++)
		{
			s = a[k][j] * x[j];
			d = d + s;
		}
		x[k] = (b[k] - d) / a[k][k];
	}
	for (i = 1; i <= n; i++)
		cout << "x[" << i << "]=" << x[i] << " " << endl;
	return 0;
}