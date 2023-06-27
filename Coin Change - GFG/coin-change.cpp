//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long int helper(int index , int sum , int coins[] , vector<vector<long>> &dp){
        // base conditions 
        // if(index == 0){
        //     if(coins[index] <= sum){
        //         return sum%coins[index] == 0;
        //         return 0 ; 
        //     }
        //     // return 0 ; 
        // }
        if(index == 0){
            return (sum%coins[0]==0);
        }
        
        if(dp[index][sum] != -1) return dp[index][sum];
        
        long notake = 0 + helper(index-1 , sum , coins , dp);
        long  take = 0; 
        if(coins[index] <= sum){
            take =  helper(index , sum - coins[index] , coins , dp);
        }
        
        return dp[index][sum] = take+notake ; 
    }
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long>> dp(N , vector<long>(sum+1 , -1));
        return helper(N-1 , sum , coins , dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends