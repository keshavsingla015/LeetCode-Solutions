class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN ;
        if(nums.size() == 1){
            return nums[0];
        }
        for(int i = 0 ; i < nums.size() ; i++){
            int sum = nums[i];

            if(i == nums.size() - 1){
                if(sum > max)max = sum ; 
            }
            for(int j = i + 1 ; j < nums.size() ; j++){
                if(sum > max ){
                    max = sum ; 
                }
                sum = sum + nums[j];
                if(sum > max ){
                    max = sum ; 
                }
            }
        }
        return max ; 
    }
};
