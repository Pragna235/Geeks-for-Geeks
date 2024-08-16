//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int n,int R)
    {
       //Your code here
       long long ans = 1.0;
       long long rr = R;
       long long N = n;
       long long mod = 1e9+7;
       
       if(rr<0) rr = (-1) * rr;
       
       while(rr){
           if(rr%2){
               ans = (ans * N) % mod;
               rr-=1;
           }
           else{
               N = (N * N) % mod;
               rr/=2;
           }
       }
       if(R<0) ans = (double)(1.0) / (double)(ans);
       return ans;
        
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends
