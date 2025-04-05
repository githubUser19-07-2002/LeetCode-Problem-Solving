//Problem Link
https://leetcode.com/problems/solving-questions-with-brainpower/description/

//Thought process
// Standard DP

//Final answer
// Standard DP


class Solution {
public:
    long long rep(int i,vector<long long int>& dp,int n,vector<vector<int>>& questions){
        if(i>=n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        long long op1 = questions[i][0] + rep(i+questions[i][1]+1,dp,n,questions);
        long long op2 = rep(i+1,dp,n,questions);
        return dp[i] = max(op1,op2);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long int> dp(n+2,-1);
        return rep(0,dp,n,questions);
        }
};