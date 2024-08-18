//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
    // Calculate GCD using Euclidean algorithm
    long long a = A, b = B;
    
    while (b != 0) {
        long long rem = a%b;
        a = b;
        b = rem;
    }
    
    long long gcd = a;
    long long lcm = (A * B) / gcd;  // Calculate LCM using the formula LCM * GCD = A * B
    
    return {lcm, gcd};
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends
