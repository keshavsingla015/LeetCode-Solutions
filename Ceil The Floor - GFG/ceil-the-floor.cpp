//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    pair<int,int> p ; 
    sort(arr , arr + n);
    // if(n == 0) return -1;
        int ans = -1; 
        for(int i=n-1; i>=0; i--){
            if(arr[i]<=x) {
                ans = arr[i];
                break;
            }
        }
        p.first = ans; 
        
        int ceiling = -1 ; 
        for(int i = 0 ; i < n ; i++){
            if(arr[i] >= x){
                ceiling = arr[i] ; 
                break ;
            }
        }
        p.second = ceiling ; 
        
        return p ; 
}