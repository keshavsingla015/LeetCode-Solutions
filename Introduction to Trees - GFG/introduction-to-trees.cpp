//{ Driver Code Starts
// Initial Template for C++

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countNodes(int n) {
        // your code here
        // int count = 1 ; 
        int count = 0 ; 
        for(int i = 0 ; i < n-1 ; i++){
            count += pow(2,i) ; 
        }
        return count + 1 ; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int i;
        cin >> i;
        Solution ob;
        int res = ob.countNodes(i);

        cout << res;
        cout << "\n";
    }
}

// } Driver Code Ends