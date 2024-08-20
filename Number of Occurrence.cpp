//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		int firstOccurrence(int arr[], int n, int k){
        int low=0,high=n-1;
        int first=-1;
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
    int lastOccurrence(int arr[], int n, int k){
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
    vector<int> searchRange(int arr[], int n,int target) {
        //int n = nums.size();
        int first = firstOccurrence(arr,n,target);
        if(first==-1) return {-1,-1};
        int last = lastOccurrence(arr,n,target);
        return {first,last};
    }


	int count(int arr[], int n, int x) {
	    // code here
	vector<int> temp = searchRange(arr,n,x);
	if(temp[0]==-1) return 0;
	return temp[1] - temp[0] + 1;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
