//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  int lowerBound(vector<int> arr, int n, int x){
      int low=0,high=n-1;
      int ans=n;
      while(low<=high){
          int mid = (low+high)/2;
          if(arr[mid]>=x){
              ans=mid;
              high=mid-1;
          }
          else{
              low=mid+1;
          }
      }
      return ans;
  }
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        int maxi=0;
        int index=-1;
        for(int i=0;i<n;i++){
            int cnt_ones = m - lowerBound(arr[i],m,1);
            if(cnt_ones>maxi){
                maxi=cnt_ones;
                index=i;
            }
        }
        return index;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
