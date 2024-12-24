#include<iostream>
using namespace std;
int binarySr(int arr[],int low,int high,int x)
{
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==x)
        {
            return mid;
        }
        if(arr[mid]<x)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int x=5;
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=binarySr(arr,0,n-1,x);
    if(result==-1)
    {
        cout<<"not found"<<endl;
    }
    else
    {
        cout<<"found at index : "<<result;
    }
    return 0;
}
