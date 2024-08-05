//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*  Function to calculate the longest consecutive ones
*   N: given input to calculate the longest consecutive ones
*/
class Solution
{
    public:
    int maxConsecutiveOnes(int N)
    {
        // code here
        int binary[32]={0};
        int i=0;
        
        while(N){
            binary[i]=N%2;
            i++;
            N=N/2;
        }
        
        //reverse(binary,binary+N);
        
        int count=0,maxi=0;
        
        for(int i=0;i<32;i++){
            if(binary[i]==1){
                count++;
                maxi = max(maxi,count);
            }
            else{
                count=0;
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

// Driver Code
int main() {
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n;
		cin>>n;//input n
		Solution obj;
		//calling maxConsecutiveOnes() function
		cout<<obj.maxConsecutiveOnes(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
