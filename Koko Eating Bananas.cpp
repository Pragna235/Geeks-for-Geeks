//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int func(vector<int> arr, int mid){
      int ans =0;
      int n = arr.size();
      for(int i=0;i<n;i++){
          ans += ceil((double)arr[i] / (double)mid);
      }
      return ans;
  }
    int KoKoEat(vector<int>& arr, int k) {
        // Code here
        int low=1,high=*max_element(arr.begin(),arr.end());
        while(low<high){
            int mid = low + (high-low)/2;
            int hours = func(arr,mid);
            if(hours>k) low=mid+1;
            else high=mid;
        }
        return low;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;

        cout << ob.KoKoEat(arr, k);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
