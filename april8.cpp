//Problem Link
// https://leetcode.com/problems/partition-equal-subset-sum/description/?envType=daily-question&envId=2025-04-07

class Solution {
public:
    int checkForSubset(vector<int>& nums,int sum,vector<vector<int>>& dp,int n,int i){
        if(i == n){
            if(sum == 0){
                return 1;
            }
            return 0;
        }
        if(sum < 0){
            return false;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        return dp[i][sum] = checkForSubset(nums,sum - nums[i],dp,n,i+1) || checkForSubset(nums,sum,dp,n,i+1);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum&1){
            return false;
        }
        vector<vector<int>> dp(n,vector<int>(30000,-1));
        return checkForSubset(nums,sum/2,dp,n,0);
        
    }
};