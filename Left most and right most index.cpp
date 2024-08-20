//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    long firstOccurrence(vector<long long>&arr, long long n, long long k){
        int low=0,high=n-1;
        long first=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==k){
                first=mid;
                high=mid-1;
            }
            else if(arr[mid]<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return first;
    }
    long lastOccurrence(vector<long long>&arr, long long n, long long k){
        int low=0,high=n-1;
        int last=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==k){
                last=mid;
                low=mid+1;
            }
            else if(arr[mid]<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return last;
    }
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        int n = v.size();
        long first = firstOccurrence(v,n,x);
        if(first==-1) return {-1,-1};
        long last = lastOccurrence(v,n,x);
        return {first,last};
        
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends
