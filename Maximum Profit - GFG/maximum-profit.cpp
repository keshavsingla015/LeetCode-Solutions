//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
int getAns(int Arr[], int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp ){

    if(ind==n || cap==0) return 0; //base case
    
    if(dp[ind][buy][cap]!=-1)
        return dp[ind][buy][cap];
        
    int profit;
    
    if(buy==0){// We can buy the stock
        profit = max(0+getAns(Arr,n,ind+1,0,cap,dp), 
                    -Arr[ind] + getAns(Arr,n,ind+1,1,cap,dp));
    }
    
    if(buy==1){// We can sell the stock
        profit = max(0+getAns(Arr,n,ind+1,1,cap,dp),
                    Arr[ind] + getAns(Arr,n,ind+1,0,cap-1,dp));
    }
    
    return dp[ind][buy][cap] = profit;
}
    int maxProfit(int K, int N, int A[]) {
        // code here
        // vector<vector<vector<int>>> dp(N,vector<vector<int>>(2,vector<int>(K,-1)));
          vector<vector<vector<int>>> dp(N,vector<vector<int>>(2,vector<int>(K+1,-1)));
        // return getAns(A , N , 0 , 1 , K , dp);
        return getAns(A,N,0,0,K,dp);

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends