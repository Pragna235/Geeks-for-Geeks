//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
    int n = arr.size();  

    // Size of priority queue or min heap
    int pqSz = (n == k) ? k : k + 1; 
    
    // Min-heap to store the first k+1 elements
    priority_queue<int, vector<int>, greater<int>> 
                    pq(arr.begin(), arr.begin() + pqSz);

    int idx = 0;

    // Process remaining elements
    for (int i = k + 1; i < n; i++) {
        arr[idx++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    // Place remaining elements from the heap into 
    // the array
    while (!pq.empty()) {
        arr[idx++] = pq.top();
        pq.pop();
    }
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
        Solution obj;
        obj.nearlySorted(arr, k);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        // cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
