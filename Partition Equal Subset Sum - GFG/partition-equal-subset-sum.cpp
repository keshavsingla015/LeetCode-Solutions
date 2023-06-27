//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int answer(int index , int arr[] , vector<vector<int>> &dp , int target){
        if(target == 0) return true ; 
        if(index == 0) return arr[index] == target;
        
        if(dp[index][target] != -1) return dp[index][target];
        
        bool Notake = answer(index - 1 , arr , dp , target);
        bool take = false ; 
        if(arr[index] <= target) take = answer(index - 1, arr , dp , target-arr[index]);
        
        return dp[index][target] = Notake||take;
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0 ; 
        for(int i =0 ; i< N ;i++){
            sum+= arr[i];
        }
        if(sum%2 != 0) return false ;
        int target = sum/2 ;
        
        vector<vector<int>> dp(N , vector<int>(target+1 , -1));
        
        return answer(N-1 , arr , dp , target);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends