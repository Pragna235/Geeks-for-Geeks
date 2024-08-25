//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool possible(vector<int> &arr, int day, int m, int k){
        int n = arr.size();
        int cnt=0,nOfB=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=day){
                cnt++;
            }
            else{
                nOfB += (cnt/k);
                cnt=0;
            }
        }
        nOfB += (cnt/k);
        return nOfB>=m;
    }
    int solve(int M, int K, vector<int> &arr){
      // Code here
      long long val = M * 1LL * K * 1LL;
      int n = arr.size();
      if(val>n) return -1;
      
      int low = *min_element(arr.begin(),arr.end());
      int high = *max_element(arr.begin(),arr.end());
      while(low<=high){
          int mid = (low+high)/2;
          if(possible(arr,mid,M,K)){
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
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends
