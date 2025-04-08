
//Problem Link
https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/?envType=daily-question&envId=2025-04-08

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> visited(105,0);
        int count = 0;
        for(int i = n-1;i>=0;i--){
            if(visited[nums[i]]){
                count = i+1;
                break;
            }
            visited[nums[i]] = 1;
        }
        return (count%3 == 0)? count/3 : 1+count/3;
    }
};