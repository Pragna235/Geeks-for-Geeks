//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long sum=0;
        long long maxi=LONG_MIN;
        
        int start;
        int answer_start=-1,answer_end=-1;
        // Your code here
        for(int i=0;i<n;i++){
            if(sum==0) start=i;
            
            sum+=arr[i];
            if(sum>maxi){
                maxi=sum;
                answer_start=start;
                answer_end=i;
            }
            
            if(sum<0)
            sum=0;
        }
        
        
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends
