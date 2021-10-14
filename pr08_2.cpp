#include<iostream>
#include<vector>
using namespace std;
int bins(int a[], int l, int r, int x)
{
	int index;
	if (l > r)
	{
		index = -1;
	}
	else
	{
		int m = (l + r) / 2;
		if (x == a[m])
			index = m;
		else if (x < a[m])
			index = bins(a, l, m - 1, x);
		else
			index = bins(a, m + 1, r, x);
	}
	return index;
}
int main()
{
	int a[5] = {1,2,3,4,5};
	int key;
	cin >> key;
	cout << bins(a, 0, 4, key);
}