//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         if(l>=r) return;
         int l1=l,r1=m+1,k=0,size=r-l+1;
         int sorted[size];
         while(l1<=m && r1<=r){
             sorted[k++]=arr[l1]<arr[r1]?arr[l1++]:arr[r1++];
         }
         while(l1<=m){
             sorted[k++]=arr[l1++];
         }
         while(r1<=r){
             sorted[k++]=arr[r1++];
         }
         for(k=0;k<size;k++){
             arr[k+l]=sorted[k];
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l<r){
            int mid = (l+(r-l)/2);
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends
