//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& a, vector<int>& b)
    {
        // Your code goes here
        int n1 = a.size();
        int n2 = b.size();
        if(n1>n2) return MedianOfArrays(b,a);
        
        int low=0,high=n1;
        int left=(n1+n2+1)/2;
        int n = n1+n2;
        
        while(low<=high){
            int mid1 = (low+high)/2;
            int mid2 = left-mid1;
            
            int l1=INT_MIN, l2=INT_MIN;
            int r1 = INT_MAX,r2=INT_MAX;
            
            if(mid1<n1) r1=a[mid1];
            if(mid2<n2) r2=b[mid2];
            if(mid1-1>=0) l1=a[mid1-1];
            if(mid2-1>=0) l2=b[mid2-1];
            
            if(l1<=r2 && l2<=r1) {
                if(n%2==1) return max(l1,l2);
                return ((double)(max(l1,l2) + min(r1,r2))) / (2.0);
            }
            else if(l1>r2){
                high=mid1-1;
            }
            else{
                low=mid1+1;
            }
        }
        return 0;
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
