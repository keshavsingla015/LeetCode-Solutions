//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

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
    
    int countMin(string str){
    //complete the function here
        string s2 = str ; 
        int n = str.size() ; 
        reverse(str.begin() , str.end());
        int ans = lcs( n  ,n , str, s2);
        
        return n-ans ; 
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends