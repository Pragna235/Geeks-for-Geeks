class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        int ans=1;
        // Your code here
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
            if(arr[i]==ans){
                ans++;
            }
        }
        return ans;
    } 
};
