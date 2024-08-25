//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int sumOfD(vector<int> &nums, int div){
        long long ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            ans += ceil((double)nums[i] / (double)div);
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        int n = nums.size();
        if(n>K) return -1;
        
        int low = 1, high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid = (low+high)/2;
            if(sumOfD(nums,mid)<=K){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
