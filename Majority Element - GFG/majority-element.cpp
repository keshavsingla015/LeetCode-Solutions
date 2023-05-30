//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int v[], int n)
    {
        //declaring a map:
        map<int, int> mpp;
    
        //storing the elements with its occurnce:
        for (int i = 0; i < n; i++) {
            mpp[v[i]]++;
        }
    
        //searching for the majority element:
        for (auto it : mpp) {
            if (it.second > (n / 2)) {
                return it.first;
            }
            re
    }

    return -1;
        // if(size == 1)return -1 ; 
        // if(size == 2){
        //     if(a[0] == a[1])return a[0];
        //     return -1;
        // }
        // int ans[10000]; 
        // int maxCount = 0 ; 
        // int num = 0 ; 
        // for(int i = 0 ; i<size ;i++){
        //     ans[a[i]]++;
        //     if(maxCount < ans[a[i]]){
        //         maxCount = ans[a[i]];
        //         num = a[i];
        //     }
        //     if(maxCount >= size/2) return a[i]; 
        // }
        
        // return - 1; 
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends