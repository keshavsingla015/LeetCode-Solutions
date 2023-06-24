//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  int solveUtil(int n, vector<int>& height, vector<int>& dp, int k){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps = INT_MAX;
        
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j]+ abs(height[i]- height[i-j]);
                mmSteps= min(jump, mmSteps);
            }
        }
        dp[i]= mmSteps;
    }
    return dp[n-1];
}

int minimizeCost(vector<int>& height, int n, int k){
    vector<int> dp(n,-1);
    return solveUtil(n, height, dp, k);
}
    // int () {
    //     // Code here
    //     vector<int>vec(n , -1);
        
    //     vec[0] = 0 ;
    //     for(int i = 1 ; i < n ; i++){
    //         // int ans = INT_MAX ; 
    //         for(int j = 1 ; j < k ; j++){
    //             vec[i] = vec[i-1] + abs(height[i] - height[i-1]);
    //             if(i>=j){
    //             // if(i>j){
    //                 vec[i] = min(vec[i] , vec[i-j] + abs(height[i] - height[i-j])) ;
    //             }
    //             if(j>i){
    //                 break ; 
    //             }
    //         }
            
    //     }
    //     return vec[n-1] ;
    // }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends