#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

void mergesort(int a[], int i, int j);
void merge(int a[], int i1, int j1, int i2, int j2);

int main()
{
	int a[30], n, i;
	printf("Enter no of elements: ");
	scanf("%d", &n);
	printf("\nEnter array elements: \n");

	for (i = 0; i<n; i++)
		scanf("%d", &a[i]);

	mergesort(a, 0, n - 1);

	printf("\nSorted array is : ");
	for (i = 0; i<n; i++)
		printf("%d ", a[i]);

	_getch();
}

void mergesort(int a[], int low, int high)
{
	int mid;

	if (low<high)
	{
		mid = (low + high) / 2;
		mergesort(a, low, mid);				//left recursion
		mergesort(a, mid + 1, high);		//right recursion
		merge(a, low, mid, mid + 1, high);	//merging of two sorted sub-arrays
	}
}

void merge(int a[], int low, int mid, int midPlus, int high)
{
	int temp[50];	//array used for merging
	int i, j, k;
	i = low;		//beginning of the first list
	j = midPlus;	//beginning of the second list
	k = 0;

	while (i <= mid && j <= high)	//while elements in both lists
	{
		if (a[i] < a[j])
		{	
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= mid)	//copy remaining elements of the first list
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <= high)	//copy remaining elements of the second list
	{
		temp[k] = a[j];
		k++;
		j++;
	}

	//Transfer elements from temp[] back to a[]
	for (i = low, j = 0; i <= high; i++, j++)
		a[i] = temp[j];
}