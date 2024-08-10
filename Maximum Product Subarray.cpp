//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // Function to find maximum product subarray
    long long maxProduct(vector<int> arr, int n) {
        long long max_so_far = arr[0];
        long long min_so_far = arr[0];
        long long result = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] < 0) 
                swap(max_so_far, min_so_far);

            max_so_far = max((long long)arr[i], max_so_far * arr[i]);
            min_so_far = min((long long)arr[i], min_so_far * arr[i]);

            result = max(result, max_so_far);
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
