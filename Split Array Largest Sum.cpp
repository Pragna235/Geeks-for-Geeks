//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int noOfSubsets(int arr[], int n, int mid){
        long long sum=0;int subsets=1;
        for(int i=0;i<n;i++){
            if(arr[i]+sum <= mid){
                sum+=arr[i];
            }
            else{
                subsets++;
                sum=arr[i];
            }
        }
        return subsets;
    }
    int splitArray(int arr[] ,int n, int K) {
        // code here
        int low = *max_element(arr,arr+n);
        int high = accumulate(arr,arr+n,0);
        while(low<=high){
            int mid = (low+high)/2;
            int subsets = noOfSubsets(arr,n,mid);
            if(subsets>K){
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

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
