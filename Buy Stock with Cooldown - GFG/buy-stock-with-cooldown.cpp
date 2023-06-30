//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long helper(int index , int buy , vector<long long>&prices,
    vector<vector<int>>&dp){
        // base case 
        if(index >= prices.size()) return 0 ;
        
        if(dp[index][buy] != -1) return dp[index][buy];
        // choices 
        if(buy == 1){
            // can buy 
            int take = -prices[index] + helper(index+1 , 0 , prices , dp);
            int notake = 0 + helper(index+1 , 1 , prices , dp);
            return dp[index][buy] = max(take,notake);
        }
        else if(buy == 0){
            // can sell
            //sold
            int take = prices[index] + helper(index+2 , 1 , prices , dp);
            // not sold 
            int notake = 0 + helper(index+1 , 0 , prices , dp);
            return dp[index][buy] = max(take,notake);
        }
        
    }
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<int>>dp(n , vector<int>(2 , -1));
        return helper(0 , 1 , prices , dp);
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