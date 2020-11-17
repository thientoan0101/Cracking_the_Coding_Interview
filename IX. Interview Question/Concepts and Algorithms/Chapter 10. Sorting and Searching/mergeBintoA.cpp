#include <iostream>
#include <vector>
using namespace std;


int binaryInsertionSearch(int a[], int n, int x)
{
    int l = 0, r = n-1;
    int mid;
    while (l<=r)
    {
        mid = l+(r-l)/2;
        if (x<=a[mid]) r = mid -1;
        else l = mid + 1; 
    }
    if (x >= a[mid]) return mid + 1;
    return mid;	
}

void mergeBA(int a[], int n, int b[], int m)
{
    for (int i = 0; i<m; i++)
    {
        int pos = binaryInsertionSearch(a, n, b[i]);
        for (int j = n;j>=pos;j--)
            a[j] = a[j-1];
        a[pos] = b[i];
        n++;
    }
}

// BETTER METHOD:
void mergeBA2(int a[], int n, int b[], int m)
{
    int indexA = n-1, indexB = m-1;
    int indexMerge = n+m-1;

    while (indexB>=0)
    {
        if (indexA>=0 && a[indexA]>b[indexB])
        {
            a[indexMerge] = a[indexA];
            indexA--;
        } 
        else {
            a[indexMerge] = b[indexB];
            indexB--;
        }
        indexMerge--;
    }
}


void print(int arr[], int n)
{
    for (int i = 0;i<n;i++)
        cout<<arr[i]<<"  ";
    cout<<endl;
}


int main()
{
    int a[20] = {1,2,4,6,9,13,15};
    int n = 7;
    int b[5] = {3,6,8,9,13};
    int m = 5;
    mergeBA2(a,n,b,m);
    print(a, n+m);
    return 0;
}