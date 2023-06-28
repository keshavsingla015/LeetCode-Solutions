//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
      int helper(int idx1 , int idx2 , string s1, string s2 , vector<vector<int>> &dp){
        // vase case
        if(idx1 < 0 || idx2 < 0) return 0 ; 
        // choices
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        
        if((s1[idx1] == s2[idx2])){
            return dp[idx1][idx2] = 1 + helper(idx1-1 , idx2-1  ,s1 , s2 , dp);
        }
        
        else{
            int one = helper(idx1 , idx2-1  ,s1 , s2 , dp);
            int two = helper(idx1-1 , idx2  ,s1 , s2 , dp) ; 
            return dp[idx1][idx2] = max(one , two);
        }
        // return dp[idx1][idx2] = 
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(x , vector<int>(y , -1));
        return helper(x - 1, y-1 , s1 , s2 , dp);
        
    }
    int longestPalinSubseq(string s) {
        
        string s2 = s;
        reverse(s.begin() , s.end());
        int n = s.size() ;
        return lcs(n , n , s  , s2);
        // //code here
        // int n = s.size() ;
        // vector<vector<int>> dp(n , vector<int>(n , 0));
        
        // int ans = 0 ; 
        // // for(int i = 0  ;)
        // for(int i = 0 ; i < n ; i++){
        //     if(s[i] == s[n-i-1]){
        //         dp[i][0] = 1 ; 
        //         dp[0][i] = 1 ; 
        //     }
        // }
        
        // for(int i = 1 ; i < n ; i++){
        //     for(int j = n-1 ; j >= 0 ; j--){
        //         if(s[i] == s[j]){
        //             dp[i][j] = 1 + dp[i-1][j-1];
        //         }
        //         else{
        //             dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        //         }
        //     }
        // }
        // return dp[n-1][n-1];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends