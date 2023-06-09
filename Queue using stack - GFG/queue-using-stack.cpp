//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) {
        if(input.size() == 0 && output.size()){
            input.push(x);
        }
        input.push(x);
    }

    int dequeue() {
        if(input.size() == 0) return - 1;
        if(input.size() == 1){
            int x= input.top() ;
            input.pop() ;
            return x ; 
        }
        else{
            while(input.size() != 1){
                int x = input.top() ; 
                output.push(x);
                input.pop() ;
            }
            int res = input.top() ; 
            input.pop() ; 
            while(!output.empty()){
                int x = output.top() ; 
                input.push(x);
                output.pop() ;
            }
            return res ; 
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        }
    cout<<endl;
    }
}

// } Driver Code Ends