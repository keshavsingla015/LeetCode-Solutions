//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool inspect(int M , int K , vector<int> &bloomDay , int mid){
        int bloomed = 0 ; 
        int total = 0 ; 
        
        for(int i = 0 ; i < bloomDay.size() ;i++){
            if(bloomDay[i] <= mid){
                bloomed++ ; 
                if(bloomed == K){
                    total++ ; 
                    bloomed = 0 ; 
                }
            }
            else{
                bloomed = 0 ; 
            }
            if(total >= M){
                return true ; 
            }
        }
        return false ; 
    }
    
    int solve(int M, int K, vector<int> &bloomDay){
      // Code here+
      if(bloomDay.size() < M*K) return -1 ; 
      
      int low = 0 , high = *max_element(bloomDay.begin() , bloomDay.end()) ; 
      int res = -1 ;
      
      while(low <= high){
          int mid = (low+high)/2 ; 
          
          if(inspect(M , K , bloomDay , mid)){
              res = mid ; 
              high = mid - 1 ;
          }
          else{
              low = mid + 1 ; 
          }
      }
      return res ; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends