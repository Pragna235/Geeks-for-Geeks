//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    // Note that the size of the array is n-1
    int missingNumber(int N, vector<int>& arr) {

        // Your code goes here
        int xor1=0,xor2=0;
        int n = N-1;
        
        for(int i=0;i<n;i++){
            xor2 = xor2^arr[i];
            xor1 = xor1^(i+1);
        }
        xor1 = xor1^N;
        return xor1^xor2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.missingNumber(n, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends
