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
        vector<vector<int>> dp(n+1 , vector<int>(2 ,0));
        // int one = helper(0 , )
        // return helper( 0 , 1 , prices , n , dp);
        for(int i = 0 ; i < 2 ; i++){
            dp[n-1][i] = 0 ;
        }
        int buy = 1 ;
        for(int index = n-1 ; index >= 0 ; index--){
            // int profit = 0 ;
            for(int buy = 0 ; buy < 2 ; buy++){
                long long profit =0 ; 
                if(buy){
                    int take = -prices[index] + dp[index+1][0];;
                    int notake = 0 + dp[index+1][1];;
                    profit = max(take, notake);
                }
                else{
                    int take = prices[index] + dp[index+1][1];
                    int notake = 0 + dp[index+1][0];;
                    profit = max(take, notake);
                }
                dp[index][buy] = profit ;
            }
        }
        return dp[0][1];
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