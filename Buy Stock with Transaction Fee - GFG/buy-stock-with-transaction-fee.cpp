//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long helper(int index , int buy , vector<vector<long long>>&dp , vector<long long>&prices, int n, int fee){
        if(index >= n) return 0 ; 
        
        if(dp[index][buy] != -1) return dp[index][buy];
        
        // choices 
        if(buy == 0){
            long long take = -prices[index] + helper(index + 1 , 1 , dp , prices , n , fee);
            long long notake = helper(index + 1,  0 , dp , prices , n , fee);
            return dp[index][buy] = max(take,notake);
        }
        else if(buy == 1){
            long long take = prices[index] - fee + helper(index + 1 , 0 , dp , prices , n , fee);
            long long notake = helper(index + 1,  1 , dp , prices , n , fee);
            return dp[index][buy] = max(take,notake);
        }
    }
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
        // vector<vector<long long>> dp(n , vector<int>(2,-1));
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return helper(0 , 0 , dp , prices , n , fee);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends