/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    bool static comparison(Job a, Job b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comparison);
        
        int maxi=arr[0].dead;
        
        for(int i=1;i<n;i++){
            maxi=max(maxi,arr[i].dead);
        }
        
        int slot[maxi+1];
        
        for(int i=0;i<=maxi;i++){
            slot[i]=-1;
        }
        
        int countjobs=0,jobprofit=0;
        
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(slot[j]==-1){
                    slot[j]=i;
                    countjobs++;
                    jobprofit+=arr[i].profit;
                    break;
                }
            }
        }
        
        
        vector<int> ans;
        ans.push_back(countjobs);
        ans.push_back(jobprofit);
        return ans;
        
        
    } 
};
