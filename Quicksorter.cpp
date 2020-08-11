#include <iostream>
#include <conio.h>
using namespace std;
void max_heap(int *a, int y, int n)
{

	int x, temp;
	temp = a[y];
	x = 2 * y;
	while (x <= n)
	{
		if (x < n && a[x + 1] > a[x])
			x = x + 1;
		if (temp > a[x])
			break;
		else if (temp <= a[x])
		{
			a[x / 2] = a[x];
			x = 2 * x;
		}
	}
	a[x / 2] = temp;
	return;
}
void heapsort(int *a, int n)
{
	int y, temp;
	for (y = n; y >= 2; y--)
	{
		temp = a[y];
		a[y] = a[1];
		a[1] = temp;
		max_heap(a, 1, y - 1);
	}
}
void maxheap(int *a, int n)
{
	int y;
	for (y = n / 2; y >= 1; y--)
	{
		max_heap(a, y, n);
	}
}
int main()
{
	int s, y, x;
	cout << "Please enter the size of the array, must be smaller then or equal to 19.\n";
	cin >> s;
	int a[20];
	for (y = 1; y <= s; y++)
	{
		cout << "Enter the element : " << y << " ";
		cin >> a[y];
	}
	maxheap(a, s);
	heapsort(a, s);
	cout << "\nHere is the sorted array in ascending order: \n\n";
	for (y = 1; y <= s; y++)
	{
		cout << a[y] << "  ";
	}
}