//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int nums = 1;
        sort(arr.begin(),arr.end());
        int twice;
        
        for(int i=0;i<n;i++){
            if(arr[i]==arr[i+1]){  //for finding element that occuring twice
                twice = arr[i];
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]==nums){ // for finding element that is missing
                nums++;
            }
        }
        return {twice,nums};
    }
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
