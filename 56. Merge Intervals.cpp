Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of 
the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

////////////////////////////////////////

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans ; 
        vector<int>::iterator it;
        

        for(int i = 0 ; i < intervals.size() ; i++){
            int lowerBound = (intervals[i])[0];
            int upperBound = (intervals[i])[1];

            for(int j = i ; j < intervals.size() ; j++){
                int mergeLower = (intervals[j])[0];
                int mergeUpper = (intervals[j])[1];
                if(mergeLower < upperBound){
                    upperBound = mergeUpper ; 
                }
                it = intervals.begin();
                it = j ; 
                intervals.erase(it);
            }
            ans.push_back([lowerBound , upperBound]);
        }
        return ans; 
    }
};

// or it can be done by creating a set of numbers where the merged element ka index is stored and in the first loop it is skipped using if-else and break 
// and it works . but set use krna nhi aata......
