//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int index , int target , int val[] , int wt[] , vector<vector<int>>&dp){
        // vase cases 
        if(index == 0){
            if(wt[index] <= target) return val[index]*(target/wt[index]) ;
            else{
                return 0 ; 
            }
        }
        // if(index == 0){
        //     return (target/wt[0]) * val[0];
        // }
        // choices 
        if(dp[index][target] != -1) return dp[index][target];
        
        int notake = helper(index-1 , target , val , wt , dp);
        int take = 0 ; 
        if(wt[index] <= target){
            take = val[index] + helper(index , target - wt[index] , val , wt , dp);
        }
        return dp[index][target] = max(take , notake);
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N , vector<int>(W+1,-1));
        return helper(N-1 , W , val , wt , dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends