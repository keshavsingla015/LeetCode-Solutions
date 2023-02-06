
#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int>nse(n);
    stack<int>s;

    for(int i=n-1;i>=0;--i){

        while(!s.empty() && arr[i]<=s.top()){
            s.pop();
        }

        if(i<n){
            if(!s.empty()){ 
                nse[i]=s.top();
            } 

            else{
              nse[i] = -1;
            }
        }

        s.push(arr[i]);
    }
    return nse;
}

// vector<int> nextGreaterElements(vector<int>& nums) {
//     int n=nums.size();
//     vector<int> ans(n, -1);
//     stack<int> st;
//     for(int i=0;i<2*n;i++)
//     {
//         while(!st.empty() && nums[i%n]>nums[st.top()%n])
//         {
//             ans[st.top()%n]=nums[i%n];
//             st.pop();
//         }
//         st.push(i%n);
//     }
//     return ans;
// }
