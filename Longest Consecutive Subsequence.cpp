//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      if(n==0) return 0;
      
      int count=0,longest=1,lastSmaller=INT_MIN;
      unordered_set<int> s;
      
      for(int i=0;i<n;i++){
          s.insert(arr[i]);
      }
      
      for(auto it : s){
          if(s.find(it-1) == s.end()){
              count=1;
              lastSmaller = it;
              while(s.find(lastSmaller+1)!=s.end()){
                  count++;
                  lastSmaller++;
              }
          }
          longest = max(longest, count);
      }
      return longest;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends
