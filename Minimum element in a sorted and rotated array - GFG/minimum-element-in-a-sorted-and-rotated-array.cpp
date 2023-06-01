//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        // int minimum = INT_MAX ; 
        // for(int i = 0 ;i < n ;i++){
        //     minimum = min(minimum , arr[i]); 
        // }
        // return minimum ; 
        int low = 0 ; int high = n-1 ;
        
        int mini = INT_MAX ; 
        while(low<=high){
            int mid = (low+high)/2;
            
            if(arr[mid] > arr[high]){
                low = mid + 1 ; 
            }
            else{
                high = mid -1 ; 
            }
            mini = min(mini , arr[mid]);
        }
        return mini ; 
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends