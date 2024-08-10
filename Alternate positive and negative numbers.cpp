//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector<int> pos;
	    vector<int> neg;
	    
	    for(int i=0;i<n;i++){
	        if(arr[i]<0) neg.push_back(arr[i]);
	        else pos.push_back(arr[i]);
	    }
	    
	    if(neg.size()<pos.size()){
	        for(int i=0;i<neg.size();i++){
	            arr[2*i] = pos[i];
	            arr[2*i+1] = neg[i];
	        }
	        int index = neg.size() * 2;
	        for(int i=neg.size();i<pos.size();i++){
	            arr[index] = pos[i];
	            index++;
	        }
	    }
	    else{
	        for(int i=0;i<pos.size();i++){
	            arr[2*i] = pos[i];
	            arr[2*i+1] = neg[i];
	        }
	        int index = pos.size() * 2;
	        for(int i=pos.size();i<neg.size();i++){
	            arr[index] = neg[i];
	            index++;
	        }
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
