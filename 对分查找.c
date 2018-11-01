#include<stdio.h>
int BinarySearch(const ElementType A[], ElementType X, int N)
{
	int low, mid, high;
	low = 0; high = N-1;
	while(low <= high)
	{
		mid = (low + high)/2;
		if(A[mid] < X)
			low = mid + 1;
		else if (A[mid] > X)
			high = mid - 1;
		else
			return mid;
	}
}