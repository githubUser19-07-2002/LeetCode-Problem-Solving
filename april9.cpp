//Problem Link
https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/?envType=daily-question&envId=2025-04-09

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<int> visited(105,0);
        for(int i=0;i<n;i++){
            if(nums[i] < k){
                return -1;
            }
            if(!visited[nums[i]] && nums[i]!=k){
                visited[nums[i]]=1;
                ans++;
            }

        }
        return ans;
    }
};