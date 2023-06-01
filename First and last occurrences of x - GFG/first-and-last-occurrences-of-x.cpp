//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int high(int n, int key, int v[]) {
  int res = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (v[i] == key) {
      res = i;
      break;
    }
  }
  return res;
}

int low(int n, int key, int v[]) {
  int res = -1;
  for (int i = 0; i < n ; i++) {
    if (v[i] == key) {
      res = i;
      break;
    }
  }
  return res;
}

vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> v  ;
    int one = low(n , x , arr);
    v.push_back(one);
    one = high(n , x, arr);
    v.push_back(one);
    return v ; 
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends