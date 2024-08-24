//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    void SortedDuplicates(int n, vector<int> &arr) {
        map<int, int> freq;
        vector<int> result;

        // Calculate the frequency of each element
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }

        // Collect elements with frequency greater than 1
        for (auto it : freq) {
            if (it.second > 1) {
                result.push_back(it.first);
            }
        }

        // If no duplicates, print -1
        if (result.empty()) {
            cout << -1;
        } else {
            // Sort and print the result
            sort(result.begin(), result.end());
            for (int i = 0; i < result.size(); i++) {
                cout << result[i];
                if (i != result.size() - 1) {
                    cout << " ";
                }
            }
        }
        cout << endl;  // To handle multiple test cases properly
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        
        obj.SortedDuplicates(n, arr);
        
    }
}

// } Driver Code Ends
