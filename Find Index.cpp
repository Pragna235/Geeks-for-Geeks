//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findIndex(vector<int>& arr, int key) {
        // code here.
        vector<int> result = {-1,-1};
        int n = arr.size();
        
        int i=0, j=n-1;
        
        while(i<=j){
            if(arr[i] == key){
                result[0] = i;
            }
            if(arr[j]==key){
                result[1]=j;
            }
            if(result[0]!=-1 and result[1]!=-1){
                break;
            }
            if(result[0]==-1) i++;
            if(result[1]==-1) j--;
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> res;
        vector<int> arr;
        string s;
        getline(cin, s);
        stringstream ss(s);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int key;
        cin >> key;
        cin.ignore();
        Solution ob;
        res = ob.findIndex(arr, key);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends
