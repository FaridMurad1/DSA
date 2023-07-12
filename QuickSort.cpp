#include <bits/stdc++.h>
using namespace std;

int divide(int a[], int start, int end)
{

    int pivot = a[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (a[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(a[pivotIndex], a[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (a[i] <= pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(a[i++], a[j--]);
        }
    }

    return pivotIndex;
}

void sort(int a[], int start, int end)
{

    if (start >= end)
        return;

    int p = divide(a, start, end);

    sort(a, start, p - 1);
    sort(a, p + 1, end);
}

int main()
{
    int a[] = {1,5,7,4,2,6,3};
    int n = sizeof(a)/sizeof(a[0]);

    sort(a, 0, n);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}