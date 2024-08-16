//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution {
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        vector<long long> ansRow;
        int mod = 1e9 + 7;
        long long ans = 1;
        ansRow.push_back(1); // The first element is always 1

        for (int col = 1; col < n; col++) {
            // Calculate the next element using the formula:
            // ans = ans * (n - col) / col;
            ans = (ans * (n - col)) % mod;
            ans = (ans * powmod(col, mod - 2, mod)) % mod; // Modular division
            
            ansRow.push_back(ans);
        }
        return ansRow;
    }

private:
    long long powmod(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
};



//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends
