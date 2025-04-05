//Problem Link
https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/?envType=daily-question&envId=2025-04-03

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long int> prefix(n,0);
        vector<long long int> suffix(n+1,0);

        for(int i=0;i<n;i++){
            prefix[i] = nums[i];
            if(i>0){
                prefix[i] = max(prefix[i-1],prefix[i]);
            }
        }
        for(int i=n-1;i>=0;i--){
            suffix[i] = max(suffix[i+1],(long long int)nums[i]);
        }
        long long ans = 0;

        for(int i=1;i<n;i++){
            ans = max(ans,(prefix[i-1]-nums[i])*suffix[i+1]);
        }

        return ans;
    }
};