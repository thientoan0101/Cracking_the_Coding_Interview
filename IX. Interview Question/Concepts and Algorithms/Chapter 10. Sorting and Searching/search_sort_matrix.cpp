#include <iostream>
using namespace std;


int binarySearch(int a[], int n, int x)
{    
    int left = 0, right = n-1;

    while (left<=right)
    {
        int mid = left + (right - left)/2;
        if (a[mid]==x) return mid;
        if (a[mid]>x) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

pair<int,int> searchMatrix(int a[][10], int n, int x)
{
    for (int i = 0; i<n; i++)
    {
        int pos = binarySearch(a[i], n, x);
        if (pos!=-1) return make_pair(i,pos);
    }
    return make_pair(-1,-1);
}


// Method 2:
bool searchMatrix2(int a[][], int n, int x)
{
    int row = 0;
    int col = n-1;

    while (row<n && col >= 0)
    {
        if (a[row][col]==x) return true;
        else if (a[row][col]>x) col--;
        else row++;
    }
    return false;
}

int main()
{
    int a[4][10] = { {15, 20, 40, 85},
              {20, 35, 80, 95},
              {30, 55, 95, 105},
              {40, 80, 100, 120}};

    pair<int,int> coordinate = searchMatrix(a, 4, 55);
    cout<<"("<<coordinate.first<<", "<<coordinate.second<<")"<<endl;
    return 0;
}