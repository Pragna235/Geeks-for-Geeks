//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    long long noOfPages(int arr[], int pages,int n){
        long long pagesStudent = 0;
        long long students = 1;
        for(int i=0;i<n;i++){
            if(arr[i] + pagesStudent <= pages){
                pagesStudent += arr[i];
            }
            else{
                students ++;
                pagesStudent = arr[i];
            }
        }
        return students;
    }
    long long findPages(int n, int arr[], int m) {
        // code here
        if(m>n) return -1;
        int low = *max_element(arr,arr+n);
        int high = accumulate(arr,arr+n,0);
        while(low<=high){
            int mid = (low+high)/2;
            long long students = noOfPages(arr,mid,n);
            if(students>m){
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
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
