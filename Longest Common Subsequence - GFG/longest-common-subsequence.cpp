//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
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
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends