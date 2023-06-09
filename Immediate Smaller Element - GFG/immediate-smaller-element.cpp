//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void immediateSmaller(vector<int>&arr, int n) {
	    //  code here
	    vector<int> ans ; 
	    stack<int> st ; 
	    
	    for(int i = n-1 ; i >= 0 ; i--){
	        if(st.size() == 0){
	            ans.push_back(-1);
	        }
	        else if(st.size() > 0 && st.top() >= arr[i]){
	            ans.push_back(-1);
	           // while(st.size() > 0 && st.top() >= arr[i]){
	           //     st.pop() ;    
	           // }
	           // if(st.size() == 0){
	                    
	           //     }
                // else if(st.size() > 0 && st.top() < arr[i]){
	               //     ans.push_back(st.top());
                // }
	        }
	        else{
	            ans.push_back(st.top());
	        }
	        st.push(arr[i]);
	    }
	    reverse(ans.begin() , ans.end());
	    for(int i = 0 ; i < n ; i++){
	        arr[i] = ans[i];
	    }
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends