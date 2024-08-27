//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long noOfPainters(int arr[],long long units,int n){
        long long painters=1;
        long long pUnits = 0;
        for(int i=0;i<n;i++){
            if(arr[i]+pUnits <= units){
                pUnits+=arr[i];
            }
            else{
                painters++;
                pUnits = arr[i];
                
            }
        }
        return painters;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long low = *max_element(arr,arr+n);
        long long high = accumulate(arr,arr+n,0LL);
        while(low<=high){
            long long mid = (low+high)/2;
            long long painters = noOfPainters(arr,mid,n);
            if(painters>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends
