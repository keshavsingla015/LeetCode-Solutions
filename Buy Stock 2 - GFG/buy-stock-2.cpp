//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int helper(int index , int buy , vector<long long>&prices, int n , vector<vector<int>>&dp){
        // base 
        if(index == n){
            return 0 ;
        }
        
        if(dp[index][buy] != -1) return dp[index][buy];
        
        if(buy){
            int take = -prices[index] + helper(index + 1, 0 , prices , n , dp);
            int notake = 0 + helper(index + 1 , 1 , prices , n , dp);
            return dp[index][buy] = max(take, notake);
        }
        else{
            int take = prices[index] + helper(index + 1, 1 , prices , n , dp);
            int notake = 0 + helper(index + 1 , 0 , prices , n , dp);
            return dp[index][buy] = max(take, notake);
        }
    }
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<int>> dp(n , vector<int>(2 ,-1));
        // int one = helper(0 , )
        return helper( 0 , 1 , prices , n , dp);
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
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends