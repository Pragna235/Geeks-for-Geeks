//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> a, int n) {
        // code here
       // int n= a.size();
    //int n = a.size();
    int xor1 = 0;
    
    // Step 1: Get the XOR of all elements in the array and numbers from 1 to n
    for (int i = 0; i < n; i++) {
        xor1 ^= a[i];
    }
    for (int i = 1; i <= n; i++) {
        xor1 ^= i;
    }

    // Step 2: Get the rightmost set bit in xor1
    int set_bit = xor1 & ~(xor1 - 1);

    // Step 3: Initialize two variables to hold two distinct groups
    int x = 0, y = 0;
    
    // Step 4: Divide the array elements and numbers 1 to n into two sets
    for (int i = 0; i < n; i++) {
        if (a[i] & set_bit) {
            x ^= a[i];
        } else {
            y ^= a[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i & set_bit) {
            x ^= i;
        } else {
            y ^= i;
        }
    }

    // Step 5: Determine which is the missing number and which is the repeating one
    int x_count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            x_count++;
        }
    }

    if (x_count == 0) {
        return {y,x};  
    } else {
        return {x,y};  
    }}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
