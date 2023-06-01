//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        int res = -1 ; 
        for(int i = 0 ; i <= h ; i++){
            if(A[i] == key){
                res = i ; 
                break ; 
            }
        }
        return res ; 
        //if we want to use binary search 
        // first find the first element of the array now divide the array into two parts
        // 1. array 2. rotated array 
        // apply binary search on both individually and return index 
        // if not present return -1 ; 
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends