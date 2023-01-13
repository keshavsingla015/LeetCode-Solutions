
Medium
14.6K
601
Companies
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109


/////////////////////////////////////////////////////////////////////////


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int count = 0 ; 
        vector<int> ans; 

        for(int i = 0 ; i < nums.size() ; i++){

            if(ans.size() == 0){
                ans.push_back(nums[i]);
                if(count < ans.size()){
                    count = ans.size();
                }
            }

            else{
                if(nums[i] == nums[i-1]+1){
                    ans.push_back(nums[i]);
                    if(count < ans.size()){
                        count = ans.size();
                    }
                }
                else if(nums[i] == nums[i-1]){
                    continue ;
                }
                else{
                    ans.clear() ; 
                    i--;
                }
            }
        }
        return count ; 
    }
};
