//Problem Link
https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/?envType=daily-question&envId=2025-04-04

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<(1<<n);i++){
            int xor_value = 0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    xor_value = nums[j]^xor_value;
                }
            }
           ans += xor_value;
        }
        return ans;
    }
};