//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
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
    
    int shortestCommonSupersequence(string x, string y, int m, int n)
    {
        //code here
        int ans = lcs(m , n, x ,y);
        int one = abs(ans-m) ;
        int two = abs(ans-n );
        return one + two + ans;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends