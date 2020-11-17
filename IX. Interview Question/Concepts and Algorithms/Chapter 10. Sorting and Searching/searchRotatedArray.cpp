#include <iostream>
using namespace std;


int binarySearch(int a[], int l, int r, int x)
{
    while (l<=r)
    {
        int mid = l + (r-l)/2;
        if (a[mid]==x)  return mid;
        if (x<a[mid]) r = mid- 1;
        else l = mid + 1;
    }
    return -1;
}

int searchRotated(int a[], int n, int x)
{
    if (a[n-1]>a[0]) return binarySearch(a,0,n-1, x);
    int pos = 0;
    while (a[pos]>a[pos+1]) 
    {
        if (a[pos]==x) return pos;
        pos++;
    }
    return binarySearch(a,pos,n-1,x);
}



int binaryRotatedSearch(int a[], int l, int r, int x)
{
    int mid = l +(r-l)/2;
    if (a[mid]==x) return mid;

    if (a[l]<a[mid])
    {
        if (a[l]<=x && x<a[mid]) return binaryRotatedSearch(a,l,mid,x);
        else return binaryRotatedSearch(a,mid+1,r,x);
    }
    else if (a[l]>a[mid])
    {
        if (a[mid]<x && x<=a[r]) return binaryRotatedSearch(a,mid,r,x);
        else return binaryRotatedSearch(a,l,mid-1,x);
    }
    else if (a[l]==a[mid])
    {
        if (a[mid]!=a[r])   return binaryRotatedSearch(a, mid, r, x);
        else {
            int result = binaryRotatedSearch(a,l,mid-1,x);
            if (result==-1) return binaryRotatedSearch(a,mid,r,x);
            else return result;
        }
    }
    return -1;
}












int main()
{
    int a[] = {15,16,19,20,25,1,3,4,5,7,10,14};
    int n = 12;
    int x = 5;
    //cout<<searchRotated(a,n,x);

    cout<<binaryRotatedSearch(a,0,11,x);



    return 0;
}