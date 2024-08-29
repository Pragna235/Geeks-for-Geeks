//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int noOfGasStations(vector<int> &stations, long double dist){
        int cnt=0;
        for(int i = 1;i<stations.size();i++){
            int numberBetween = (stations[i]-stations[i-1]) / dist;
            if((stations[i]-stations[i-1]) / dist == numberBetween * dist){
                numberBetween--;
            }
            cnt+=numberBetween;
        }
        return cnt;
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        long double low=0;
        long double high=0;
        for(int i=0;i<n-1;i++){
            high = max(high, (long double)(stations[i+1]-stations[i]));
        }
        
        long double diff = 1e-6;
        while(high - low > diff){
            long double mid = (low+high)/(2.0);
            int cnt = noOfGasStations(stations, mid);
            if(cnt>k){
                low=mid;
            }
            else{
                high=mid;
            }
        }
        return high;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends
