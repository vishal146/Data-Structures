#include<iostream>
#include<conio.h>
using namespace std;
 int main()
{
	int n, i, arr[50], search, first, last, mid;
	cout<<"Enter total number of elements :";
	cin>>n;
	cout<<"Enter "<<n<<" number :";
	for (i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter a number to find :";
	cin>>search;
	first = 0;
	last = n-1;
	mid = (first+last)/2;
	while (first <= last)
	{
		if(arr[mid] < search)
		{
			first = mid + 1;

		}
		else if(arr[mid] == search)
		{
			cout<<search<<" found at location "<<mid+1<<"\n";
			break;
		}
		else
		{
			 last = mid - 1;
		}
		mid = (first + last)/2;
	}
	if(first > last)
	{
		cout<<"Not found! "<<search<<" is not present in the list.";
	}
	return 0;
}
