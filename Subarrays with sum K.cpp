//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        int sum=0;
        int count=0;
        map<int,int> preSumMap;
        
        for(int i=0;i<N;i++){
            sum+=Arr[i];
            if(sum==k){
                count++;
            }
            
            int rem = sum-k;
            
            if(preSumMap.find(rem)!=preSumMap.end()){
                count = count+preSumMap[rem];
            }
            
            if(preSumMap.find(sum)==preSumMap.end()){
                preSumMap[sum]=1;
            }
            else{
                preSumMap[sum]++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
