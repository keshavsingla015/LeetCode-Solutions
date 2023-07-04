//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    // void bfs(int sta)
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q ; 
        int start = 0 ; 
        vector<int> visited(V , 0);
        
        vector<int> ans ; 
        // ans.push_back(start);
        q.push(start);
        visited[start] = 1 ; 
        
        while(!q.empty()){
            int front = q.front(); 
            ans.push_back(front);
            
            for(auto it : adj[front]){
                if(!visited[it]){
                    visited[it] = 1 ; 
                    q.push(it);
                }
            }
            q.pop() ;
        }
        return ans ; 
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends