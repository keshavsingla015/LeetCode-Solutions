//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int A[], int N){
	    //code
	    unordered_map<int,int> map ; 
	    
	    for(int i = 0 ; i < N ; i++){
	        map[A[i]]++ ; 
	    }
	    
	    for(auto & it : map){
	        if(it.second == 1){
	            return it.first ; 
	        }
	    }
	    
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends